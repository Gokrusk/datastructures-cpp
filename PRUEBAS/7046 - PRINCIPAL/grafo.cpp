// Ingresar materias y estudiantes, mostrar materias con estudiantes matriculados. Los estudiantes no debem repetirse

#include "Grafo.h"
#include "utilidades.h"
#include "listaString.h"

int main()
{
    GrafoLista g; // declara un grafo para manipular las clases
    int n;        // cantidad de vertices a crear
    Lista e,m;

    GrafoLista ingresarVertices(int n1);
    void ingresarArcos(GrafoLista * g); // añade arcos => grafos no valorados
    void imprimirGrafo(GrafoLista g);   // prototipo de la funcion que presenta los vertices del grafo
    void ingresarMaterias(Lista *e);    // funcion para ingresar materias
    void ingresarEstudiantes(Lista *m); // funcion para ingresar estudiantes


    ingresarMaterias(&e);

    // cout << endl
    //      << "CANTIDAD DE VERTICES DEL GRAFO" << endl;
    // n = leerN(1, 20); // lectura de cantidad de vertices del grafo
    // cin.ignore();

    // g = ingresarVertices(n); // llamado a funcion de ingreso de los datos referentes al grafo
    // ingresarArcos(&g);       // llamado a la funcion que ingresa los arcos del grafo
    // imprimirGrafo(g);        // llamado a la funcion que imprime la matriz de adyacencia
    // cout << endl;
    system("pause");
}

GrafoLista ingresarVertices(int n1)
{ // funcion que ingresa los datos de los v�rtices de un grafo
    string aux;
    bool flag;
    GrafoLista a(n1);

    for (int i = 0; (i < n1); i++)
    {
        flag = false;
        cout << endl
             << "Ingrese el nombre del vertice No. " << (i + 1) << ": ";
        getline(cin, aux);
        for (int j = 0; j < a.getNumVerts(); j++)
        {
            Vertice x;
            x = a.getVertice(j);
            if (x.getNombre() == aux)
            {
                flag = true;
            }
        }
        if (!flag)
        {
            a.nuevoVertice(aux);
        }
        else
        {
            cout << "Ya existe el vertice" << endl;
            i--;
        }
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
            Vertice y = g->getVertice(aux);
            if (!g->adyacente(x.getNombre(), y.getNombre()))
            {
                g->setArco(x.getNombre(), aux);
            }
            else
            {
                cout << "Ya existe una conexion" << endl;
                j--;
            }
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
             << "Vertice No. " << x.getNumero() + 1 << " - " << x.getNombre() << " - "
             << "GRADO SALIDA: " << g.gradoSalida(i);

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

void ingresarMaterias(Lista *e, string x)    // funcion para ingresar materias
{
    string f = "999";
    cout << "Ingrese elemento: ";
    getline(cin, x);
    if (x != f)
    {
        e->insertarNodoFinal(x);
        ingresarMaterias(e, x);
    }
}

void ingresarEstudiantes(Lista *m, Tipo x) // funcion para ingresar estudiantes
{
    string f = "999";
    cout << "Ingrese elemento: ";
    getline(cin, x);
    if (x != f)
    {
        m->insertarNodoFinal(x);
        ingresarEstudiantes(m, x);
    }
}