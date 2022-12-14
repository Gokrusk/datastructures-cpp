// Elaborar un programa que permita ingresar un árbol binario de valores numericos
// de enteros positivos, y proceda a presentar un listado ordenado descendentemente de los niveles del mismo,
// en base a la suma de valores de nodos.

// Implementa un arbol binario basico
#include <iostream>
using namespace std;
#include "arbolbinario.h"

int main()
{
    // PROTOTIPOS
    void ingresarAB(ArbolBinario * a); // funcion que ingresa un arbol binario
    void leerAB(ArbolBinario * a);
    int contarNodosIzquierdos(NodoBinario * p);
    int contarNodosDerechos(NodoBinario * p);
    void nivelArbol(int *nivel, int cont1, int cont2);
    int sumarNiveles(NodoBinario * p, int nivel);
    int cont = 0, cont1 = 0, cont2 = 0, nivel = 0;
    ArbolBinario a;
    leerAB(&a);
    cout << endl
         << "ARBOL BINARIO" << endl;
    a.imprimirIDN(a.getRaiz());
    cont1 = contarNodosIzquierdos(a.getRaiz());
    cont2 = contarNodosDerechos(a.getRaiz());
    nivelArbol(&nivel, cont1, cont2);
    cout << endl
         << "Nivel del arbol: " << nivel << endl
         << endl;
    cout << sumarNiveles(a.getRaiz(), nivel) << endl;
    return 0;
}

void leerAB(ArbolBinario *a)
{
    NodoBinario *leerNodo(int margen);
    a->setNodoRaiz(leerNodo(0));
}

NodoBinario *leerNodo(int margen)
{
    Tipo aux;
    Tipo fin = 999;
    NodoBinario *p;

    void imprimirEsp(int c);
    cout << endl;
    imprimirEsp(margen);
    cout << " Valor para el nodo. Ingrese [999] para terminar: ";
    cin >> aux;

    if (aux != fin)
    {
        p = new NodoBinario(aux);
        imprimirEsp(margen);
        cout << " --- NODO DERIVADO IZQUIERDO ---";
        p->setNodoBinarioI(leerNodo(margen + 1));
        imprimirEsp(margen);
        cout << " --- NODO DERIVADO DERECHO ---";
        p->setNodoBinarioD(leerNodo(margen + 1));
        imprimirEsp(margen);
        return p;
    }
    else
    {
        return NULL;
    }
}

void imprimirEsp(int margen)
{
    for (int i = 0; i <= margen; i++)
    {
        cout << " ";
    }
}

int contarNodosIzquierdos(NodoBinario *p)
{
    if (p != NULL)
    {
        return 1 + contarNodosIzquierdos(p->getIzq());
    }
    else
        return 0;
}

int contarNodosDerechos(NodoBinario *p)
{
    if (p != NULL)
    {
        return 1 + contarNodosDerechos(p->getDer());
    }
    else
        return 0;
}
void nivelArbol(int *nivel, int cont1, int cont2)
{
    if (cont1 > cont2)
    {
        *nivel = cont1;
    }
    else
        *nivel = cont2;
}
int sumarNiveles(NodoBinario *p, int nivel)
{
    if (nivel > 0)
    {
        cout << " > " << p->getDato() << ", ";
        return sumarNiveles(p->getIzq(), nivel-1) + sumarNiveles(p->getDer(), nivel-1);
        cout << ">" << p->getDato();
    }
}
/*EJEMPLO
    5
    2   4
1 0     1   1

2,4: 6
5: 5
1,0,1,1: 3
*/