#include <stdio.h>
#include <math.h>

float triseccion(float a, float b, float eps);
float newton(float epsilon, float x0);
float f(float x);
float f_prima(float x);
int sgn(float num);


int main() {
    float a, b, epsilon;
    printf("Aproximacion de intervalo que contiene una raiz con el metodo de triseccion \n");
    printf("Ingrese el valor 'a' del intervalo\n");
    scanf("%f", &a);
    printf("Ingrse el valor 'b' del intervalo\n");
    scanf("%f", &b);
    /*
        Defino un epsilon grande para que el algoritmo solamente aproxime sin acercarse demasiado, para que el metodo
        de Newton haga el resto
    */
    epsilon = 50;
    float x0 = triseccion(a, b, epsilon);
    if(f(x0)==0){ // Verifica si el valor obtenido es una raiz  o no, si lo es, termina la busqueda
        printf("Raiz hallada con el metodo de triseccion. Fin de la busqueda. \n");
    } else { // Si no, fue solo una aproximacion y continua con el metodo de Newton
        printf("Aproximacion de raiz con el metodo de Newton \n");
        printf("Ingrese el valor de epsilon para el metodo de Newton \n");
        scanf("%f", &epsilon);
        float raiz = newton(epsilon, x0);
        printf("La raiz hallada es: %.2f \n", raiz);
        printf("f(x) evaluada en la raiz hallada es: %.5f", f(raiz));
        return 0;
    }
}

float triseccion(float a, float b, float epsilon) {
    float c1, c2;
    int pasos = 0;
    do {
        // Divido el intervalo b-a en 3 partes, c1=1/3 y c2=2/3 del intervalo
        c1 = a+(b-a)/3;
        c2 = a+2*(b-a)/3;
        if(f(c1)==0){ // En caso de que c1 o c2 coincidan con una raiz, retorno el valor
            return c1;
        } else if(f(c2)==0){
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
        pasos++;
    } while(fabs(b-a) >= epsilon);
    // Una vez que encontre el intervalo que seguro contiene una raiz, retorno el punto medio.
    printf("Aproximacion hecha en %d pasos con el metodo de triseccion \n", pasos);
    return (a+b)/2;
}

float newton(float epsilon, float x0){
    float xn = x0;
    float xa;
    int pasos=0;
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
        pasos++;
        printf("Aproximacion obtenida en el paso %d: %f \n", pasos, xn);
    } while(fabs(xn-xa) >= epsilon);
    return xn;
}

// Funcion a analizar
float f(float x){
    return pow(x,3) - 5*x + sin(4*x) - 10;
}

// Derivada de f(x)
float f_prima(float x){
    return 3*pow(x,2) - 5 + 4*cos(4*x);
}

// Verifica el signo de x evaluada en f(x)
int sgn(float num) {
    if(num<0) return -1;
    else if(num==0) return 0;
    else return 1;
}
