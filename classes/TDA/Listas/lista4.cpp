// Programa que permite insertar elementos a una lista generar una lista para elementos pares y otra lista para elementos impares
#include "lista.h"
using namespace std;

int main()
{
    // PROTOTIPOS
    void leerLista(Lista * a);                        // insertar datos en una lista
    void imprimirLista(Lista a);                      // presenta los valores contenidos en los nodos de una lista
    void dividirListaParImpar(Lista a, Lista * b, Lista * c); // genera dos listas a partir de la original, 1. elementos pares, 2. elementos impares
    Lista l, m, n;
    leerLista(&l);
    imprimirLista(l);
    dividirListaParImpar(l, &m, &n);
    cout << " LISTA DE PARES " << endl;
    imprimirLista(m);
    cout << " LISTA DE IMPARES " << endl;
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

void dividirListaParImpar(Lista a, Lista *b, Lista *c) // genera dos listas a partir de la original, 1. elementos pares, 2. elementos impares
{
    // recorrido de la lista
    Nodo *actual; // referencia a nodo actual de la lista
    actual = a.getPrimero(); // almacena temporalmente la posicion del primer nodo
    while (actual != NULL)   // repetir mientras no se alcance el final de la lista
    {
        if(actual->getDato() % 2 == 0)
        {
            b->insertarNodoFinal(actual->getDato());
        }else
            c->insertarNodoFinal(actual->getDato());
        actual = actual->getPunt(); // desplaza el puntero actual al siguiente nodo de la lista
    }
    cout << endl;
}