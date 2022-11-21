#include "lista.h"
using namespace std;

int main()
{
    Lista l;             // creacion del objeto lista
    Tipo x;
    // l.setPrimero(&n1); // incluir nodo a lista
    // Nodo n2(10,&n1);
    // l.setPrimero(&n2);
    // Nodo n3(20,&n2);
    // l.setPrimero(&n3);
    
    for (int i = 0; i < 5; i++)
    {
        cout<<"Ingrese valor para la lista: ";
        cin>>x;
        Nodo nuevo(x,l.getPrimero());
        l.setPrimero(&nuevo);
    }
    
    // recorrido de la lista
    Nodo *actual; // referencia a nodo actual de la lista
    cout << endl
         << " VALORES ALMACENADOS EN LA LISTA " << endl;
    actual = l.getPrimero(); // almacena temporalmente la posicion del primer nodo
    while (actual != NULL)   // repetir mientras no se alcance el final de la lista
    {
        cout << "> " << actual->getDato() << endl;
        actual = actual->getPunt(); // desplaza el puntero actual al siguiente nodo de la lista
    }
    cout << endl;
    return 0;
}