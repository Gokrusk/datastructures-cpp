// Invertir el orden de los valores contenidos en los nodos de una lista ingresada previamente
#include "lista.h"
using namespace std;

int main()
{
    // PROTOTIPOS
    void leerLista(Lista * a);                 // insertar datos en una lista
    void imprimirLista(Lista a);               // presenta los valores contenidos en los nodos de una lista
    void invertirOrdenValoresNodos(Lista * a); // invierte el orden de los valores de los nodos
    Tipo invertirValor(Tipo x);                // invierte el orden de un valor;
    Lista l;
    leerLista(&l);
    imprimirLista(l);
    cout<<"VALORES DE NODOS INVERTIDOS"<<endl;
    invertirOrdenValoresNodos(&l);
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

void invertirOrdenValoresNodos(Lista *a) // invierte el orden de los valores de los nodos
{
    Lista b;
    Tipo x;
    // recorrido de la lista
    Nodo *actual;
    actual = a->getPrimero();
    while (actual != NULL)
    {
        x = actual->getDato();
        b.insertarNodoFinal(invertirValor(x));
        actual = actual->getPunt();
    }
    *a = b;
}
