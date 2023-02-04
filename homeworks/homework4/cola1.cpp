// Invertir el orden de los números pares contenidos.
// Tener en cuenta que los demás elementos deben quedar en el mismo orden.

#include <iostream>
using namespace std;
#include "cola.h"
#include "pila.h"

int main()
{
    // PROTOTIPOS
    void ingresarCola(Cola * a);                      // metodo para insertar valores a cola
    void imprimirCola(Cola a);                        // metodo para imprimir cola
    void buscarPares(Cola a, Cola * b, Pila p);       // metodo para buscar los pares e invertir
    void insertarParesInvertidos(Cola * a, Cola * b); // metodo para insertar pares invertidos
    Cola b, c;
    Pila p;
    Tipo val;
    ingresarCola(&c);
    cout << endl
         << " COLA INGRESADA " << endl;
    imprimirCola(c);
    cout << endl;
    buscarPares(c, &b, p);
    cout << " PARES INVERTIDOS " << endl;
    imprimirCola(b);
    insertarParesInvertidos(&c, &b);
    cout << endl
         << " COLA CON PARES INVERTIDOS " << endl;
    imprimirCola(c);
}

void ingresarCola(Cola *a)
{
    Tipo val = 0, fin = 999;
    do
    {
        cout << "Ingrese elemento, (ingrese " << fin << " para finalizar): ";
        cin >> val;
        if (val != fin)
        {
            a->insertarVal(val);
        }
    } while (val != fin);
}

void imprimirCola(Cola a)
{
    cout << "[ ";
    while (!a.colaVacia())
    {
        cout << a.extraerVal() << " ";
    }
    cout << "]";
}

void buscarPares(Cola a, Cola *b, Pila p)
{
    Tipo aux;
    while (!a.colaVacia()) // mientras no este vacia
    {
        aux = a.extraerVal(); // extrae un valor, si es par lo inserta en una pila
        if (aux % 2 == 0)
        {
            p.push(aux);
        }
    }
    while (!p.pilaVacia()) // inserta los valores de la pila en una cola
    {
        b->insertarVal(p.pop());
    }
}

void insertarParesInvertidos(Cola *a, Cola *b)
{
    Cola c;
    Tipo aux1, aux2;
    while (!a->colaVacia()) // mientras cola no este vacia
    {
        aux1 = a->extraerVal();
        if (aux1 % 2 == 0) // si el valor es par inserta en una cola los valores pares invertidos
        {
            c.insertarVal(b->extraerVal());
        }
        else
            c.insertarVal(aux1); // si no inserta los valores que no son pares sin afectar su orden
    }
    *a = c;
}