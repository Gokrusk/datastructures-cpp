// Programa que permite insertar elementos a una lista e indica cantidad de elementos repetidos
#include "lista.h"
using namespace std;

int main()
{
    // PROTOTIPOS
    void leerLista(Lista * a);                    // insertar datos en una lista
    void imprimirLista(Lista a);                  // presenta los valores contenidos en los nodos de una lista
    void nElementosRepetidos(Lista a, Lista * c); // indica la cantidad de elementos repetidos
    Lista l, m;
    leerLista(&l);
    imprimirLista(l);
    nElementosRepetidos(l, &m);
    imprimirLista(m);
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

void eliminarValor(Lista a) // eliminar valor de una lista
{
    Tipo x;
    cout << "Ingrese valor para eliminar: ";
    cin >> x;
    a.eliminarNodo(x);
}

void insertarUnValorEnLista(Lista a) // funcion que inserta un elemento en medio de una lista
{
    Tipo x, ant; // var de lectura

    cout << endl
         << "INSERTAR UN VALOR EN MEDIO DE UNA LISTA";
    cout << endl
         << "Ingrese el valor a insertar: ";
    cin >> x;
    cout << endl
         << "Ingrese el valor anterior al valor a insertar: ";
    cin >> ant;
    a.insertarUnNodo(x, a.buscarElemento(ant));
}

void nElementosRepetidos(Lista a, Lista *c) // indica la cantidad de elementos repetidos
{
    Lista b;
    Nodo *actual; // referencia a nodo actual de la lista
    Nodo *actual2;
    Nodo *actual3;
    b = a;
    int cont;
    Tipo aux;
    actual = a.getPrimero(); // almacena temporalmente la posicion del primer nodo
    cout
        << " VALORES REPETIDOS EN LA LISTA ";
    while (actual != NULL) // repetir mientras no se alcance el final de la lista
    {
        actual2 = b.getPrimero(); // almacena temporalmente la posicion del primer nodo
        cont = 0;
        // cout << "->" << actual->getDato() << endl;
        while (actual2 != NULL)
        {
            if (actual->getDato() == actual2->getDato())
            {
                cont++;
                //cout << actual->getDato() << " " << actual2->getDato() << endl;
            }
            actual2 = actual2->getPunt();
        }
        if (cont > 1)                           //si se repite mas de una vez
        {   
            aux = actual->getDato();    
            if(c->buscarElemento(aux) == NULL)  //se comprueba que el elemento repetido no este en la lista
            {
                c->insertarNodoFinal(actual->getDato());    //se insertar el elemento repetido
            }
        }
        actual = actual->getPunt(); // desplaza el puntero actual al siguiente nodo de la lista
    }
    cont = 0;
    cout << endl
         << " CANTIDAD DE VALORES REPETIDOS: " << endl;
    actual3 = c->getPrimero(); // almacena temporalmente la posicion del primer nodo
    while (actual3 != NULL)   // repetir mientras no se alcance el final de la lista
    {
        cont++;
        actual3 = actual3->getPunt();
    }
    cout << cont <<endl;
}