// 1 matriz 2 lista 3 matriz 4 lista
// vertices y arcos contenidas en los demas grafos
// RESPUESTA A
// RESPUESTA B
// RESPUESTA C
// RESPUESTA D

#include "Grafo.h"
#include "utilidades.h"

int main()
{
    int n; // cantidad de grafos

    GrafoLista ingresarVertices(int n1);
    GrafoMatriz ingresarVertices2(int n1);
    void ingresarArcos(GrafoLista * g);
    void ingresarArcos2(GrafoMatriz * h);
    void imprimirGrafo(GrafoLista g);                            // prototipo de la funcion que presenta los vertices del grafo
    void imprimirGrafo2(GrafoMatriz g);                          // prototipo de la funcion que presenta los vertices del grafo
    void ingresarGrafos(GrafoLista g[], GrafoMatriz h[], int n); // prototipo de la funcion que presenta los vertices del grafo
    void imprimirGrafos(GrafoLista g[], GrafoMatriz h[], int n); // prototipo de la funcion que presenta los vertices de todos los grafos ingresados
    void compararGrafos(GrafoLista g[], GrafoMatriz h[], int n, ListaG lg[]); // prototipo de la funcion que compara vertices y arcos de grafos
    ListaG vertices(GrafoLista g);
    ListaG vertices2(GrafoMatriz g);

    cout << "CANTIDAD DE GRAFOS N: ";
    cin >> n;
    GrafoLista g[n];         // vector de grafo lista
    GrafoMatriz h[n];        // vector de grafo matriz
    ingresarGrafos(g, h, n); // ingreso de grafos
    imprimirGrafos(g, h, n); // impresion de grafos
    cout << endl;
    cout << endl;
    system("pause");
}

GrafoLista ingresarVertices(int n1)
{ // funcion que ingresa los datos de los v�rtices de un grafo
    string aux;
    GrafoLista a(n1);
    for (int i = 0; (i < n1); i++)
    {
        cout << endl
             << "Ingrese el nombre del vertice No. " << (i + 1) << ": ";
        getline(cin, aux);
        a.nuevoVertice(aux);
    }
    return a;
}

GrafoMatriz ingresarVertices2(int n1)
{ // funcion que ingresa los datos de los v�rtices de un grafo
    string aux;
    GrafoMatriz a(n1);

    for (int i = 0; (i < n1); i++)
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

void ingresarArcos2(GrafoMatriz *g)
{ // funcion que ingresa los datos de los arcos de un grafo incluido peso
    int nv = g->getNumVerts();
    int na;
    int peso; // peso del arco
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
            g->setArco(x.getNombre(), aux, 1);
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
             << "Vertice No. " << x.getNumero() + 1 << " - " << x.getNombre() << " - ";

        for (int j = 0; (j < nv); j++)
        {
            if (g.adyacente(i, j))
            {
                Vertice x = g.getVertice(j);
                cout << endl
                     << "\t\t--->" << x.getNombre();
            }
        }
    }
    cout << endl
         << "===============================================";
    cout << endl;
}

void imprimirGrafo2(GrafoMatriz g)
{ // funcion que presenta los datos del grafo
    int nv = g.getNumVerts();
    int na;
    string aux;
    cout << endl
         << "===============================================";
    cout << endl
         << "M A T R I Z    D E    A D Y A C E N C I A";

    for (int i = 0; (i < nv); i++)
    {
        Vertice x = g.getVertice(i);
        cout << endl
             << "Vertice No. " << x.getNumero() + 1 << " - " << x.getNombre() << " - ";

        for (int j = 0; (j < nv); j++)
        {
            if (g.adyacente(i, j))
            {
                Vertice x = g.getVertice(j);
                cout << endl
                     << "\t\t--->" << x.getNombre();
            }
        }
    }
    cout << endl
         << "===============================================";
    cout << endl;
}

void ingresarGrafos(GrafoLista g[], GrafoMatriz h[], int n)
{
    int x = 0, // var aux
        j = 0, // var aux grafo lista
        k = 0; // var aux grafo matriz
    for (int i = 0; i < n; i++)
    {
        x = 0;
        if (i % 2 != 0) // control para que el segundo grafo sea de lista de adyacencia
        {
            cout << endl
                 << "CANTIDAD DE VERTICES DEL GRAFO " << i + 1 << " CON LISTA" << endl;
            x = leerN(1, 20); // lectura de cantidad de vertices del grafo
            cin.ignore();
            // se ingresa en la posicion j de vector grafo lista
            g[j] = ingresarVertices(x); // llamado a funcion de ingreso de los datos referentes al grafo
            ingresarArcos(&g[j]);       // llamado a la funcion que ingresa los arcos del grafo
            j++;
        }
        else
        {
            cout << endl
                 << "CANTIDAD DE VERTICES DEL GRAFO " << i + 1 << " CON MATRIZ" << endl;
            x = leerN(1, 20); // lectura de cantidad de vertices del grafo
            cin.ignore();
            // se ingresa en la posicion k de vector grafo matriz
            h[k] = ingresarVertices2(x); // llamado a funcion de ingreso de los datos referentes al grafo
            ingresarArcos2(&h[k]);       // llamado a la funcion que ingresa los arcos del grafo
            k++;
        }
    }
}

void imprimirGrafos(GrafoLista g[], GrafoMatriz h[], int n)
{
    int l = 0,
        m = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "GRAFO " << i + 1 << endl;
        if (i % 2 != 0) // control para que el segundo grafo sea de lista de adyacencia
        {
            imprimirGrafo(g[l]);
            l++;
        }
        else
        {
            imprimirGrafo2(h[m]);
            m++;
        }
    }
}

void compararGrafos(GrafoLista g[], GrafoMatriz h[], int n, ListaG lg[]) // prototipo de la funcion que compara vertices y arcos de grafos
{
    int l = 0,
        m = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "COMPARACION GRAFO " << i + 1 << endl;
        if (i % 2 != 0) // control para que el segundo grafo sea de lista de adyacencia
        {
            l++;
        }
        else
        {
            m++;
        }
    }
}

ListaG vertices(GrafoLista g)
{
    int nv = g.getNumVerts();
    ListaG l;
    for (int i = 0; (i < nv); i++)
    {
        Vertice x = g.getVertice(i);
        l.insertarAlFinal(x.getNumero());
    }
    return l;
}

ListaG vertices2(GrafoMatriz g)
{
    int nv = g.getNumVerts();
    ListaG l;
    for (int i = 0; (i < nv); i++)
    {
        Vertice x = g.getVertice(i);
        l.insertarAlFinal(x.getNumero());
    }
    return l;
}

ListaG verticesTotales(int n, GrafoLista g[], GrafoMatriz h[])
{
    int l = 0,
        m = 0;
    ListaG lg[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; i++)
        {
            if (i % 2 != 0) // control para que el segundo grafo sea de lista de adyacencia
            {
                lg[i] = vertices(g[l]);
                
            }
            else
            {
                lg[i] = vertices2(h[m]);
                m++;
            }
        }
    }
    return lg[n];
}