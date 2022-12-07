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
    // if (aux == 1)
    // {
    //     n1.setNodoBinarioI(&n2);
    // }
    // else
    // {
    //     n1.setNodoBinarioD(&n2);
    // }
    // cout << "A donde quiere apuntar nodo 3 1:izq 2:der: ";
    // cin >> aux;
    // if (aux == 1 && n1.getIzq() == NULL)
    // {
    //     n1.setNodoBinarioI(&n3);
    // }
    // else
    // {
    //     if (n1.getDer() == NULL)
    //     {
    //         n1.setNodoBinarioD(&n3);
    //     }
    //     else
    //     {
    //         n1.setNodoBinarioI(&n3);
    //     }
    // }
    // cout << "Valor almacenado en el nodo1: " << n1.getDato() << endl;
    // cout << "Subarbol izquierdo: " << n1.getIzq()->getDato() << endl;
    // cout << "Subarbol derecho: " << n1.getDer()->getDato() << endl;
    cout << "VALORES CONTENIDOS EN EL ARBOL BINARIO " << endl;
    imprimirArbol(&n1); // llamado a la funcion que recorre e imprime el arbol binario
    return 0;
}

void imprimirArbol(NodoBinario *p)
{
    if (p != NULL)
    {
        imprimirArbol(p->getDer());
        imprimirArbol(p->getIzq());
        cout << " > " << p->getDato() << endl;
    }
    return;
}