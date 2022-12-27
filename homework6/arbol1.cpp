// Obtener la imagen especular de un ABB previamente ingresado (reflejo respecto al eje vertical)
#include "ArbolBinario.h"
#include "lista.h"

int main()
{					// programa principal
	ArbolBinario a; // declara un Arbol binario
	Lista l;
	void leerAB(ArbolBinario * b); // prototipo de funcion ingreso AB
	leerAB(&a); // llamado a funcion de ingreso AB
	cout << endl;
	cout<<" ARBOL INGRESADO "<<endl;
	a.imprimirABJerarquia(a.getRaiz(),0);
	cout<<" IMAGEN ESPECULAR "<<endl;
	a.imprimirABJerarquiaEspecular(a.getRaiz(),0);
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