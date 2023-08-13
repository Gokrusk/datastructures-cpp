// Ingresar un grafo, generar listas de los nodos de cada vértice, sumar elementos de las listas e imprimir el mayor
#include "Grafo.h"
#include "utilidades.h"

int main()
{
    GrafoLista g; // declara un grafo para manipular las clases
    int n;        // cantidad de vertices a crear

    GrafoLista ingresarVertices(int n);
    void ingresarArcos(GrafoLista * g); // funcion que ingresa los datos de los arcos de un grafo
    void imprimirGrafo(GrafoLista g);   // prototipo de la funcion que presenta los vertices del grafo
    void crearListaG(ListaG l[], GrafoLista g);
    void imprimirLista(ListaG l[], GrafoLista g);
    void mayorSumaNodos(ListaG l[], int n);

    cout << endl
         << "CANTIDAD DE VERTICES DEL GRAFO" << endl;
    n = leerN(1, 20); // lectura de cantidad de vertices del grafo
    cin.ignore();

    g = ingresarVertices(n); // llamado a funcion de ingreso de los
    ingresarArcos(&g);
    imprimirGrafo(g);

    ListaG l[n - 1];

    crearListaG(l, g);
    imprimirLista(l, g);
    cout << endl;
    mayorSumaNodos(l, g.getNumVerts());
    system("pause");
}

GrafoLista ingresarVertices(int n)
{ // funcion que ingresa los datos de los v�rtices de un grafo
    string aux;
    GrafoLista a(n);

    for (int i = 0; i < n; i++)
    {
        cout << endl
             << "Ingrese el nombre del vertice No. " << (i + 1) << ": ";
        getline(cin, aux);
        a.nuevoVertice(aux);
    }
    return a;
}

void ingresarArcos(GrafoLista *g)
{ // funcion que ingresa los datos de los arcos de un grafo
    int nv = g->getNumVerts();
    int na;
    string aux;

    for (int i = 0; (i < nv); i++)
    {
        Vertice x = g->getVertice(i);
        cout << endl
             << "Vertice No. " << x.getNumero() + 1 << " - " << x.getNombre() << " - ";
        cout << endl
             << "CANTIDAD DE ARCOS DE SALIDA DEL VERTICE" << endl;
        na = leerN(0, 10);
        cin.ignore();

        for (int j = 0; (j < na); j++)
        {
            cout << endl
                 << "Identificador del Vertice Destino: ";
            getline(cin, aux);
            g->setArco(x.getNombre(), aux);
        }
    }
}

void imprimirGrafo(GrafoLista g)
{ // funcion que presenta los datos del grafo
    int nv = g.getNumVerts();
    int na;
    string aux;
    cout << endl
         << "===============================================";
    cout << endl
         << "L I S T A    D E    A D Y A C E N C I A";

    for (int i = 0; (i < nv); i++)
    {
        Vertice x = g.getVertice(i);
        cout << endl
             << "Vertice No. " << x.getNumero() + 1 << " - " << x.getNombre();

        for (int j = 0; (j < nv); j++)
        {
            if (g.adyacente(i, j))
            {
                Vertice x = g.getVertice(j);
                cout << endl
                     << "\t\t--->" << x.getNumero() + 1;
            }
        }
    }
    cout << endl
         << "===============================================";
    cout << endl;
}

void imprimirLista(ListaG l[], GrafoLista g)
{
    for (int i = 0; i < g.getNumVerts(); i++)
    {
        NodoG *actual;
        cout << endl;
        cout << "Vertice " << g.getVertice(i).getNumero() + 1 << ": ";
        actual = l[i].getPrimero();
        cout << "[ ";
        while (actual != NULL)
        {
            cout << actual->getDato() << " ";
            actual = actual->getPunt();
        }
        cout << "]" << endl;
    }
}

void crearListaG(ListaG l[], GrafoLista g)
{
    int n = g.getNumVerts();
    cout << "LISTAS DE NODOS DE CADA VÉRTICE" << endl;
    for (int i = 0; i < n; i++)
    {
        l[i].anula();
    }
    for (int i = 0; (i < n); i++)
    {
        Vertice x = g.getVertice(i);
        for (int j = 0; (j < n); j++)
        {
            if (g.adyacente(i, j))
            {
                Vertice x = g.getVertice(j);
                l[i].insertarEnOrden(x.getNumero() + 1);
            }
        }
    }
    cout << endl;
}

void mayorSumaNodos(ListaG l[], int n)
{
    ListaG m;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        NodoG *actual;
        actual = l[i].getPrimero();
        while (actual != NULL)
        {
            sum += actual->getDato();
            actual = actual->getPunt();
        }
        m.insertarEnOrden(sum);
    }
    cout << "La suma mayor de nodos: " << m.ultimoValorDeLista()->getDato() << endl;
}