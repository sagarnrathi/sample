#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>

void miniprintf(const char *fmt,...);

int main(void)
{
    int n = 100;
    float fnum = 3.14;
    unsigned int un = 100;

    miniprintf("n - %d, fnum  = %f,un = %u, percent = %%  sagar\n",n,fnum,un);

    return(0);
}

void miniprintf(const char *fmt,...)
{
    va_list ap;
    unsigned int i;
    int int_arg;
    double float_arg;
    unsigned int uint_arg;

    va_start(ap,fmt);
    for(i=0;i<strlen(fmt);i++)
    {
        if(fmt[i]!='%')
        {
         putchar(fmt[i]);
         continue ;
         }

         switch(fmt[++i])
         {
            case 'd' : 
                 int_arg = va_arg(ap,int);
                 printf("%d",int_arg);
                 break;
            
            case 'f' :
                 float_arg = va_arg(ap,double);
                 printf("%f",float_arg);
                 break;
            case 'u' :
                 uint_arg = va_arg(ap,unsigned int);
                 printf("%u",uint_arg);
                 break;
            case '%' :
                 putchar('%');
                break;
            default :
                 putchar(fmt[i]);
                 break;

         }

   }
   va_end(ap);
}