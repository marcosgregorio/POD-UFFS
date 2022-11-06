#include <stdio.h>

void criaHeap(int array[], int i, int n) {
    int maior, left, right, aux;

    maior = i;
    left = 2*i+1;
    right = 2*i+2;
    if(left < n && array[left] > array[i])
        maior = left;
    if(right < n && array[right] > array[maior])
        maior = right;
    if(maior != i){
        aux = array[i]; 
        array[i] = array[maior];
        array[maior] = aux;
        criaHeap(array, maior, n);
    }
}

void heapSort(int array[], int n) {
    int aux;

    for(int k = n/2-1;k >= 0; k--)
        criaHeap(array, k, n);
    for(int k = n-1; k > 0; k--){
        aux = array[0];
        array[0] = array[k];
        array[k] = aux;
        criaHeap(array, 0, k);
    }
    
}

int main() {
    int array[] = {50, 3, 6, 7, 2, 11, 30, 4, -100};
    int n = sizeof(array)/sizeof(array[0]);
    printf("Lista desordenada: ");
    for (int i = 0; i < n; i++) {
        printf("%d, ", array[i]);
    }
    heapSort(array, n);
    printf("\n ");
    printf("Lista ordenada: ");
    for (int i = 0; i < n; i++) {
        printf("%d, ", array[i]);
    }
    return 0;
}
