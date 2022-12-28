// Determinar el número de nodos que se encuentran en un nivel X de un ABB
#include "ArbolBinario.h"

int main()
{					// programa principal
	ArbolBinario a; // declara un Arbol binario

	void leerAB(ArbolBinario * b); // prototipo de funcion ingreso AB
	void nodosPorNivel(NodoBinario * p, int n, int nv, int *nodos);
	leerAB(&a); // llamado a funcion de ingreso AB
	int n = 0, nodos = 0;
	cout << " ARBOL INGRESADO " << endl;
	a.imprimirABJerarquia(a.getRaiz(), 0);
	cout << endl;
	do
	{
		cout << "Ingrese en que nivel desea contar los nodos: ";
		cin >> n;
		if (n < 0)
		{
			cout << "Ingrese numero positivo!" << endl;
		}
	} while (n < 0);
	nodosPorNivel(a.getRaiz(),n,0,&nodos);
	cout<<"Cantidad de nodos en el nivel "<<n<<": "<<nodos;
	cout << endl;
	system("pause");
}

//==================================================================================================

void leerAB(ArbolBinario *b)
{
	Tipo v;
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

void nodosPorNivel(NodoBinario *p, int n, int nv, int *nodos)
{
	if (p == NULL)
	{
		return;
	}
	if (n == nv)
	{
		*nodos = *nodos + 1;
	}
	nodosPorNivel(p->getIzq(), n, nv + 1, nodos);
	nodosPorNivel(p->getDer(), n, nv + 1, nodos);
}