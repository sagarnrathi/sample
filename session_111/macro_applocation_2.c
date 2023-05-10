#define DEFINE_NODE(type) struct node_##type  \
                           { \
                              type data ;\
                              struct node_##type *next ;\
                              struct node_##type * prev ; \
                           } 
                        
int main(void)

{

DEFINE_NODE(int);
DEFINE_NODE(char);
return (0);
}