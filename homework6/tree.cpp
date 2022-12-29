// Genere una lista que contenga los elementos de la rama más larga del ABB.
// Si hubiera varias ramas con la misma profundidad, la lista contendría los elementos de una cualquiera de ellas
#include "ArbolBinario.h"
#include "lista.h"

int main()
{                                  // programa principal
    ArbolBinario a;                // declara un Arbol binario
    void leerAB(ArbolBinario * b); // prototipo de funcion ingreso AB
    void contarRamas(NodoBinario * p, int *n);
    void obtenerRamas(NodoBinario * p, int *n, Lista l[]);
    void ramas(NodoBinario * p, Lista l, int *n, Lista m[]);
    void impresionRamas(Lista a[], int n);
    int contarElementos(Lista l);
    void obtenerRamaLarga(Lista a[], int n);
    int n = 0, r = 0;
    leerAB(&a); // llamado a funcion de ingreso AB
    contarRamas(a.getRaiz(), &r);
    a.imprimirABJerarquia(a.getRaiz(), 0);
    Lista m[r - 1];
    obtenerRamas(a.getRaiz(), &n, m);
    cout << "RAMAS DEL ARBOL" << endl;
    impresionRamas(m, n);
    cout << endl;
    obtenerRamaLarga(m,n);
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
        contarRamas(p->getIzq(), n); // recorrer subarbol izquierdo
        contarRamas(p->getDer(), n); // recorrer subarbol derecho
    }
}

//==================================================================================================

int contarElementos(Lista l)
{
    int i = 0;
    Nodo *actual;
    actual = l.getPrimero();
    while (actual != NULL)
    {
        i++;
        actual = actual->getPunt();
    }
    return i;
}

//==================================================================================================

void ramas(NodoBinario *p, Lista l, int *n, Lista m[])
{
    if (p == NULL)
    {
        return;
    }
    l.insertarNodoInicio(p->getDato()); // insertar nodo de rama en lista
    if (p->getIzq() == NULL && p->getDer() == NULL)
    {
        m[*n] = l; // guardar lista en vector
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
}

//==================================================================================================

void obtenerRamaLarga(Lista a[], int n)
{
    int x,y;
    Lista l,m,o;
    Nodo *actual;
    for (int i = 0; i < n; i++)
    {
        x = 0;
        x = contarElementos(a[i]);
        l.insertarNodoFinal(x);
    }
    x = 0;
    actual = l.getPrimero();
    while (x < n)
    {
        a[x].insertarNodoInicio(actual->getDato());
        actual = actual->getPunt();
        x++;
    }
    actual = l.getPrimero();
    while (actual != NULL)
    {
        m.insertarEnOrden(actual->getDato());
        actual = actual->getPunt();
    }
    cout << "RAMA MAS LARGA" << endl;
    for (int j = 0; j < n; j++)
    {   
        if (m.ultimoNodo()->getDato() == a[j].getPrimero()->getDato())
        {
            actual = a[j].getPrimero();
            actual = actual->getPunt();
            cout << "[ ";
            while (actual != NULL)
            {
                cout << actual->getDato() << " ";
                actual = actual->getPunt();
            }
            cout << "]" << endl;
            cout << endl;
        }
    }
}