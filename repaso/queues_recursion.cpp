// Administrar una queue con recursividad

#include <iostream>
using namespace std;
#include "cola.h"
#include "pila.h"

int main()
{
    Cola c, b, d;
    Pila p;
    void insertElements(Cola * c, Tipo x);            // funcion recursiva para insertar elementos en una queue
    void printQueue(Cola c);                          // funcion recursiva para imprimir elementos de una queue
    void evenNumbers(Cola c, Cola * b, Pila p);       // funcion recursiva para encontrar elementos pares e insertarlos en una cola de forma invertida
    void insertEvenReverse(Cola * c, Cola b, Cola d); // funcion recursiva para insertar pares invertidos

    cout << endl
         << "INSERCION DE ELEMENTOS" << endl;
    insertElements(&c, 0);
    cout << endl
         << "IMPRESION DE ELEMENTOS" << endl;
    cout << "[ ";
    printQueue(c);
    cout << "]" << endl;
    cout << endl
         << "INVERTIR ORDEN DE NUMEROS PARES SIN ALTERAR LOS DEMAS" << endl;
    cout << "[ ";
    evenNumbers(c, &b, p);
    insertEvenReverse(&c, b, d);
    printQueue(c);
    cout << "]" << endl;
    return 0;
}

void insertElements(Cola *c, Tipo x) // funcion recursiva para insertar elementos en una queue
{
    Tipo f = 999;
    cout << "Ingrese elemento: ";
    cin >> x;
    if (x != f)
    {
        c->insertarVal(x);
        insertElements(c, x);
    }
}

void printQueue(Cola c) // funcion recursiva para imprimir elementos de una queue
{
    if (!c.colaVacia())
    {
        cout << c.extraerVal() << " ";
        printQueue(c);
    }
}

void stackLoop(Cola *c, Pila p)
{
    if (!p.pilaVacia())
    {
        c->insertarVal(p.pop());
        stackLoop(c, p);
    }
}

void evenNumbers(Cola c, Cola *b, Pila p) // funcion recursiva para encontrar elementos pares e insertarlos en una cola
{
    Tipo aux;
    if (!c.colaVacia())
    {
        aux = c.extraerVal();
        if (aux % 2 == 0)
        {
            p.push(aux);
        }
        evenNumbers(c, b, p);
    }
    else
    {
        stackLoop(b, p);
    }
}

void insertEvenReverse(Cola *c, Cola b, Cola d) // funcion recursiva para insertar pares invertidos
{
    Tipo aux;
    if (!c->colaVacia())
    {
        aux = c->extraerVal();
        if (aux % 2 == 0)
        {
            d.insertarVal(b.extraerVal());
        }
        else
        {
            d.insertarVal(aux);
        }
        insertEvenReverse(c, b, d);
    }
    else
    {
        *c = d;
    }
}