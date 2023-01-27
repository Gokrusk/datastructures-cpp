// Resolver este requerimiento: Una persona quiere recorrer un museo.
// Su idea es hacer un recorrido bastante lógico: empezar en una sala (al azar),
// luego ir a una adyacente a ésta, luego a una adyacente a la segunda (si no fue visitada aún),
// y así hasta recorrer todas las salas. Cuando no tiene más salas adyacentes para visitar
//(porque ya fueron todas visitadas), simplemente vuelve por donde vino buscando otras salas adyacentes.
// Teniendo un grafo que representa el mapa del museo (donde los vértices son salas, y los arcos (v, w)
// indican que las salas v y w se encuentran conectadas). Implementar un programa que devuelva una
// lista con un recorrido posible de la idea de aquella persona para visitar las salas del museo.

#include "Grafo.h"
#include "utilidades.h"
#include "CaminoMinimo.h"

int main()
{
    GrafoMatriz g;
    int n; // cantidad de vertices a crear

    GrafoMatriz ingresarVertices(int n1);
    ListaG listaVisita(GrafoMatriz g);
    void ingresarArcos(GrafoMatriz * g); // a�ade arcos => grafos valorados
    void imprimirGrafo(GrafoMatriz g);   // prototipo de la funcion que presenta los vertices del grafo
    void imprimirLista(ListaG l, GrafoMatriz g);
    void recorrerGrafo(GrafoMatriz g);

    cout << endl
         << "CANTIDAD DE VERTICES DEL GRAFO" << endl;
    n = leerN(1, 20); // lectura de cantidad de vertices del grafo
    cin.ignore();
    ListaG l;
    g = ingresarVertices(n); // llamado a funcion de ingreso de los datos referentes al grafo
    ingresarArcos(&g);       // llamado a la funcion que ingresa los arcos del grafo
    imprimirGrafo(g);        // llamado a la funcion que imprime la matriz de adyacencia
    cout << endl;
    //recorrerGrafo(g);
    l = listaVisita(g);
    imprimirLista(l, g);
    cout << endl;
    system("pause");
}

GrafoMatriz ingresarVertices(int n1)
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

void ingresarArcos(GrafoMatriz *g)
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

void imprimirGrafo(GrafoMatriz g)
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

void imprimirLista(ListaG l, GrafoMatriz g) // recorrido de la lista
{
    NodoG *actual;            // referencia al nodo actual de la lista
    actual = l.getPrimero(); // almacenar temporalmente la posición del primer nodo de la lista

    while (actual != NULL) // repetir mientras no se alacance el final de la lista
    {
        cout << " " << g.getVertice(actual->getDato()).getNombre();
        actual = actual->getPunt(); // desplaza el puntero actual al siguiente nodo
    }
    cout <<endl;
}

void buscarAnterior(ListaG *l, GrafoMatriz g)
{
    ListaG aux;
    NodoG *val;

    val = l->getPrimero();

    while (val != NULL)
    {
        aux.insertarAlFinal(val->getDato());
        val = val->getPunt();
    }

    while (true)
    {
        aux.eliminarNodoDeLista(aux.ultimoValorDeLista()->getDato());

        l->insertarAlFinal(aux.ultimoValorDeLista()->getDato());

        for (int i = 1; i < g.getNumVerts(); i++)
        {
            if (g.adyacente(aux.ultimoValorDeLista()->getDato(), i) && l->buscarValorEnLista(i) == NULL)
                return;
        }
    }
}
ListaG listaVisita(GrafoMatriz g)
{
    ListaG visita;
    NodoG *aux;
    int r = rand()%g.getNumVerts();
    visita.insertarAlFinal(r);

    int con = 1;

    aux->setDato(r);

    for (int i = 0; i < g.getNumVerts(); i++)
    {
        if (g.adyacente(aux->getDato(), i) && visita.buscarValorEnLista(i) == NULL)
        {
            con++;
            visita.insertarAlFinal(i);
            aux->setDato(i);
            i = 1;
        }

        if (i == g.getNumVerts() - 1)
        {
            buscarAnterior(&visita, g);
            aux->setDato(visita.ultimoValorDeLista()->getDato());

            i = 0;
        }

        if (con == g.getNumVerts())
            break;
    }
    return visita;
}
void recorrerGrafo(GrafoMatriz g)
{
    cout<<"RECORRIDO DE SALAS"<<endl;
    CaminoMinimo x(g,rand()%g.getNumVerts());
    x.Recorrer(g);
}

// int r = rand()%g.getNumVerts();	//genera un valor aleatorio entre 0 y numVertices