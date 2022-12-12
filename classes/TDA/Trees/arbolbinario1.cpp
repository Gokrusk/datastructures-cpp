// Implementa un arbol binario basico
#include <iostream>
using namespace std;
#include "arbolbinario.h"

int main()
{
    // PROTOTIPOS
    void ingresarAB(ArbolBinario * a); // funcion que ingresa un arbol binario
    ArbolBinario a;
    Tipo x; NodoBinario* p;
    cout << "El arbol " << (a.esVacio() ? "si" : "no") << " esta vacio" << endl;
    cout << "Ingresar nodo: ";
    cin >> x;
    p = new NodoBinario(x);
    a.setNodoRaiz(p);
    ingresarAB(&a);
    cout << "El arbol " << (a.esVacio() ? "si" : "no") << " esta vacio" << endl;
    a.imprimirArbol(a.getRaiz());
    return 0;
}
// void ingresarAB(ArbolBinario *a) // funcion que ingresa un arbol binario
// {
//     NodoBinario n1, n2, n3;    // creacion de un nodo
//     NodoBinario *p1, *p2, *p3; // apuntadores a nodos binarios
//     Tipo x;         // variable de lectura

//     cout << "Ingrese un valor para almacenar en el nodo2: ";
//     cin >> x;
//     p2 = a->construirAB(x, NULL, NULL);

//     cout << "Ingrese un valor para almacenar en el nodo3: ";
//     cin >> x;
//     p3 = a->construirAB(x, NULL, NULL);

//     cout << "Ingrese un valor para almacenar en el nodo1: ";
//     cin >> x;

//     p1 = a->construirAB(x, p2, p3);
//     a->setNodoRaiz(p1); // enlaza la raiz del arbol binario a con direcciones del nodo
// }

void ingresarAB(ArbolBinario *a, Tipo x, NodoBinario *p) // funcion que ingresa un arbol binario
{
    while (x != 999)
    {
        cout << "Ingresar nodo: ";
        cin >> x;
        p = new NodoBinario(x);
        a->construirAB(x,p,NULL);
        a->construirAB(x,NULL,p);
    }
}