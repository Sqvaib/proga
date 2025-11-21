#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int N = 10; // 10 100 1000 

int main() {
    double a, b, h, A[N], I1, I2, s1 = 0, s2 = 0, Cm = 0;
    a = 2; b = 10;
    h = (b - a) / N;
    I1 = 0;
    I2 = 0;
    for (int i = 0; a < b; i++) {
        A[i] = pow(a + 1, 2) * sqrt(log10(a));
        a += h;
        Cm++;
    }
    for (int i = 0; i < Cm; i++) {
        if (i != 0 && i != Cm - 1)
            I1 += A[i];
        else 
            I1 += A[i] / 2;
    }
    I1 *= h;
    printf("I1 By the trapezoidal formula: %lf\n", I1);
    for (int i = 0; i < Cm; i++) {
        if (i == 0 && i == Cm - 1)
            I2 += A[i];
        else if (!(i % 2))
            s1 += A[i];
        else 
            s2 += A[i];
    }
    s1 *= 2;
    s2 *= 4;
    I2 = I2 + s1 + s2;
    I2 *= h / 3;
    printf("I2 By Simpson's formula: %lf\n", I2);
    return 0;
}