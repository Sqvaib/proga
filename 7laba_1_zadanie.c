#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float funkc(float a, float b, float c, float x) {
        return a * (x * x) * sin(x) + b * x + c;
}
int main(int argc, char** argv) {
    float a, b, c, start, end, h;
    printf("Коэффицент а: \n");
    scanf("%f", &a);
    printf("Коэффицент b:\n");
    scanf("%f", &b);
    printf("Коэффицент c:\n");
    scanf("%f", &c);
    printf("Начало:\n");
    scanf("%f", &start);
    printf("Конец:\n");
    scanf("%f", &end);
    printf("Шаг:\n");
    scanf("%f", &h);
    if (((start > end) && (h > 0)) || ((start < end) && (h < 0))) {
        float m = start;
        start = end;
        end = m;
    }
    int len = abs((end - start) / h) + 1;
    float mas[len];
    int i = 0;
    while (start != end) {
        mas[i] = funkc(a, b, c, start);
        start += h;
        i++;
    }
    for (i = 0; i < len - 1; i++) {
        for (int j = len - 2; j >= i; j--){
          if (mas[j] > mas[j+1]) {
            float l = mas[j];
            mas[j] = mas[j+1];
            mas[j+1] = l;
          }  
        } 
    }     
        for (i = 0; i < len; i++) {
            printf("%f\n", mas[i]);
        }
    return 0;
}