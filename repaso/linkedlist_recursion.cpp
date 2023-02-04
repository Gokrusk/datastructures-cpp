// Administrar una linked list con recursividad

#include <iostream>
using namespace std;
#include "lista.h"

int main()
{
    Lista l, b, c;
    void readList(Lista * l, Tipo x);                                   // funcion recurisva para leer una lista
    void printList(Lista l, Nodo * actual);                             // funcion recursiva para imprimir una lista
    void separateEvenOdd(Lista l, Lista * b, Lista * c, Nodo * actual); // funcion recursiva para separar una lista ingresada en dos listas una de pares y otra de impares

    cout << endl
         << "LEER LISTA" << endl;
    readList(&l, 0);
    cout << endl
         << "IMPRIMIR LISTA" << endl;
    cout << "[ ";
    printList(l, l.getPrimero());
    cout << "]" << endl;
    cout << endl
         << "LISTA PARES" << endl;
    separateEvenOdd(l, &b, &c, l.getPrimero());
    cout << "[ ";
    printList(b, b.getPrimero());
    cout << "]" << endl;
    cout << endl
         << "LISTA IMPARES" << endl;
    cout << "[ ";
    printList(c, c.getPrimero());
    cout << "]" << endl;
    return 0;
}

void readList(Lista *l, Tipo x) // funcion recurisva para leer una lista
{
    Tipo f = 999;
    cout << "Ingrese elemento: ";
    cin >> x;
    if (x != f)
    {
        l->insertarNodoFinal(x);
        readList(l, x);
    }
}

void printList(Lista l, Nodo *actual) // funcion recursiva para imprimir una lista
{
    if (actual != NULL)
    {
        cout << actual->getDato() << " ";
        actual = actual->getPunt();
        printList(l, actual);
    }
}

void separateEvenOdd(Lista l, Lista *b, Lista *c, Nodo *actual) // funcion recursiva para separar una lista ingresada en dos listas una de pares y otra de impares
{
    if (actual != NULL)
    {
        if (actual->getDato() % 2 == 0)
        {
            b->insertarNodoFinal(actual->getDato());
        }
        else
        {
            c->insertarNodoFinal(actual->getDato());
        }
        actual = actual->getPunt();
        separateEvenOdd(l, b, c, actual);
    }
}