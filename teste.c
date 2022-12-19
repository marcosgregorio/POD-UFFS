#include <stdio.h>

int compara(const void *a, const void *b) {
    if(*(int*) a == *(int*) b)
        return 0;
    else
        if(*(int*) a < *(int*) b)
            return -1;
        else
            return 1;
}

int main(int argc, char const *argv[]) {
    int array[] = { 1 ,23 ,6, 7 ,8 ,-22 };
    for (int i = 0; i < 6; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    qsort(array, 6, sizeof(int), compara);
    for (int i = 0; i < 6; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
