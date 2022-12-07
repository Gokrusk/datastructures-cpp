// Implementar gestion de nodos binarios

#include "nodobinario.h"
using namespace std;

int main()
{
    NodoBinario n1, n2, n3; // creacion de un nodo
    Tipo x, aux, fin = 999; // variable de lectura
    // cout << "Ingrese un valor para almacenar en el nodo1: ";
    // cin >> x;
    // n1.setDato(x);
    // cout << "Ingrese un valor para almacenar en el nodo2: ";
    // cin >> x;
    // n2.setDato(x);
    // cout << "Ingrese un valor para almacenar en el nodo3: ";
    // cin >> x;
    // n3.setDato(x);
    // cout << "A donde quiere apuntar nodo 2 1:izq 2:der: ";
    // cin >> aux;
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
    cout << "Ingrese un valor para almacenar en el nodo1: ";
    cin >> x;
    n1.setDato(x);
    while (x != fin)
    {
        NodoBinario actual;
        NodoBinario n;
        cout << "Ingrese un valor para almacenar en el nodo: ";
        cin >> x;
        n.setDato(x);
        cout << "A donde quiere apuntar nodo 2 1:izq 2:der: ";
        cin >> aux;
        if (aux == 1)
        {
            n.setNodoBinarioI(&n);
        }
        else
        {
            n1.setNodoBinarioD(&n2);
        }
        cout << "A donde quiere apuntar nodo 3 1:izq 2:der: ";
        cin >> aux;
        if (aux == 1 && n1.getIzq() == NULL)
        {
            n1.setNodoBinarioI(&n3);
        }
        else
        {
            if (n1.getDer() == NULL)
            {
                n1.setNodoBinarioD(&n3);
            }
            else
            {
                n1.setNodoBinarioI(&n3);
            }
        }
    }

    return 0;
}