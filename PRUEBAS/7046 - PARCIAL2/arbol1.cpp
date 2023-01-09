// Elaborar un programa que permita ingresar un árbol binario de valores numericos
// de enteros positivos, y proceda a presentar un listado ordenado descendentemente de los niveles del mismo,
// en base a la suma de valores de nodos.

    //impresion de niveles con una lista con la suma e imprimir los niveles si su suma coincida con los elementos de la lista suma
#include <iostream>
using namespace std;
#include "arbolbinario.h"
#include "lista.h"
int main()
{
    // PROTOTIPOS
    void ingresarAB(ArbolBinario * a); // funcion que ingresa un arbol binario
    void leerAB(ArbolBinario * a);
    int contarNodosIzquierdos(NodoBinario * p);
    int contarNodosDerechos(NodoBinario * p);
    void nivelArbol(int *nivel, int cont1, int cont2);
    void niveles(NodoBinario * p, int nivel, int nivelaux, int aux, Lista l[]);
    void sumarNivel(Lista l);
    void impresionNiveles(Lista a[], int n);
    int cont = 0, cont1 = 0, cont2 = 0, nivel = 0;
    ArbolBinario a;
    int aux = 0;
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
    Lista *m;
    m = new Lista[nivel];
    niveles(a.getRaiz(), 0, 0, aux, m);
    for (int i = 0; i < nivel; i++)
    {
        sumarNivel(m[i]);
    }
    // sumarNivel(m);
    impresionNiveles(m, nivel);
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
void niveles(NodoBinario *p, int nivel, int nivelaux, int aux, Lista l[])
{
    aux = 0;
    if (p == NULL)
    {
        return;
    }
    if (nivel == nivelaux)
    {
        aux += p->getDato();
        l[nivel].insertarEnOrden(aux);
        niveles(p->getIzq(), nivel + 1, nivelaux + 1, aux, l);
        niveles(p->getDer(), nivel + 1, nivelaux + 1, aux, l);
    }
}
void sumarNivel(Lista l)
{
    Nodo *actual;
    int aux = 0;
    actual = l.getPrimero();
    while (actual != NULL)
    {
        aux += actual->getDato();
        actual = actual->getPunt();
    }
    l.insertarNodoFinal(aux);
}
void impresionNiveles(Lista a[], int n)
{
    cout << endl;
    // recorrido de la lista
    Nodo *actual; // referencia a nodo actual de la lista
    for (int i = 0; i < n; i++)
    {
        cout << "NIVEL " << i << ":" << endl;
        actual = a[i].getPrimero(); // almacena temporalmente la posicion del primer nodo
        cout << "[ ";
        while (actual != NULL)
        {
            cout << actual->getDato() << " ";
            actual = actual->getPunt();
        }
        cout << "]" << endl;
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