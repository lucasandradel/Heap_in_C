#include <stdio.h>
#include <stdio.h>


#include "heap.c"

int main(int argc, char *argv[]){
    tipo_heap heap;
    InicializaHeap (&heap);

    InsereHeap(&heap, 10);
    InsereHeap(&heap, 5);
    InsereHeap(&heap, 15);
    InsereHeap(&heap, 1);
    InsereHeap(&heap, 80);
    InsereHeap(&heap, 85);
    InsereHeap(&heap, 17);
    InsereHeap(&heap, 8);
    InsereHeap(&heap, 9);

    ImprimeHeap(&heap);
    
    //printf ("Removido: %d\n ", RemoveRaizHeap(&heap));
   // ImprimeHeap(&heap);

    removeValorHeap(&heap, 2);
    printf ("posição 2 Removida\n ");
    ImprimeHeap(&heap);


    return 1;
}