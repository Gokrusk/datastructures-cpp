#include "lista.h"
using namespace std;

int main()
{
    void imprimirLista(Lista a); // presenta los valores contenidos en los nodos de una lista
    void leerLista(Lista * a);   // insertar datos en una lista
    Lista l;                     // creacion del objeto lista
    cout << endl
         << "La lista " << (l.esVacia() ? "si " : "no ") << " esta vacia" << endl;
    leerLista(&l);
    cout << endl
         << "La lista " << (l.esVacia() ? "si " : "no ") << " esta vacia" << endl;
    imprimirLista(l);
    cout << "Primer valor contenido en la lista es: " << l.getPrimero()->getDato() << endl;
    cout << "Ultimo valor contenido en la lista es: " << l.ultimoNodo()->getDato() << endl;
    l.anular();
    cout << endl
         << "La lista " << (l.esVacia() ? "si " : "no ") << " esta vacia" << endl;

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
            a->insertarNodoInicio(x);
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