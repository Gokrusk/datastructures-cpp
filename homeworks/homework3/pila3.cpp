// Escribir un programa para determinar si una secuencia de caracteres ingresada por el usuario
// es de la forma: X & Y donde X una cadena de caracteres e Y la cadena inversa.
// El carácter & es el separador.

#include <iostream>
// #include <curses.h>                                              //Descomentar si se compila en linux
#include <cstring>
#include "stdio.h"
using namespace std;
#include "pila1.h"

int main()
{
    // PROTOTIPOS
    void leerFrase(char a[EXT]);                                    // Lectura de frase
    void apilarFrase(Pila * a, Pila * b, char c[EXT], int tamanio); // Apilar cada caracter en una pila
    void imprimirPila(Pila c);                                      // Imrpimir la pila
    bool comprobarInversa(Pila a, Pila b);                          // Comprobar inversa
    Pila a, b;
    int t = 0;
    bool comp;
    Tipo frase[EXT];
    leerFrase(frase);
    t = strlen(frase); // Longitud de cadena
    apilarFrase(&a, &b, frase, t);
    imprimirPila(a);
    imprimirPila(b);
    comp = comprobarInversa(a, b);
    if (comp)
    {
        cout << "La secuencia es de la forma X & Y" << endl;
    }else
        cout << "La secuencia no es de la forma X & Y" << endl;
    return 0;
}

void leerFrase(char a[EXT])
{
    cout << "Ingrese la frase: ";
    gets(a);
}
void apilarFrase(Pila *a, Pila *b, char c[EXT], int tamanio)
{
    int x = 0, y = 0;
    for (int i = 0; i < tamanio; i++) // Encontrar posición de separador
    {
        if (c[i] == ' ')
        {
            x = i;
        }
    }
    do // Apilar primera cadena
    {
        a->push(c[y]);
        y++;
    } while (y < x);
    y += 1;
    do // Apilar segunda cadena
    {
        b->push(c[y]);
        y++;
    } while (y < tamanio);
}
bool comprobarInversa(Pila a, Pila b) // Comprobar inversa
{
    Pila c;
    Tipo x;
    int cont = 0;
    int t = a.tamanioPila();
    while(!a.pilaVacia())
    {
        c.push(a.pop());
    }
    if (c.tamanioPila() == b.tamanioPila())
    {
        while (!c.pilaVacia())
        {
            x = c.pop();
            if (x == b.pop())
            {
                cont++;
            }
        }
    }
    else
    {
        return false;
    }
    if (cont == t) // Son iguales si la cantidad de igualdades es igual a el tamanio de cadena
    {
        return true;
    }
    return false;
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