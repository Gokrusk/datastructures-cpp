//Escribir un programa para determinar si una secuencia de caracteres ingresada por el usuario 
//es de la forma: X & Y donde X una cadena de caracteres e Y la cadena inversa. 
//El carácter & es el separador.

#include <iostream>
#include <curses.h>
#include <cstring>
using namespace std;
#include "pila.h"

int main()
{
    // PROTOTIPOS
    void lecturaNums(Pila * p);
    void imprimirPila(Pila p);
    int convertEntero(double a);
    int contarDigitos(int x);
    double eliminarElementosDigitosPares(Pila * p);
    Pila a;
    lecturaNums(&a);
    cout << " ELEMENTOS EN PILA " << endl;
    imprimirPila(a);
    eliminarElementosDigitosPares(&a);
    cout << " ELEMENTOS CON CANTIDAD PAR DE DIGITOS ELIMINADOS " << endl;
    imprimirPila(a);
    return 0;
}
