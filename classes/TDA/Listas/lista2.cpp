// Programa que permite insertar elementos al final de una lista
#include "lista.h"
using namespace std;

int main()
{
    // PROTOTIPOS
    void leerLista(Lista * a);     // insertar datos en una lista
    void imprimirLista(Lista a);   // presenta los valores contenidos en los nodos de una lista
    void eliminarValor(Lista a); // eliminar valor de una lista
    void insertarUnValorEnLista(Lista a);	//funcion que inserta un elemento en medio de una lista
    Lista l;
    Tipo x;
    leerLista(&l);
    imprimirLista(l);
    cout << "Primer valor contenido en la lista es: " << l.getPrimero()->getDato() << endl;
    cout << "Ultimo valor contenido en la lista es: " << l.ultimoNodo()->getDato() << endl;
    cout << "Valor a buscar: ";
    cin >> x;
    cout << "El valor " << (l.buscarElemento(x) != NULL ? "si existe" : "no existe") << " en la lista" << endl;
    cout<< "Ingrese valor a eliminar: ";
    cin>>x;
    l.eliminarNodo(x);
    imprimirLista(l);
    insertarUnValorEnLista(l);
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
    cout<<"Ingrese valor para eliminar: ";
    cin>>x;
    a.eliminarNodo(x);
}

void insertarUnValorEnLista(Lista a)	//funcion que inserta un elemento en medio de una lista
{
    Tipo x, ant;						//var de lectura
	
	cout << endl << "INSERTAR UN VALOR EN MEDIO DE UNA LISTA";
	cout << endl << "Ingrese el valor a insertar: ";
	cin >> x;
	cout << endl << "Ingrese el valor anterior al valor a insertar: ";
	cin >> ant;
	a.insertarUnNodo(x,a.buscarElemento(ant));	
}