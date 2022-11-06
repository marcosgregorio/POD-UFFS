#include <stdio.h>
#include <stdlib.h> // srand, rand
#include <time.h> 

void swap(int vet[], int i, int j){
    int aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;
}

int particiona(int vet[], int inicio, int fim){
    int pivo, pivo_indice, i;
    
    pivo = vet[fim];
    pivo_indice = inicio;
    for (i = inicio; i < fim; i++) {
        if (vet[i] < pivo){
            swap(vet, i, pivo_indice);
            pivo_indice++;
        }
    }
    swap(vet, i, fim);
    return pivo_indice;
}

int particiona_random(int vet[], int inicio, int fim){
    int pivo = (rand() % (fim - inicio + 1) + inicio);
    swap(vet, pivo, fim);
    return particiona(vet, inicio, fim);
}

void quick_sort(int vet[], int inicio, int fim){
    if (inicio < fim){
       int pivo_index = particiona_random(vet, inicio, fim);
       quick_sort(vet, inicio, (pivo_index - 1)); 
       quick_sort(vet, (pivo_index - 1), fim); 
    }
}

int main(){
    int arr[6] = {4, 5, 6, 7, 1, 2};
    printf("oi");
    for (int i = 0; i < 6; i++){
        printf("%d ", arr[i]);
    }
    // srand(time(NULL));
    int len =sizeof(arr)/ sizeof(arr[0]);
    quick_sort(arr, 0, (len - 1));
    for(int i = 0; i < len; i++)
		printf("%d ", arr[i]);
    return 0;
}