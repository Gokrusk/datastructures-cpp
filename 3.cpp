#include "GrafoLista.h"
#include "GrafoMatriz.h"
#include "utilidades.h"
int main()
{
    void ingresarArcosLista(GrafoLista * g);
    void ingresarArcosMatriz(GrafoMatriz * g);
    void comprobarSubGrafo(GrafoMatriz gM[], GrafoLista gL[], int numM, int numL);
    GrafoLista ingresarVerticesLista(int n1);
    GrafoMatriz ingresarVerticesMatriz(int n1);
    int n, n1, n2; // cantidad total de grafos, cant grafos matriz y lista
    int numMat, numList;
    cout << endl
         << "Cantidad total de grafos a procesar: ";
    n = leerN(2, 30);
    numList = n / 2;
    numMat = n - numList;
    GrafoMatriz gM[numMat];
    GrafoLista gL[numList];
    int k = 0, j = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            cout << "\nINGRESO GRAFO MATRIZ\n";
            cout << "\nCANTIDAD DE VERTICES DEL GRAFO";
            n1 = leerN(1, 20); // lectura de cantidad de vertices del grafo
            cin.ignore();
            gM[j] = ingresarVerticesMatriz(n1);
            ingresarArcosMatriz(&gM[j]);
            j++;
        }
        else
        {
            cout << "\nINGRESO GRAFO LISTA\n";
            cout << "\nCANTIDAD DE VERTICES DEL GRAFO";
            n2 = leerN(1, 20); // lectura de cantidad de vertices del grafo
            cin.ignore();
            gL[k] = ingresarVerticesLista(n2);
            ingresarArcosLista(&gL[k]);
            k++;
        }
    }
    j = 0;
    k = 0;
    comprobarSubGrafo(gM, gL, numMat, numList);
}
void comprobarSubGrafo(GrafoMatriz gM[], GrafoLista gL[], int numM, int numL)
{
    bool comprobarGM(GrafoMatriz g1, GrafoMatriz g2);
    bool comprobarGML(GrafoMatriz g1, GrafoLista g2);
    bool comprobarGLM(GrafoLista g1, GrafoMatriz g2);
    bool comprobarGL(GrafoLista g1, GrafoLista g2);
    int total = numM + numL;
    int pos = 0;
    for (int i = 0; i < numM; i++)
    { // ciclo grafos matriz
        cout << "\nGrafo matriz " << i << " ";
        for (int j = 0; j < numM; j++)
        {
            if (i != j)
            { // no es el mismo grafo
                if (comprobarGM(gM[i], gM[j]))
                {
                    cout << " SI es subgrafo del grafo matriz " << j;
                }
                else
                {
                    cout << " NO es subgrafo del grafo matriz " << j;
                }
            }
        }
        for (int j = 0; j < numL; j++)
        { // ciclo grafos lista
            if (comprobarGML(gM[i], gL[j]))
            {
                cout << " SI es subgrafo del grafo lista " << j;
            }
            else
            {
                cout << " NO es subgrafo del grafo lista " << j;
            }
        }
    }
    for (int i = 0; i < numL; i++)
    { // ciclo grafos lista
        cout << "\nEl grafo lista " << i << " ";
        for (int j = 0; j < numM; j++)
        { // recorre grafos matriz
            if (comprobarGLM(gL[i], gM[j]))
            {
                cout << " SI es subgrafo del grafo matriz " << j;
            }
            else
            {
                cout << " NO es subgrafo del grafo matriz " << j;
            }
        }
        for (int j = 0; j < numL; j++)
        { // ciclo grafos lista
            if (i != j)
            { // que no sea la misma matriz
                if (comprobarGL(gL[i], gL[j]))
                {
                    cout << " SI es subgrafo del grafo lista " << j;
                }
                else
                {
                    cout << " NO es subgrafo del grafo lista " << j;
                }
            }
        }
    }
}
bool comprobarGM(GrafoMatriz g1, GrafoMatriz g2)
{ // funcion para comprobar si es subgrafo
    int n1 = g1.getNumVerts();
    int n2 = g2.getNumVerts();
    int comp = 0;
    int numVert[n1];
    if (n1 <= n2)
    {
        for (int i = 0; i < n2; i++)
        {
            for (int j = 0; j < n1; j++)
            {
                if (g1.getVertice(i).getNombre() == g2.getVertice(j).getNombre())
                { // iguales
                    nombres
                        numVert[comp] = i;
                    comp++;
                    break;
                }
            }
        }
        if (comp == n1)
        {
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n1; j++)
                {
                    if (g1.adyacente(numVert[i], numVert[j]))
                    {
                        if (!g2.adyacente(numVert[i], numVert[j]))
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool comprobarGML(GrafoMatriz g1, GrafoLista g2)
{ // comprobar entre grafo matriz y lista
    int n1 = g1.getNumVerts();
    int n2 = g2.getNumVerts();
    int comp = 0;
    int numVert[n1];
    if (n1 <= n2)
    {
        for (int i = 0; i < n2; i++)
        {
            for (int j = 0; j < n1; j++)
            {
                if (g1.getVertice(i).getNombre() == g2.getVertice(j).getNombre())
                {
                    numVert[comp] = i;
                    comp++;
                    break;
                }
            }
        }
        if (comp == n1)
        {
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n1; j++)
                {
                    if (g1.adyacente(numVert[i], numVert[j]))
                    {
                        if (!g2.adyacente(numVert[i], numVert[j]))
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool comprobarGLM(GrafoLista g1, GrafoMatriz g2)
{ // comprueba entre grafo lista y matriz
    int n1 = g1.getNumVerts();
    int n2 = g2.getNumVerts();
    int comp = 0;
    int numVert[n1];
    if (n1 <= n2)
    {
        for (int i = 0; i < n2; i++)
        {
            for (int j = 0; j < n1; j++)
            {
                if (g1.getVertice(i).getNombre() == g2.getVertice(j).getNombre())
                {
                    numVert[comp] = i;
                    comp++;
                    break;
                }
            }
        }
        if (comp == n1)
        {
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n1; j++)
                {
                    if (g1.adyacente(numVert[i], numVert[j]))
                    {
                        if (!g2.adyacente(numVert[i], numVert[j]))
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool comprobarGL(GrafoLista g1, GrafoLista g2)
{ // comprobar grafos lista
    int n1 = g1.getNumVerts();
    int n2 = g2.getNumVerts();
    int comp = 0;
    int numVert[n1];
    if (n1 <= n2)
    {
        for (int i = 0; i < n2; i++)
        {
            for (int j = 0; j < n1; j++)
            {
                if (g1.getVertice(i).getNombre() == g2.getVertice(j).getNombre())
                {
                    numVert[comp] = i;
                    comp++;
                    break;
                }
            }
        }
        if (comp == n1)
        {
            for (int i = 0; i < n1; i++)
            {
                for (int j = 0; j < n1; j++)
                {
                    if (g1.adyacente(numVert[i], numVert[j]))
                    {
                        if (!g2.adyacente(numVert[i], numVert[j]))
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
GrafoLista ingresarVerticesLista(int n1)
{ // funcion que ingresa los datos de los vertices de un grafo
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
void ingresarArcosLista(GrafoLista *g)
{ // funcion que ingresa los datos de los arcos de un grafo
    int nv = g->getNumVerts();
    int na;
    string aux;
    for (int i = 0; i < nv; i++)
    {
        Vertice x = g->getVertice(i);
        cout << endl
             << "Vertice No. " << x.getNumero() + 1 << " => " << x.getNombre();
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
    GrafoMatriz ingresarVerticesMatriz(int n1)
    { // funcion que ingresa los datos de los vertices de un grafo
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
    void ingresarArcosMatriz(GrafoMatriz * g)
    { // funcion que ingresa los datos de los arcos de un grafo
        int nv = g->getNumVerts();
        int na;
        string aux;
        for (int i = 0; i < nv; i++)
        {
            Vertice x = g->getVertice(i);
            cout << endl
                 << "Vertice No. " << x.getNumero() + 1 << " => " << x.getNombre();
            cout << endl
                 << "CANTIDAD DE ARCOS DE SALIDA DEL VERTICE" << endl;
            na = leerN(0, 10);
            cin.ignore();
            for (int j = 0; (j < na); j++)
            {
                cout << "Identificador del Vertice Destino: ";
                getline(cin, aux);
                g->setArco(x.getNombre(), aux);
            }
        }
    }