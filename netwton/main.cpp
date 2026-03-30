#include <stdio.h>
#include <math.h>

float f_prima(float x);
float f(float x);
float newton(float epsilon, float x0);

int main() {
    float raiz = newton(0.5, -8);
    printf("%.2f", raiz);
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
    } while(fabs(xn-xa) >= epsilon);
    return xn;
}

float f(float x) {
    return pow(x,2)+6*x-2;
}

float f_prima(float x){
    return 2*x+6;
}
