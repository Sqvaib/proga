#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int arr[15];
    srand(time(NULL));
    for (int i = 0; i < 15; i++) {
        arr[i] = rand() % 11;
    }
    printf("Массив:\n");
    for (int i = 0; i < 15; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Элементы массива, исключая ранее встречавшиеся:\n");
    for (int i = 0; i < 15; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                break;
            }
        }
        if (i == j) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
    return 0;
}