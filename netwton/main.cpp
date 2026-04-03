#include <stdio.h>
#include <math.h>

float f_prima(float x);
float f(float x);
float newton(float epsilon, float x0);

int main() {
    float x0=-2;
    float raiz = newton(0.000001, x0);
    printf("Raiz=%.2f \n", raiz);
    return 0;
}

float newton(float epsilon, float x0){
    float xn = x0;
    float xa;
    do {
        xa = xn;
        if (f_prima(xa) == 0) {
            printf("No se puede continuar porque la derivada es nula \n");
            break;
        }
        xn = xa - f(xa)/f_prima(xa);
        printf("%f \n", xn);
    } while(fabs(xn-xa) >= epsilon);
    return xn;
}

float f(float x) {
    return exp(-x) - sin(x);
}

float f_prima(float x){
    return -cos(x) -1*exp(-x);
}
