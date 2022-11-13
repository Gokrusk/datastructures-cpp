// Escribir un programa para determinar si una secuencia de caracteres ingresada por el usuario
// es de la forma: X & Y donde X una cadena de caracteres e Y la cadena inversa.
// El carácter & es el separador.

#include <iostream>
#include <curses.h>
#include <cstring>
#include "stdio.h"
using namespace std;
#include "pila3.h"

int main()
{
    // PROTOTIPOS
    void leerFrase(char a[EXT]);                          // Lectura de frase
    void apilarFrase(Pila * b, char a[EXT], int tamanio); // Apilar cada caracter en una pila
    void imprimirPila(Pila c);                            // Imrpimir la pila
    Pila a,b;
    int t = 0;
    char frase[EXT];
    leerFrase(frase);
    t = strlen(frase);                                     //Longitud de cadena
    //cout<<t<<endl;
    cout<<frase[7]<<endl;
    //apilarFrase(&a, frase, t);
    //imprimirPila(a);
    return 0;
}

void leerFrase(char a[EXT])
{
    cout << "Ingrese la frase: ";
    gets(a);
}
void apilarFrase(Pila *b, char a[EXT], int tamanio)
{
    for (int i = 0; i < tamanio; i++)
    {
        b->push(a[i]);
    }
}
void imprimirPila(Pila c)
{
    cout << "[ ";
    while (!c.pilaVacia())
    {
        cout << c.pop() << " ";
    }
    cout << "]" << endl;
}