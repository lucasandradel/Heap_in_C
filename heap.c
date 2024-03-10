#ifndef HEAP_C
#define HEAP_C

#include <stdlib.h>
#include <stdio.h>

#define N 10

struct est_heap
{
    int heap [N];
    int contador;
};
typedef struct est_heap tipo_heap;

//prototipação
void InicializaHeap(tipo_heap*);
void InsereHeap(tipo_heap*, int);
int PosPai(int);
int PosFilhoEsquerda(int);
int PosFilhoDireita(int);
void SobeValor (tipo_heap *, int);
int RemoveRaizHeap(tipo_heap *);
int removeValorHeap(tipo_heap *, int );

void ImprimeHeap(tipo_heap* );
void desceValor(tipo_heap*, int);

//Implementações das funções
void InicializaHeap(tipo_heap * hp){
    hp -> contador = 0;  
}

void InsereHeap(tipo_heap* hp, int valor){
    if (hp -> contador < N){
        hp -> heap [hp -> contador++] = valor;
        SobeValor(hp, hp -> contador -1);
    }

}

int PosPai(int i){
    return  (int) (i-1)/2;
}

int PosFilhoEsquerda(int i){
    return  i*2+1;
}

int PosFilhoDireita(int i){
    return  i*2+2;

}

void SobeValor (tipo_heap *hp, int pos){
    int aux;
    if (hp -> heap[pos] > hp -> heap [PosPai(pos)]){
        aux = hp -> heap[pos];
        hp -> heap [pos] = hp -> heap [PosPai(pos)];
        hp -> heap[PosPai(pos)] = aux;

        //chamada recursiva
        if (PosPai(pos) != 0){
            SobeValor(hp, PosPai(pos));
        }

    }
}

//função que desce com o valor até a posição adequada
void desceValor(tipo_heap *hp, int pos){
    int novaPos, aux ;

    if ((PosFilhoEsquerda(pos) < hp -> contador) || (PosFilhoDireita(pos) < hp -> contador)){
        //Verifica o caso do indice possuir os dois filhos
        if ( PosFilhoDireita(pos) < hp -> contador){
            //identifica qual filho tem maior valor, para que ele suba (se for o caso)
            if (hp -> heap [PosFilhoEsquerda(pos)] > hp -> heap [PosFilhoDireita(pos)]){
                novaPos = PosFilhoEsquerda(pos);//maior valor é o esquerdo
            }else{
                novaPos = PosFilhoDireita(pos);//maior valor é o direito
            }

        }else{
            novaPos = PosFilhoEsquerda(pos);//para o caso de possuir apenas o filho esquerdo 
        }

        //verifica se há necessidade de troca 

        if (hp -> heap[pos]< hp -> heap [novaPos]){

            //executa a troca de valores
            aux = hp -> heap [pos];
            hp -> heap [pos] = hp -> heap [novaPos];
            hp -> heap [novaPos] = aux;
            desceValor ( hp, novaPos);
        }

    }
}

//remove elemento de maior prioridade 
int RemoveRaizHeap(tipo_heap *hp){
    int valor;
    if (hp -> contador > 0){//verifcia se tenho pelo menos um elemento
        valor = hp -> heap [0];//pego o elemento que está na raiz e guardo em valor para devolver no final da opreação da função
        hp -> heap [0] = hp -> heap [--hp-> contador];//guardo na raiz o ultimo elemento do heap
        desceValor(hp, 0);//chamada da função desce valor passando o heap o o indice da posição que ele comece a descer 
    }else{
        return -1;   
    }
    return valor;
}

//remove um valo especifico do heap
int removeValorHeap(tipo_heap *hp, int valor) {
    int i;

    if (hp -> contador > 0){
        //busca valor no vetor do heap
        i = 0;
        while ((i < hp -> contador ) && (hp -> heap [i] != valor)){
            i ++;
        }

        //verfica se o valor foi encontrado

        if (i < hp -> contador){
            hp -> heap[i] = hp -> heap [--hp -> contador]; //move o último valor do heap para o indice do valor encontrado
            
            //verifica a possibilidade do valor estar em uma folha em outro ramo
            if ((i != 0) && (hp -> heap [PosPai(i)] < hp -> heap [i]) ){
                SobeValor(hp, i);
            }else{
                desceValor(hp, i);
            }

        }else{
            i = -1;
            
        }
        
    }else{
        return -1;
    }
    
    return i;

}

void ImprimeHeap(tipo_heap *hp ){
    int i;
    printf("Heap MAX: [");  
    for (i = 0; i< hp->contador; i++){
        printf (" %d ", hp-> heap[i]);
    }
    printf("]\n");
}




#endif