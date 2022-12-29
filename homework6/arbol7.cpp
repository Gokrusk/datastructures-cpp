//Determinar si un ABB es un ABM (AB que en su raíz guarda el menor valor, y los subárboles 
//izquierdo y derecho tienen la misma propiedad).

#include "ArbolBinario.h"

int main()
{
	void leerAB(ArbolBinario * b); // prototipo de funcion ingreso AB
	ArbolBinario a; // declara un Arbol binario
	leerAB(&a); // llamado a funcion de ingreso AB
	cout << endl;
	cout<<" ARBOL INGRESADO "<<endl;
	a.imprimirABJerarquia(a.getRaiz(),0);
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