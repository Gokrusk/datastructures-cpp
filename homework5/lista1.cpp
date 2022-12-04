// Insertar ordenadamente los elementos en una lista, desde el final de la misma
#include "lista.h"
using namespace std;

int main()
{
    // PROTOTIPOS
    void leerLista(Lista * a);                  // insertar datos en una lista
    void imprimirLista(Lista a);                // presenta los valores contenidos en los nodos de una lista
    void insertarFinalOrden(Lista * a, Tipo v); // inserta los elementos desde el final de forma ordenada
    Lista l;
    leerLista(&l);
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
            a->insertarEnOrden(x);
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