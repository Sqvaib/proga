#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    float arr[20];
    float pos_arr[20];
    int pos_count = 0;
    srand(time(NULL));
    for (int i = 0; i < 20; i++) {
        arr[i] = (float)(rand() % 21 - 10);
    }
    printf("Массив:\n");
    for (int i = 0; i < 20; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < 20; i++) {
        if (arr[i] > 0) {
            pos_arr[pos_count] = arr[i];
            pos_count++;
        }
    }
    printf("Массив положительных элементов:\n");
    for (int i = 0; i < pos_count; i++) {
        printf("%.2f ", pos_arr[i]);
    }
    printf("\n");
    return 0;
}