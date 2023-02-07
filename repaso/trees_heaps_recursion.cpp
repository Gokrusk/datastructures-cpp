// Guardar elementos de un árbol en un heap y viceversa

#include <iostream>
using namespace std;
#include "ArbolBinario.h"
#include "monticulo.h"
#include "lista.h"

int main()
{
    ArbolBinario a;
    int n = 0;

    void leerAB(ArbolBinario * a);                                               // funcion para ingresar un arbol binario
    void ingresarMonticulo(NodoBinario * p, int nivel, int nivelaux, Lista l[]); // funcion recurisva para obtener nodos de un arbol
    void imprimirMonticulo(Monticulo m, int n);                                  // funcion que imprime un monticulo
    void loopInsercion(Monticulo * m, Lista l[], int n);                         // funcion recursiva para insertar nodos de arbol en monticulo

    cout << endl
         << "INGRESO ARBOL BINARIO" << endl;
    leerAB(&a);
    cout << endl
         << "ARBOL BINARIO" << endl;
    a.imprimirABJerarquia(a.getRaiz(), 0);

    n = a.contarNodos(a.getRaiz());
    Lista v[n];
    Monticulo m(n);

    cout << endl
         << "ELEMENTOS DE UN ARBOL EN UN MONTICULO" << endl;
    ingresarMonticulo(a.getRaiz(), 0, 0, v);
    loopInsercion(&m, v, a.calcularAltura(a.getRaiz()));
    imprimirMonticulo(m, 0);

    cout << endl<<endl;
    return 0;
}

void leerAB(ArbolBinario *a)
{
    NodoBinario *leerNodo(int margen);
    a->setRaiz(leerNodo(0));
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

void loopLista(Monticulo *m, Lista l, Nodo *actual)
{
    if (actual != NULL)
    {
        m->Insertar(actual->getDato());
        loopLista(m, l, actual->getPunt());
    }
}

void loopInsercion(Monticulo *m, Lista l[], int n)
{
    if (n >= 0)
    {
        loopInsercion(m, l, n - 1);
        loopLista(m, l[n], l[n].getPrimero());
    }
}

void ingresarMonticulo(NodoBinario *p, int nivel, int nivelaux, Lista l[]) // funcion recurisva para ingresar en un monticulo un arbol
{
    if (p != NULL)
    {
        if (nivel == nivelaux)
        {
            l[nivel].insertarEnOrden(p->getDato()); // inserta en una lista los elementos de cada nivel
            ingresarMonticulo(p->getIzq(), nivel + 1, nivelaux + 1, l);
            ingresarMonticulo(p->getDer(), nivel + 1, nivelaux + 1, l);
        }
    }
}

void imprimirMonticulo(Monticulo m, int n) // funcion que imprime un monticulo
{
    if (n < m.getNumDatosAct())
    {
        cout << endl
             << "Valor obtenido del Monticulo: " << m.getValor(n);
        imprimirMonticulo(m, n + 1);
    }
}
