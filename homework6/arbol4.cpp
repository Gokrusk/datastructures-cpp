//Determinar el número de nodos que se encuentran en un nivel X de un ABB
#include "ArbolBinario.h"

int main()
{					// programa principal
	ArbolBinario a; // declara un Arbol binario

	void leerAB(ArbolBinario * b);	 // prototipo de funcion ingreso AB
	void imprimirAB(ArbolBinario a); // prototipo de funcion que imprime AB
	leerAB(&a);						 // llamado a funcion de ingreso AB
	imprimirAB(a);					 // llamado a funcion que imprime un AB
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

void imprimirAB(ArbolBinario a)
{
	cout << endl
		 << "IMPRESION DE ARBOL BINARIO" << endl
		 << endl;
	// a.imprimirABJerarquia(a.getRaiz(), 0); // llama a metodo impresion con formato jerarquico de AB
	a.imprimirABJerarquia(a.getRaiz(), 0);
}

//==================================================================================================
