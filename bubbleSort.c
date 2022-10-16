#include <stdio.h>

void bubbleSort(int vetor[],int n){
    int aux;
    for (int i = 0; i < n; i++){
        // printf("%d ",i);
        for (int j = 0; j < (n-1); j++){
            // printf("%d",j);
            if(vetor[j]>vetor[j+1]){
                aux=vetor[j];
                vetor[j]=vetor[j+1];
                vetor[j+1]=aux;
            }
        }
        printf("%d ",vetor[i]);
    }
    printf("\n");

}

void selectionSort(int vet[],int n){
    int aux;
    for (int i = 0; i < n; i++){
        int smaller = i;
        for (int j = i+1; j < n-1; j++){
            if(vet[j]<vet[i])
                smaller = j;
        }
        aux = vet[smaller];
        vet[smaller] = vet[i];
        vet[i] = aux;
        printf("%d ",vet[i]);
    }
    printf("\n");

}

int main(){
    int vetor[6]= {10,3,6,4,7,9};
    printf("\n");
    printf("Vetor:");
    for (int i = 0; i < 6; i++){
        printf("%d ",vetor[i]);
    }
    // printf("\n");
    // printf("bubble sort\n");
    bubbleSort(vetor,6);
    printf("\n");
    printf("Selection sort\n");
    selectionSort(vetor,6);
    return 0;
}