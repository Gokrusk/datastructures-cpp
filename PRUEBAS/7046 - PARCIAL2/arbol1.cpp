// Elaborar un programa que permita ingresar un árbol binario de valores numericos
// de enteros positivos, y proceda a presentar un listado ordenado descendentemente de los niveles del mismo,
// en base a la suma de valores de nodos.

#include <iostream>
using namespace std;
#include "arbolbinario.h"
#include "lista.h"
int main()
{
    int cont = 0, cont1 = 0, cont2 = 0, nivel = 0;
    ArbolBinario a;
    int aux = 0;
    // PROTOTIPOS
    void ingresarAB(ArbolBinario * a); // funcion que ingresa un arbol binario
    void leerAB(ArbolBinario * a);
    int contarNodosIzquierdos(NodoBinario * p); // funcion para contar nodos de la izquierda
    int contarNodosDerechos(NodoBinario * p);   // funcion para contar nodos de la derecha
    void nivelArbol(int *nivel, int cont1, int cont2);  // funcion para establecer el nivel del arbol
    void niveles(NodoBinario * p, int nivel, int nivelaux, int aux, Lista l[]); // funcion para insertar los niveles del arbol en listas
    void sumarNivel(Lista l);   // funcion para sumar los elementos de los niveles del arbol
    void impresionNiveles(Lista a[], int n);    // funcion para imprimir los niveles con la suma

    leerAB(&a);
    cout << endl
         << "ARBOL BINARIO" << endl;
    a.imprimirIDN(a.getRaiz());
    cont1 = contarNodosIzquierdos(a.getRaiz());
    cont2 = contarNodosDerechos(a.getRaiz());
    nivelArbol(&nivel, cont1, cont2);
    cout << endl
         << "Nivel del arbol: " << nivel << endl;
    Lista *m;
    m = new Lista[nivel];
    niveles(a.getRaiz(), 0, 0, aux, m);
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
        return 1 + contarNodosIzquierdos(p->getIzq());  // cuenta nodos izquierdos
    }
    else
        return 0;
}

int contarNodosDerechos(NodoBinario *p)
{
    if (p != NULL)
    {
        return 1 + contarNodosDerechos(p->getDer());    // cuenta nodos derechos
    }
    else
        return 0;
}
void nivelArbol(int *nivel, int cont1, int cont2)
{
    if (cont1 > cont2)
    {
        *nivel = cont1; // si nodos izquierdos son mayores, ese es el nivel
    }
    else
        *nivel = cont2; // si nodos derechos son mayores, ese es el nivel
}
void niveles(NodoBinario *p, int nivel, int nivelaux, int aux, Lista l[])
{
    if (p == NULL)
    {
        return;
    }
    if (nivel == nivelaux)
    {
        l[nivel].insertarEnOrden(p->getDato()); // inserta en una lista los elementos de cada nivel
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
        aux += actual->getDato();   // suma los elementos de cada lista
        actual = actual->getPunt();
    }
    l.insertarNodoFinal(aux);   // inserta esa suma al final
}
void impresionNiveles(Lista a[], int n)
{
    Lista m;    // lista de sumas
    cout << endl;
    Nodo *actual; // referencia a nodo actual de la lista
    for (int i = 0; i < n; i++)
    {
        sumarNivel(a[i]);   // suma los elementos de cada lista
        m.insertarEnOrden(a[i].ultimoNodo()->getDato());    // inserta esa suma en una lista
    }
    for (int i = 0; i < n; i++)
    {
        cout << "[ ";
        for (int j = 0; j < n; j++)
        {
            if (a[j].ultimoNodo()->getDato() == m.ultimoNodo()->getDato())  // si la suma (que esta en el ultimo nodo de cada lista) coincide con el ultimo nodo de la lista de sumas
            {
                a[j].eliminarNodo(a[j].ultimoNodo()->getDato());    // se elimina nodo de suma para no imprimirlo
                actual = a[j].getPrimero(); // almacena temporalmente la posicion del primer nodo
                while (actual != NULL)
                {
                    cout << actual->getDato() << " ";
                    actual = actual->getPunt();
                }
            }
        }
        cout << "]: "<<m.ultimoNodo()->getDato()<<endl; // se imprime la suma del nivel
        m.eliminarNodo(m.ultimoNodo()->getDato());  // se elimina la suma de la lista de listas
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