//Genere una lista que contenga los elementos de la rama más larga del ABB. 
//Si hubiera varias ramas con la misma profundidad, la lista contendría los elementos de una cualquiera de ellas
// Obtener la imagen especular de un ABB previamente ingresado (reflejo respecto al eje vertical)
#include "ArbolBinario.h"
#include "lista.h"

int main()
{					// programa principal
	ArbolBinario a; // declara un Arbol binario
	void leerAB(ArbolBinario * b); // prototipo de funcion ingreso AB
    void imprimirRama(NodoBinario* p, int v[], int l);
    void printArray(int v[], int l);
    void printPaths(NodoBinario* p);
	Lista l;
	leerAB(&a); // llamado a funcion de ingreso AB
    a.imprimirABJerarquia(a.getRaiz(),0);
    printPaths(a.getRaiz());
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

void printArray(int v[], int l)
{
    int i;
    for (i = 0; i < l; i++)
    {
        cout << v[i] << " ";
    }
    cout<<endl;
}

void imprimirRama(NodoBinario* p, int v[], int l)
{
    if (p == NULL)
    {
        return;
    }
     
    /* append this node to the path array */
    v[l] = p->getDato();
    l++;
     
    /* it's a leaf, so print the path that lead to here */
    if (p->getIzq() == NULL && p->getDer() == NULL)
    {
        printArray(v, l);
    }
    else
    {
        /* otherwise try both subtrees */
        imprimirRama(p->getIzq(), v, l);
        imprimirRama(p->getDer(), v, l);
    }
}


//==================================================================================================

void printPaths(NodoBinario* p)
{
    int path[1000];
    imprimirRama(p, path, 0);
}