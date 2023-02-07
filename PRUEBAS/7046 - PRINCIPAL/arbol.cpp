// Sumar los elementos de las ramas de un arbol binario y realizar la diferencia entre el valor mayor y el valor menor

#include <iostream>
using namespace std;
#include "ArbolBinario.h"
#include "lista.h"

int main()
{
    ArbolBinario a;
    int n = 0, r = 0;
    Lista m;

    void leerAB(ArbolBinario * a);                             // funcion para ingresar un arbol binario
    void ramas(NodoBinario * p, Lista l, int *n, Lista m[]);   // guarda las ramas del AB en listas
    void contarRamas(NodoBinario * p, int *n);                 // cuenta las ramas del AB
    void obtenerRamas(NodoBinario * p, int *n, Lista l[]);     // guarda las ramas del AB en listas
    void loopSuma(Lista l, Lista * m, Nodo * actual, int sum); // funcion para obtener las sumas de las ramas
    void sumaRamas(Lista l[], Lista * m, int n);               // funcion para guardar las sumas en una lista
    void impresionRamas(Lista a[], int n);                     // imprime las ramas del AB
    void impresion(Lista a[], int n);                          // imprime las ramas del AB

    cout << endl
         << "INGRESO ARBOL BINARIO" << endl;
    leerAB(&a);
    cout << endl
         << "ARBOL BINARIO" << endl;
    a.imprimirABJerarquia(a.getRaiz(), 0);

    contarRamas(a.getRaiz(), &r);
    Lista l[r - 1];
    obtenerRamas(a.getRaiz(), &n, l);
    impresionRamas(l, n);
    sumaRamas(l, &m, r - 1);

    int d = m.ultimoNodo()->getDato() - m.getPrimero()->getDato();
    cout << "Diferencia: " << m.ultimoNodo()->getDato() << " - " << m.getPrimero()->getDato() << " = " << d << endl
         << endl;

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

void ramas(NodoBinario *p, Lista l, int *n, Lista m[])
{
    if (p == NULL)
    {
        return;
    }
    l.insertarNodoInicio(p->getDato()); // insertar nodo de rama en lista
    if (p->getIzq() == NULL && p->getDer() == NULL)
    {
        m[*n] = l; // guardar lista
        *n += 1;   // aumentar posicion
    }
    else
    {
        ramas(p->getIzq(), l, n, m); // recorrer subarbol izquierdo
        ramas(p->getDer(), l, n, m); // recorrer subarbol derecho
    }
}

void obtenerRamas(NodoBinario *p, int *n, Lista l[])
{
    Lista m;
    ramas(p, m, n, l);
}

//==================================================================================================

void impresionRamas(Lista a[], int n)
{
    cout << endl;
    // recorrido de la lista
    Nodo *actual; // referencia a nodo actual de la lista
    for (int i = 0; i < n; i++)
    {
        cout << "RAMA " << i + 1 << ":" << endl;
        actual = a[i].getPrimero(); // almacena temporalmente la posicion del primer nodo
        cout << "[ ";
        while (actual != NULL)
        {
            cout << actual->getDato() << " ";
            actual = actual->getPunt();
        }
        cout << "]" << endl;
    }
    cout << endl;
}

void contarRamas(NodoBinario *p, int *n)
{
    if (p == NULL)
    {
        return;
    }
    if (p->getIzq() == NULL && p->getDer() == NULL) // cuando llega al final de una rama
    {
        *n = *n + 1; // cuenta + 1
    }
    else
    {
        contarRamas(p->getIzq(), n); // recorrer subarbol izquierdo
        contarRamas(p->getDer(), n); // recorrer subarbol derecho
    }
}

void loopSuma(Lista l, Lista *m, Nodo *actual, int sum) // funcion para obtener las sumas de las ramas
{
    if (actual != NULL)
    {
        sum += actual->getDato(); // suma elementos de la lista
        loopSuma(l, m, actual->getPunt(), sum);
    }
    else
    {
        m->insertarEnOrden(sum); // inserta la suma en una lista
    }
}

void sumaRamas(Lista l[], Lista *m, int n)
{
    if (n >= 0)
    {
        sumaRamas(l, m, n - 1);                  // recorrido de listas[]
        loopSuma(l[n], m, l[n].getPrimero(), 0); // obteniendo suma de cada rama
    }
}