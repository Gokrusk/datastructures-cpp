// Eliminar N nodos a partir de una posición específica de la lista.
#include "lista.h"
using namespace std;

int main()
{
    // PROTOTIPOS
    void leerLista(Lista * a);                 // insertar datos en una lista
    void imprimirLista(Lista a);               // presenta los valores contenidos en los nodos de una lista
    void eliminarNodos(Lista *a, int n, int p);          // eliminar n nodos desde una posicion p
    Lista l;
    int n, p;
    leerLista(&l);
    imprimirLista(l);
    cout<<"Cuantos nodos desea eliminar: ";
    cin>>n;
    cout<<"A partir de que posicion: ";
    cin>>p;
    p-=1;
    eliminarNodos(&l,n,p);
    cout<<"NODOS ELIMINADOS"<<endl;
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

void eliminarNodos(Lista *a, int n, int p)          // eliminar n nodos desde una posicion p
{
    Nodo *actual;
    int x = 0;
    actual = a->getPrimero();
    while (x < p)
    {
        actual = actual->getPunt();
        x++;
    }
    cout<<actual->getDato()<<endl;
    x = 0;
    while (x < n)
    {
        a->eliminarNodo(actual->getDato());
        actual = actual->getPunt();
        x++;
    }
}
