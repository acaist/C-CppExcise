#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
int main()
{
  //assert(0);
  printf("assert true \n");
 

    int* ptr = (int*) malloc(5*sizeof(int));
    if(!ptr)
        exit(1);
        
    ptr[1] = 2;
    ptr[4] = 5;

    int* ptr_new = (int*)realloc(ptr, 0*sizeof(int));
    printf("new ptr address %x \n", ptr_new);
    if(!ptr_new){
        free(ptr);
        exit(1);
    }
   
   
    ptr = ptr_new;
   
    ptr[6]=7;

    for(int i=0; i<10;++i)
    {
        printf(" %d ", ptr[i]);
    }

    free(ptr);
    return 0;
}
