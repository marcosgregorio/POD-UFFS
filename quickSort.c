#include <stdio.h>

void swap(int arr[], int i, int j) {
    int aux = arr[j];
    arr[j] = arr[i];
    arr[i] = aux;
    return;
}

int particiona(int array[], int inicio, int fim) {
    int posPivo, k, aux;
    posPivo = fim;
    k = inicio;
    for(int i = inicio; i < fim; i++){
        if(array[i] <= array[posPivo]){
            // swap
            aux = array[k];
            array[k] = array[i];
            array[i] = aux;
            k++;
        }
    }
    if(array[k] > array[posPivo]){
        //swap
        aux = array[posPivo];
        array[posPivo] = array[k];
        array[k] = aux;
        posPivo = k;
    }
    return posPivo;
}

void quickSort(int array[], int inicio, int fim) {
    int posPivo;
    if(inicio < fim){
        posPivo = particiona(array, inicio, fim);
        quickSort(array, inicio, posPivo-1);
        quickSort(array, posPivo+1, fim);
    }
}

int main() {
    int array[10] = {6, 5, 3, 1, 12, 10, 9, 5, 2, 11};
    int len = sizeof(array)/ sizeof(array[0]);
    printf("Lista desordenada: ");
    for (int i = 0; i < len; i++)
        printf("%d, ", array[i]);
    quickSort(array, 0, (len - 1));

    printf("\nLista ordenada: ");
    for (int i = 0; i < len; i++)
        printf("%d, ", array[i]);
    
    return 0;
}
