#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float funkc(float a, float b, float c, float x) {
        return a * (x * x) * sin(x) + b * x + c;
}
int main(int argc, char** argv) {
    float a=2.14, b=-4.21, c=3.25, start_x=-4.5, end_x=-33.5, h=0.5;
    if (((start_x > end_x) && (h > 0)) || ((start_x < end_x) && (h < 0))) {
        float m = start_x;
        start_x = end_x;
        end_x = m;
    }
    int len = abs((end_x - start_x) / h) + 1;
    float mass[len];
    int i = 0;
    while (start_x != end_x) {
        mass[i] = funkc(a, b, c, start_x);
        start_x += h;
        i++;
    }
    for (i = 0; i < len - 1; i++) {
        for (int j = len - 2; j >= i; j--){
          if (mass[j] > mass[j+1]) {
            float l = mass[j];
            mass[j] = mass[j+1];
            mass[j+1] = l;
          }  
        } 
    }     
        for (i = 0; i < len; i++) {
            printf("%f\n", mass[i]);
        }
    return 0;
}