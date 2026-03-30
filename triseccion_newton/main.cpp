#include <stdio.h>
#include <math.h>

float triseccion(float a, float b, float eps);
float newton(float epsilon, float x0);
float f(float x);
int sgn(float num);
float f_prima(float x);

int main() {
    float a = -200;
    float b = 150;
    float epsilon = 50;
    float x0 = triseccion(a, b, epsilon);
    epsilon = 0.01;
    float raiz = newton(epsilon, x0);
    printf("%.2f", raiz);
    return 0;
}

float triseccion(float a, float b, float epsilon) {
    float c1, c2;
    do {
        // Divido el intervalo b-a en 3 partes, c1=1/3 y c2=2/3 del intervalo
        c1 = a+(b-a)/3;
        c2 = a+2*(b-a)/3;
        if(f(c1)==0){ // En caso de que c1 o c2 coincidan con una raiz, las retorno y termina la busqueda
            printf("La raiz se hallo con el metodo de triseccion \n");
            return c1;
        } else if(f(c2)==0){
            printf("La raiz se hallo con el metodo de triseccion \n");
            return c2;
        /*
            En caso de que no se halle una raiz de esta manera (lo mas probable), procedo a acotar el intervalo utilizando el
            corolario del Teorema de Bolzano. Es decir, que solo voy a continuar utilizando aquel intervalo que contenga extremos
            con distintos signos al evaluarlos en la funcion f(x)
        */
        } else if(sgn(f(a)) * sgn(f(c1)) < 0) b=c1; // Primer intervalo
        else if(sgn(f(c1)) * sgn(f(c2)) < 0){ // Segundo intervalo
            a=c1;
            b=c2;
        } else a=c2; // Tercer intervalo
        /*
            Continuo acotando hasta que el intervalo sea mas pequeño que el epsilon, esa seria mi condicion parada. La idea es aproximar un conjunto
            en el cual pueda asegurar que existe una raiz.
        */
    } while(fabs(b-a) >= epsilon);
    // Una vez que encontre el intervalo que seguro contiene una raiz, retorno el punto medio.
    return (a+b)/2;
}

float newton(float epsilon, float x0){
    float xn = x0;
    float xa;
    do {
        /*
           En la variable xa voy a guardar el valor actual de xn, el cual se va a actualizar, entonces xa seria el punto anterior
           al obtenido con la tangente, y ya luego puedo medir la distancia entre un punto y otro para saber si me aproxime a una raiz
        */
        xa = xn;
        /*
            Es muy importante verificar que la funcion sea derivable en el punto xn. Si no lo es, la evaluacion en la derivada devolveria
            cero, y luego no se podria calcular el punto siguiente porque se estaria dividiendo por cero.
        */
        if (f_prima(xa) == 0) {
            printf("No se puede continuar porque la derivada es nula \n"); // Interrumpo el metodo
            break;
        }
        xn = xa - f(xa)/f_prima(xa); // Calculo el punto en el que desemboca la tangente
        // El proceso se repite hasta que la distancia entre el punto anterior y el de la tangente sea menor a epsilon
    } while(fabs(xn-xa) >= epsilon);
    return xn;
}

float f(float x){
    return 0.001*pow(x,3) - 4*x;
}

float f_prima(float x){
    return 0.003*pow(x,2) - 4;
}

int sgn(float num) {
    if(num<0) return -1;
    else if(num==0) return 0;
    else return 1;
}
