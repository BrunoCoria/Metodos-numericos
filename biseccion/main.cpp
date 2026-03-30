#include <stdio.h>
#include "lib.h"
void ej_1();

int main() {
    ej_1();
    return 0;
}

void ej_1() {
/*
1 – Emplear el método de bisección y hacer los primeros 3 pasos, con el fin de aproximar una
raíz para cada una de las siguientes funciones, cuando sea posible usarlo. Para las funciones
en las cuales no se pueda usar, justificar.

f(x) = √x --> No se puede, no tiene valores negativo en la imagen
f(x) = x3 +1 --> Se puede, raiz = -1
f(x) = x3-x+1 --> Se puede, raiz = -1,3
f(x) = e-x – sen x --> Se puede, raiz = 0,63
f(x) = 2/x
f(x) = |x + 5|
f(x) = 2x + 3
*/
    printf("%.2f", biseccion_n_pasos(-1, 1, 3));
}
