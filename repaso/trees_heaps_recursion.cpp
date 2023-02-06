// Guardar un árbo en un heap y viceversa

#include <iostream>
using namespace std;
#include "ArbolBinario.h"
#include "monticulo.h"
#include "lista.h"

int main()
{
    ArbolBinario a;
    int n = 0, n1 = 0;

    void leerAB(ArbolBinario * a);                                               // funcion para ingresar un arbol binario
    void ingresarMonticulo(NodoBinario * p, int nivel, int nivelaux, Lista l[]); // funcion recurisva para obtener nodos de un arbol
    void imprimirMonticulo(Monticulo m, int n);                                  // funcion que imprime un monticulo
    void ordenarMonticulo(Monticulo * m, Monticulo m1, int n);                   // funcion recursiva para ordenar un monticulo
    void loopInsercion(Monticulo * m, Lista l[], int n);                         // funcion recursiva para insertar nodos de arbol en monticulo
    void impresionNiveles(Lista a[], int n);                                     // funcion para imprimir los niveles con la suma

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
         << "INGRESO DE ELEMENTOS EN UN MONTICULO" << endl;
    ingresarMonticulo(a.getRaiz(), 0, 0, v);
    loopInsercion(&m, v, a.calcularAltura(a.getRaiz()));
    // ordenarMonticulo(&m, m1, m.getNumDatosAct());
    imprimirMonticulo(m, m.getNumDatosAct());
    impresionNiveles(v,a.calcularAltura(a.getRaiz()));
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
    if (n > 0)
    {
        imprimirMonticulo(m, n - 1);
        cout << endl
             << "Valor obtenido del Monticulo: " << m.getValor(n)<<endl;
    }
}

void impresionNiveles(Lista a[], int n)
{
    Nodo *actual; // referencia a nodo actual de la lista
    for (int j = 0; j < n; j++)
    {
        cout<<"NIVEL "<<j<<endl;
        cout << "[ ";
        actual = a[j].getPrimero(); // almacena temporalmente la posicion del primer nodo
        while (actual != NULL)
        {
            cout << actual->getDato() << " ";
            actual = actual->getPunt();
        }
        cout << "]"<<endl;
    }
}
