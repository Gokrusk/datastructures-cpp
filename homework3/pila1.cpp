// Programa que utilice una pila para determinar si cada una de las frases ingresadas por el usuario
// es un palíndromo (frase cuya lectura directa e indirecta es igual: ana, alila, etc).
#include <iostream>
#include <curses.h>
using namespace std;
#include "pila.h"

int main()
{
    char f[5];
    Pila frase;
    cout << "Ingrese la frase: ";
    cin >> f;
    //Insertar letras mientras escribes, hasta que presione enter.
    for (int i = 0; i < 5; i++)
    {
        cout << f[i] <<endl;
    }
    
    
}