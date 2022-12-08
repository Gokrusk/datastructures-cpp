// Concatenar ordenadamente dos listas ingresadas previamente, que se supone ya se encuentran ordenadas desde el inicio.
#include "lista.h"
using namespace std;

int main()
{
    // PROTOTIPOS
    void leerLista(Lista * a);                 // insertar datos en una lista
    void imprimirLista(Lista a);               // presenta los valores contenidos en los nodos de una lista
    void mergeListas(Lista *l,Lista m);         //concatena listas
    Lista l,m;
    cout<<"LISTAS 1"<<endl;
    leerLista(&l);
    imprimirLista(l);
    cout<<"LISTAS 2"<<endl;
    leerLista(&m);
    imprimirLista(m);
    cout<<"LISTAS CONCATENADAS"<<endl;
    mergeListas(&l,m);
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

Tipo invertirValor(Tipo x)
{
    Tipo aux,n;
    while (x > 0 || x < 0)
    {
        aux = x % 10;
        n = (n * 10) + aux;
        x /= 10;
    }
    return n;
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
        //cout<<invertirValor(actual->getDato())<<endl;
        actual = actual->getPunt(); // desplaza el puntero actual al siguiente nodo de la lista
    }
    cout << endl;
}

void mergeListas(Lista *l,Lista m)         //concatena listas
{
    Nodo* actual;
    actual = m.getPrimero();

    while (actual != NULL)
    {
        l->insertarEnOrden(actual->getDato());
        actual = actual->getPunt();
    }
}