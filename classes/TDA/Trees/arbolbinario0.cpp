// Implementar gestion de nodos binarios

#include "nodobinario.h"
using namespace std;

int main()
{
    // PROTOTIPO
    void imprimirArbol(NodoBinario * p);
    NodoBinario n1, n2, n3; // creacion de un nodo
    Tipo x, aux, fin = 999; // variable de lectura
    cout << "Ingrese un valor para almacenar en el nodo1: ";
    cin >> x;
    n1.setDato(x);
    cout << "Ingrese un valor para almacenar en el nodo2: ";
    cin >> x;
    n2.setDato(x);
    cout << "Ingrese un valor para almacenar en el nodo3: ";
    cin >> x;
    n3.setDato(x);
    n1.setNodoBinarioI(&n2);
    n1.setNodoBinarioD(&n3);
    cout << "VALORES CONTENIDOS EN EL ARBOL BINARIO " << endl;
    imprimirArbol(&n1); // llamado a la funcion que recorre e imprime el arbol binario
    return 0;
}

void imprimirArbol(NodoBinario *p)
{
    if (p != NULL)
    {
        cout << " > " << p->getDato() << endl;
        imprimirArbol(p->getIzq());
        imprimirArbol(p->getDer());
    }
    return;
}