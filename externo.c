#include <stdio.h>
#include <stdlib.h>
#define N 100

struct arquivo {
    FILE *f;
    int pos, MAX, *buffer;
};

void merge(char *nome, int numArquivos, int K) {
    char novo[20];
    int i;
    int *buffer = (int*)malloc(K*sizeof(int));
    struct arquivo* arq;
    arq = (struct arquivo*)malloc(numArquivos*sizeof(struct arquivo));
    for(i=0; i<numArquivos; i++) {
        sprintf(novo, "Temp%d.txt", i+1);
        arq[i].f = fopen(novo, "r");
        arq[i].MAX = 0;
        arq[i].pos = 0;
        arq[i].buffer = (int*)malloc(K*sizeof(int));
        preencheBuffer(&arq[i], K); 
    }
    int menor, qtdBuffer = 0;
    while (procuraMenor(arq, numArquivos, K, &menor) == 1) {
        buffer[qtdBuffer] = menor;
        qtdBuffer++;
        if(qtdBuffer == K) {
            salvaArquivo(nome, buffer, K, 1);
            qtdBuffer = 0;
        }
    }
    if(qtdBuffer != 0) 
        salvaArquivo(nome, buffer, qtdBuffer, 1);
    for(i = 0; i < numArquivos; i++) 
        free(arq[i].buffer);
    free(arq);
    free(buffer);
}

//assadsad

int procuraMenor(struct arquivo* arq, int numArquivos, int K, int* menor) {
    int i, idx = -1;
    for(i = 0; i < numArquivos; i++) {
        if(arq[i].pos < arq[i].MAX) {
            if(idx == -1)
                idx = i;
            else{
                if(arq[i].buffer[arq[i].pos] < arq[idx].buffer[arq[idx].pos])
                    idx = i;
            }
        }
    }
    if(idx != -1) {
        *menor = arq[idx].buffer[arq[idx].pos];
        arq[idx].pos++;
        //cheguei na ultima pos do buffer
        if(arq[idx].pos == arq[idx].MAX)
            preencheBuffer(&arq[idx], K);
        return 1;
    }
    return 0;
}

void preencheBuffer(struct arquivo* arq, int K) {
    int i;
    if(arq->f == NULL)
        return;
    arq->f = 0;
    arq->MAX = 0;
    for(i = 0; i < K; i++) {
        if(!feof(arq->f)) {
            fscanf(arq->f, "%d", &arq->buffer[arq->MAX]);
            arq->MAX++;
        }else{
            fclose(arq->f);
            arq->f = NULL;
            break;
        }
    }
}

void geraArquivo(char *arquivo) {
    FILE *file = fopen(arquivo, "w");
    srand(time(NULL));
    for(int i = 0; i < 1000; i++) 
        fprintf(file, "%d\n", rand() % 1000);
    fprintf(file, "%d", rand() % 1000);
    fclose(file);
}

void mergeSortExterno(char *filename) {
    char novo[20];
    int numArquivos = criaArquivosOrdenados(filename);
    int i, K = N / (numArquivos + 1);
    remove(filename);
    merge(filename, numArquivos, K);
}

int criaArquivosOrdenados(char *nome) {
    int vetor[N], cont = 0, total = 0;
    char novo[20];
    FILE *f = fopen(nome, "r");
    while(!feof(f)) {
        fscanf(f, "%d", &vetor[total]);
        total++;
        if(total == N) {
            cont++;
            sprintf(novo, "Temp%d.txt", cont);
            qsort(vetor, total, sizeof(int), compara);
            // heapSort(vetor,total);
            salvaArquivo(novo, vetor, total, 0);
            total = 0;
        }
    }
    if(total > 0) {
        cont++;
        sprintf(novo, "Temp%d.txt", cont);
        qsort(vetor, total, sizeof(int), compara);
        // heapSort(vetor,total);
        salvaArquivo(novo, vetor, total, 0);
    }
    fclose(f);
    return cont;
}

void salvaArquivo(char *nome, int *vetor, int tam, int mudaLinhaFinal) {
    int i;
    FILE *f = fopen(nome, "a");
    for(int i = 0; i < tam-1; i++) 
        fprintf(f, "%d\n", vetor[i]);
    if(mudaLinhaFinal == 0)    
        fprintf(f, "%d", vetor[tam-1]);
    else
        fprintf(f, "%d\n", vetor[tam-1]);
}

int compara(const void *a, const void *b) {
    if(*(int*) a == *(int*) b)
        return 0;
    else
        if(*(int*) a < *(int*) b)
            return -1;
        else
            return 1;
}

int main() {
    geraArquivo("dados.txt");
    mergeSortExterno("dados.txt");
    return 0;
}
