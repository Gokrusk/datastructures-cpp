// Programa que permite ingresar elementos y generar listas de elementos que terminen en cada uno de los digitos del sistema de base 10
#include "lista.h"
using namespace std;

int main()
{
    // PROTOTIPOS
    void leerLista(Lista * a);                        // insertar datos en una lista
    void imprimirLista(Lista a);                      // presenta los valores contenidos en los nodos de una lista
    void unirListas(Lista a, Lista b, Lista * c); // genera una lista con elementos ordenados a partir de dos listas
    Lista l, m, n;
    cout << " LISTA 1 " << endl;
    leerLista(&l);
    cout << " LISTA 2 " << endl;
    leerLista(&m);
    unirListas(l, m, &n);
    cout << " LISTA RESPUESTA " << endl;
    imprimirLista(n);
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
void imprimirLista(Lista a)
{
    // recorrido de la lista
    Nodo *actual; // referencia a nodo actual de la lista
    cout << endl
         << " VALORES ALMACENADOS EN LA LISTA " << endl;
    actual = a.getPrimero(); // almacena temporalmente la posicion del primer nodo
    while (actual != NULL)   // repetir mientras no se alcance el final de la lista
    {
        cout << "> " << actual->getDato() << endl;
        actual = actual->getPunt(); // desplaza el puntero actual al siguiente nodo de la lista
    }
    cout << endl;
}

void unirListas(Lista a, Lista b, Lista *c) // genera dos listas a partir de la original, 1. elementos pares, 2. elementos impares
{
    Lista d;
    // recorrido de la lista
    Nodo *actual; // referencia a nodo actual de la lista
    Nodo *actual2;
    Nodo *actual3;
    actual = a.getPrimero(); // almacena temporalmente la posicion del primer nodo
    actual2 = b.getPrimero();
    while (actual != NULL)   // repetir mientras no se alcance el final de la lista
    {
        c->insertarNodoFinal(actual->getDato());
        actual = actual->getPunt();
    }
    while (actual2 != NULL)   // repetir mientras no se alcance el final de la lista
    {
        c->insertarNodoFinal(actual2->getDato());
        actual2 = actual2->getPunt();
    }
    actual3 = c->getPrimero();
    while (actual3 != NULL)
    {
        d.insertarEnOrden(actual3->getDato());
        actual3 = actual3->getPunt();
    }
    *c = d;
    cout << endl;
}