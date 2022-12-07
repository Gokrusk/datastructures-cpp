// Programa que permite ingresar elementos y generar listas de elementos que terminen en cada uno de los digitos del sistema de base 10
#include "lista.h"
using namespace std;
#include <iostream>

int main()
{
    // PROTOTIPOS
    void leerLista(Lista * a);     // insertar datos en una lista
    void imprimirLista(Lista a[]); // presenta los valores contenidos en los nodos de una lista
    // void generarListas(Lista a); // genera listas en base al ultimo digito de los elementos
    void generarListas(Lista a[], Lista m); // genera listas en base al ultimo digito de los elementos
    Lista l[9];
    Lista m;
    leerLista(&m);
    generarListas(l, m);
    imprimirLista(l);
    return 0;
}
void leerLista(Lista *a) // insertar datos en una lista
{
    Tipo x, fin = 999;
    do
    {
        cout << "Ingrese valor para la lista (fin 999): ";
        cin >> x;
        if (x != fin)
        {
            a->insertarNodoFinal(x);
        }
    } while (x != fin);
}
void imprimirLista(Lista a[])
{
    // recorrido de la lista
    Nodo *actual; // referencia a nodo actual de la lista
    cout << endl
         << " VALORES ALMACENADOS EN LA LISTA " << endl;

    for (int i = 0; i < 9; i++)
    {
        if (!a[i].esVacia())
        {
            cout << "Lista " << i << endl;
            actual = a[i].getPrimero(); // almacena temporalmente la posicion del primer nodo
            while (actual != NULL)      // repetir mientras no se alcance el final de la lista
            {
                cout << "> " << actual->getDato() << endl;
                actual = actual->getPunt(); // desplaza el puntero actual al siguiente nodo de la lista
            }
        }
        cout << endl;
    }
}

void generarListas(Lista a[], Lista m) // genera listas en base al ultimo digito de los elementos
{
    // recorrido de la lista
    Nodo *actual; // referencia a nodo actual de la lista
    Tipo x;
    actual = m.getPrimero(); // almacena temporalmente la posicion del primer nodo
    while (actual != NULL)   // repetir mientras no se alcance el final de la lista
    {
        x = actual->getDato();
        if (x < 0)
        {
            x *= -1;
        }
        switch (x % 10)
        {
        case 0:
            a[0].insertarEnOrden(actual->getDato());
            // b = New Lista.insertarEnOrden(actual->getDato());
            break;
        case 1:
            a[1].insertarEnOrden(actual->getDato());
            break;
        case 2:
            a[2].insertarEnOrden(actual->getDato());
            break;
        case 3:
            a[3].insertarEnOrden(actual->getDato());
            break;
        case 4:
            a[4].insertarEnOrden(actual->getDato());
            break;
        case 5:
            a[5].insertarEnOrden(actual->getDato());
            break;
        case 6:
            a[6].insertarEnOrden(actual->getDato());
            break;
        case 7:
            a[7].insertarEnOrden(actual->getDato());
            break;
        case 8:
            a[8].insertarEnOrden(actual->getDato());
            break;
        case 9:
            a[9].insertarEnOrden(actual->getDato());
            break;
        }
        actual = actual->getPunt();
        cout << endl;
    }
}