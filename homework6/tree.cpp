// Genere una lista que contenga los elementos de la rama más larga del ABB.
// Si hubiera varias ramas con la misma profundidad, la lista contendría los elementos de una cualquiera de ellas
//  Obtener la imagen especular de un ABB previamente ingresado (reflejo respecto al eje vertical)
#include "ArbolBinario.h"
#include "lista.h"

int main()
{                                  // programa principal
    ArbolBinario a;                // declara un Arbol binario
    void leerAB(ArbolBinario * b); // prototipo de funcion ingreso AB
    void contarRamas(NodoBinario * p, int *n);
    void imprimirRamas(Lista l, int d, int *n);
    void printPaths(NodoBinario * p, int *n);
    void ramas(NodoBinario * p, Lista l, int d, int *n);
    Lista l;
    int n = 0, r = 0;
    leerAB(&a); // llamado a funcion de ingreso AB
    contarRamas(a.getRaiz(), &r);
    Lista m[r-1];
    a.imprimirABJerarquia(a.getRaiz(), 0);
    printPaths(a.getRaiz(), &n);
    cout << endl;
    system("pause");
}

//==================================================================================================

void leerAB(ArbolBinario *b)
{
    int v;
    cout << endl
         << "LECTURA DE ARBOL BINARIO" << endl
         << endl;
    cin >> v;
    if (v != 999)
    {
        b->insertarNodo(v);
        leerAB(b);
    }
}

//==================================================================================================

void imprimirRamas(Lista l, int d, int *n)
{
    int i = 0;
    Nodo *actual;
    actual = l.getPrimero();
    cout << "[ ";
    while (i < d)
    {
        cout << actual->getDato() << " ";
        actual = actual->getPunt();
        i++;
    }
    cout << "] " << i << endl;
    *n = *n + 1;
}

void ramas(NodoBinario *p, Lista l, int d, int *n)
{
    if (p == NULL)
    {
        return;
    }

    /* append this node to the path array */
    l.insertarNodoInicio(p->getDato());
    d++;
    if (p->getIzq() == NULL && p->getDer() == NULL)
    {
        imprimirRamas(l, d, n);
    }
    else
    {
        /* otherwise try both subtrees */
        ramas(p->getIzq(), l, d, n);
        ramas(p->getDer(), l, d, n);
    }
}

//==================================================================================================

void printPaths(NodoBinario *p, int *n)
{
    Lista l;
    ramas(p, l, 0, n);
}

void contarRamas(NodoBinario *p, int *n)
{
    if (p == NULL)
    {
        return;
    }

    if (p->getIzq() == NULL && p->getDer() == NULL)
    {
        *n = *n + 1;
    }
    else
    {
        /* otherwise try both subtrees */
        contarRamas(p->getIzq(), n);
        contarRamas(p->getDer(), n);
    }
}