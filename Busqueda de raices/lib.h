#include <stdio.h>
#include <math.h>

float potencia(float x);
float biseccion(float a, float b, float epsilon);
float triseccion(float a, float b, float epsilon);
float biseccion_contador(float a, float b, float epsilon);
float coseno(int n, float x);
float f(float x);
float g(float x);
float fg(float x, int n);
int sgn(float num);
float biseccion_no_raiz(float a, float b, float epsilon);
float biseccion_modificada(float a, float b, float epsilon);
void mostrar_secuencia(float *p, int max);

// Funcion F(X) para biseccion
float F(float x) {
    return x-10;
}

/*
    Biseccion clasica
    Condicion de salida -> error absoluto (distancia entre a y b menor a epsilon)
*/
float biseccion(float a, float b, float epsilon) {
    float c;
    while(b-a >= epsilon) {
        c = (a+b)/2;
        if(F(c)==0)return c;
        if((sgn(F(a))*sgn(F(c))) < 0) b=c;
        else a=c;
    }
    return c;
}

/*
    Triseccion clasica
    Condicion de salida -> error absoluto (distancia entre a y b menor a epsilon)
*/
float triseccion(float a, float b, float eps) {
    float c1, c2;
    while(b-a > eps){
        c1 = a + (b-a)/3;
        c2 = a + 2*(b-a)/3;
        if(F(c1)==0) return c1;
        else if (F(c2)==0) return c2;
        if(sgn(F(a))*sgn(F(c1))<0) b=c1;
        else if(sgn(F(c1))*sgn(F(c2))<0) {
            a=c1;
            b=c2;
        } else a=c2;
    }
    return (a+b)/2;
}

/*
    Biseccion clasica pero que ademas cuenta la cantidad de pasos realizados(n)
*/
float biseccion_contador(float a, float b, float epsilon) {
    float c;
    int contador = 0;
    while(b-a >= epsilon) {
            contador++;
        c = (a+b)/2;
        if(F(c)==0)return c;
        if((sgn(F(a))*sgn(F(c))) < 0) b=c;
        else a=c;
    }
    printf("El numero de pasos necesitados para aproximar la raiz fue %d \n", contador);
    return c;
}

/*
    Aplica el coseno de x n veces
    Ver de hacer funcion recursiva
*/
float coseno(int n, float x) {
    float resultado = x;
    int i=0;
    while(i<n){
        resultado = cos(resultado);
        i++;
    }
    return resultado;
}

/*
float f(float x) {
    return cos(x);
}

float g(float x) {
    return sin(x);
}

// Funcion que a un valor X le aplica f(x) y luego g(x)
float fg(float x, int n) {
    float resultado = x;
    int i=n;
    while(i>0) {
        resultado = f(resultado);
        resultado = g(resultado);
        i--;
    }
    return resultado;
}
*/

// Biseccion que toma como raiz a un valor distinto de Y distinto de 0
float biseccion_no_raiz(float a, float b, float epsilon) {
    float c, valor_buscado=-1;
    while(b-a >= epsilon) {
        c = (a+b)/2;
        if(F(c)==valor_buscado)return c;
        if(sgn(F(a)+1)*sgn(F(c)+1) < 0) b=c;
        else a=c;
    }
    return c;
}

// Devuelve un entero que representa el signo del numero
int sgn(float num) {
    if(num<0) return -1;
    else if(num==0) return 0;
    else return 1;
}

float biseccion_modificada(float a, float b, float epsilon) {
    float c;
    float secuencia[20];
    int i=0;
    do {
        c = (a+b)/2;
        secuencia[i] = c;
        if((sgn(F(a))*sgn(F(c))) < 0) b=c;
        else a=c;
        i++;
    } while(b-a >= epsilon);
    mostrar_secuencia(secuencia, i);
}


void mostrar_secuencia(float *p, int max) {
    for(int i=0; i<max; i++) {
        printf("%f \n", *(p+i));
    }
}


