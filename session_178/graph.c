#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define SUCCESS 1 
#define G_INVALID_VERTEX 2
#define G_INVALID_EDGE 3
#define G_VERTEX_EXISTS 4
#define G_EDGE_EXISTS 5

typedef struct hnode hnode_t;
typedef struct vnode vnode_t ;
typedef hnode_t hlist_t;
typedef vnode_t vlist_t ;
typedef struct edge edge_t ;
typedef struct graph graph_t;
typedef int vertex_t;
typedef int status_t;

struct hnode {
    vertex_t v ;
    struct hnode *prev;
    struct hnode *next;
};

struct vnode{
    vertex_t v;
    hlist_t *ph_list;
    struct vnode *prev;
    struct vnode *next;
};

struct edge{
    vertex_t v_start;
    vertex_t v_end;
};

struct graph{
    vlist_t * pv_list;
    int nr_vertices;
    int nr_edges;
};

//graph interfaces 

graph_t * create_graph(void);
status_t add_vertex(graph_t *g,vertex_t v );
status_t remove_vertex(graph_t *g,vertex_t v);
status_t add_edge(graph_t * g,vertex_t v_start,vertex_t v_end);
status_t remove_edge(graph_t *g,vertex_t v_start,vertex_t v_end);
void show_graph(graph_t *g,const char *msg);
status_t destroy_graph(graph_t **pp_g);

//vertical interface 
vlist_t* v_create_list(void);
status_t v_insert_end(vlist_t *pv_list,vertex_t v);

//helper vertical routine 
void v_generic_insert(vnode_t * pv_start,vnode_t * pv_mid,vnode_t * pv_end);
void v_generic_delete(vnode_t *pv_node);
vnode_t * v_search_node(vlist_t * pv_list,vertex_t v);
vnode_t * v_get_node(vertex_t v);

//horizontal interface 
hlist_t *h_create_list(void);
status_t h_insert_end(hlist_t *ph_list,vertex_t v);

//horizontal helper 
void h_generic_insert(hnode_t *ph_start, hnode_t *ph_mid,hnode_t *ph_end);
void h_generic_delete(hnode_t *ph_node);
hnode_t *h_search_node(hlist_t * ph_list,vertex_t v);
hnode_t *h_get_node(vertex_t v);

void * xcalloc(size_t nr_element,size_t size_per_element);

int main(void)
{
    graph_t *g = NULL ;
    status_t status;
    int i;
    vertex_t v[] = {1,2,3,4,5};
    edge_t E[] = {
      {1,2},{1,5},{1,4},
      {2,3},{3,4},{3,5},
      {4,5}
    };

    g = create_graph();
    for(i = 0;i < sizeof(v)/sizeof(v[0]);++i){
        status = add_vertex(g,v[i]);
        assert(status == SUCCESS );
    } 
    for(i = 0;i<sizeof(E)/sizeof(E[0]);++i)
    {
        status = add_edge(g,E[i].v_start,E[i].v_end);
        assert(status == SUCCESS);
    }

    show_graph(g,"INITIAL STATE");
    status  = add_vertex(g,6);
    assert(status == SUCCESS);
    status = add_edge(g,1,6);
    assert(status == SUCCESS);
    status = add_edge(g,2,6);
    assert(status == SUCCESS);
    status = add_edge(g,5,6);
    assert(status == SUCCESS);

    show_graph(g,"after adding vertex 6 and edege 1,6 egde edeg 2,6 and edge 5,6");

    status = remove_edge(g,2,3);
    assert(status == SUCCESS);

    status = remove_edge(g,4,5);
    assert(status == SUCCESS);

    show_graph(g,"after removing edge 2,3 and edge 4,5");
    status = remove_vertex(g,1);
    assert(status == SUCCESS);

    show_graph(g,"after removing vertex 1");

    status = destroy_graph(&g);
    assert(status == SUCCESS && g == NULL);
    puts("graph destroyrd successfully");

    return(EXIT_SUCCESS);
}

graph_t *create_graph(void)
{
    graph_t *g = NULL ;

    g = (graph_t *) xcalloc(1,sizeof(graph_t));
    g->pv_list = v_create_list();
    g -> nr_edges = 0 ;
    g -> nr_vertices = 0 ;
    
    return(g);
}


status_t add_vertex(graph_t *g,vertex_t v){
    vnode_t *pv_node = NULL ;

    pv_node = v_search_node(g ->pv_list,v);
    if(pv_node != NULL)
         return(G_VERTEX_EXISTS);
    
    v_insert_end(g -> pv_list,v);
    g -> nr_vertices++;
    return(SUCCESS);
}

status_t remove_vertex(graph_t *g,vertex_t v){
             vnode_t *pv_remove_node = NULL ;
             vnode_t *pv_adj_node  = NULL ;
             hnode_t *ph_remove_vertex_in_adj = NULL ;
             hnode_t *ph_run  = NULL ;
             hnode_t * ph_run_next = NULL ;

             pv_remove_node = v_search_node(g -> pv_list,v);
             if(pv_remove_node == NULL)
                     return (G_INVALID_VERTEX);
            
            for(ph_run = pv_remove_node -> ph_list -> next;
                ph_run != pv_remove_node -> ph_list;
                ph_run = ph_run_next )
                {
                    ph_run_next = ph_run -> next;
                    pv_adj_node = v_search_node(g -> pv_list,ph_run -> v);
                    ph_remove_vertex_in_adj = h_search_node(pv_adj_node->ph_list,v);
					h_generic_delete(ph_remove_vertex_in_adj); 
                    h_generic_delete(ph_run);
                    g->nr_edges--;

                }

            free(pv_remove_node -> ph_list);
            v_generic_delete(pv_remove_node);
            g -> nr_vertices--;
            return(SUCCESS);
}

status_t add_edge(graph_t *g,vertex_t v_start,vertex_t v_end)
{
    vnode_t *pv_start = NULL ;
    vnode_t *pv_end   = NULL ;
    hnode_t *ph_end_in_start = NULL ;
    status_t status ;

    pv_start = v_search_node(g -> pv_list,v_start);
    
    if(pv_start == NULL)
          return G_INVALID_VERTEX;
    
    pv_end = v_search_node(g -> pv_list,v_end);
    
    if(pv_end == NULL)
          return G_INVALID_VERTEX;
    
    ph_end_in_start = h_search_node(pv_start -> ph_list,v_start );
    if(ph_end_in_start != NULL)
        return(G_EDGE_EXISTS);
    
    status = h_insert_end(pv_start ->ph_list,v_end);
    assert(status == SUCCESS);

    status = h_insert_end(pv_end -> ph_list,v_start);
    assert(status == SUCCESS);
     g->nr_edges++ ;
     return(SUCCESS);

}

status_t remove_edge(graph_t *g,vertex_t v_start,vertex_t v_end)
{
    vnode_t *pv_start = NULL ;
    vnode_t *pv_end = NULL ;
    hnode_t *ph_start_in_end = NULL ;
    hnode_t *ph_end_in_start = NULL ;

    pv_start = v_search_node(g -> pv_list,v_start);
    if(pv_start == NULL)
        return (G_INVALID_VERTEX);
    
    pv_end = v_search_node(g->pv_list ,v_end);
    if(pv_end == NULL)
        return (G_INVALID_VERTEX);
    
    ph_end_in_start = h_search_node(pv_start->ph_list,v_end) ;
    if(ph_end_in_start == NULL)
    {
        return(G_INVALID_EDGE);
    }

    ph_start_in_end = h_search_node(pv_end ->ph_list,v_start);
    if(ph_start_in_end == NULL)
        return (G_INVALID_EDGE);
    h_generic_delete(ph_start_in_end);
    h_generic_delete(ph_end_in_start);

    g ->nr_edges--;
    return(SUCCESS);
}

void show_graph(graph_t *g,const char *msg)
{
    vnode_t *pv_run = NULL ;
    hnode_t *ph_run = NULL;
    if(msg)
        puts(msg);
    
    printf("graph g :|V| = %d , |E| = %d \n",g->nr_vertices,g->nr_edges);
    for(pv_run = g -> pv_list ->next;pv_run != g->pv_list;pv_run = pv_run ->next){
        printf("[%d]\t <-> \t",pv_run ->v);
        for(ph_run = pv_run->ph_list->next ;ph_run!=pv_run -> ph_list ;ph_run =ph_run -> next)        
            printf("[%d] <-> ",ph_run ->v);
        puts("END");
        
    }
}
status_t destroy_graph(graph_t  ** p_g){
    graph_t *g = NULL ;
    vnode_t *pv_run = NULL ;
    vnode_t *pv_run_next = NULL ;
    hnode_t *ph_run = NULL ;
    hnode_t *ph_run_next = NULL ;

    g = *p_g ;

    for(pv_run = g-> pv_list ->next ;pv_run != g->pv_list;pv_run = pv_run ->next)
    {
        pv_run_next = pv_run -> next ;
        for(ph_run = pv_run ->ph_list->next ; ph_run != pv_run -> ph_list ; ph_run = ph_run_next)
        {
            ph_run_next = ph_run -> next;
            free(ph_run);
        }
        free(pv_run -> ph_list);
    }
    free(g->pv_list);
    free(g);
    *p_g = NULL;
    return(SUCCESS);
}

vlist_t *v_create_list(void){
   vlist_t *pv_list = NULL ;
   pv_list = (vlist_t *)xcalloc(1,sizeof(vlist_t));
   pv_list -> v = -1 ;
   pv_list -> ph_list = NULL;
   pv_list -> next = pv_list;
   pv_list -> prev = pv_list ;

   return(pv_list);
}

status_t v_insert_end(vlist_t *pv_list,vertex_t v){
    v_generic_insert(pv_list->prev ,v_get_node(v),pv_list);
    return(SUCCESS);
}

void v_generic_insert(vnode_t *pv_start,vnode_t *pv_mid,vnode_t *pv_end)
{
    pv_mid -> next = pv_end ;
    pv_mid -> prev = pv_start;
    pv_end -> prev  = pv_mid ;
    pv_start -> next = pv_mid;
}

void v_generic_delete(vnode_t *pv_node)
{
    pv_node -> prev -> next = pv_node -> next ;
    pv_node -> next -> prev = pv_node -> prev ;
    
    free(pv_node);
}

vnode_t *v_search_node(vlist_t *pv_list,vertex_t v){
    vnode_t * pv_run = NULL ;

    for(pv_run = pv_list -> next ;pv_run != pv_list; pv_run = pv_run ->next)
        if(pv_run -> v == v)
            return pv_run ;
        
    return (NULL);
}

vnode_t *v_get_node(vertex_t v){
    vnode_t *pv_node = NULL ;
    pv_node = (vnode_t *)xcalloc(1,sizeof(vnode_t));
    pv_node -> v = v;
    pv_node -> ph_list = h_create_list();

    return(pv_node); 
}

//horizontal interfaces 
hlist_t *h_create_list(void)
{
    hnode_t *ph_list = NULL ;
    ph_list = h_get_node(-1);
    ph_list -> prev = ph_list;
    ph_list -> next = ph_list;

    return(ph_list);
}

status_t h_insert_end(hlist_t *ph_list,vertex_t v){
    h_generic_insert(ph_list -> prev,h_get_node(v),ph_list);
    return(SUCCESS);
}

//horizontal helper 
void h_generic_insert(hnode_t *ph_start,hnode_t *ph_mid,hnode_t *ph_end)
{
    ph_start -> next =  ph_mid ;
    ph_end -> prev = ph_mid ;
    ph_mid -> next = ph_end;
    ph_mid -> prev = ph_start;
}

void h_generic_delete(hnode_t *ph_node)
{
    ph_node -> next ->prev = ph_node -> prev ; 
    ph_node -> prev -> next = ph_node -> next;
    free(ph_node);
}

hnode_t *h_search_node(hlist_t *ph_list,vertex_t v)
{
    hnode_t * ph_run = NULL ;
    for(ph_run = ph_list -> next ; ph_run != ph_list;ph_run = ph_run ->next)
    if(ph_run -> v == v)
         return ph_run ;
    return NULL ;
}

hnode_t *h_get_node(vertex_t v)
{
    hnode_t *ph_new_node  = NULL ;
    ph_new_node = (hnode_t *)xcalloc(1,sizeof(hnode_t));
    ph_new_node -> v = v;
    ph_new_node -> next = NULL;
    ph_new_node -> prev = NULL;

    return(ph_new_node);
}

void *xcalloc(size_t nr_element,size_t size_per_element)
{
    void *p = NULL;
    p = calloc(nr_element,size_per_element);
    if(p == NULL)
    {
        puts("error in allocating the memory") ;
        exit(EXIT_FAILURE);
    }
    return(p);
}