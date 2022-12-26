// ArbolBinario2.cpp
// implementa un AB basico con proceso de lectura e impresion

#include "ArbolBinario.h"

int main()
{					// programa principal
	ArbolBinario a; // declara un Arbol binario

	void leerAB(ArbolBinario * b);	 // prototipo de funcion ingreso AB
	void imprimirAB(ArbolBinario a); // prototipo de funcion que imprime AB
	bool visualizacion(ArbolBinario a);
	void eliminarNodo(ArbolBinario *a);
	void modificarArbol(ArbolBinario *a);
	leerAB(&a);	   // llamado a funcion de ingreso AB
	imprimirAB(a); // llamado a funcion que imprime un AB
	cout<<"El numero: " << (visualizacion(a) ? " si" : " no ")<<" se encuentra";
	eliminarNodo(&a);
	imprimirAB(a); // llamado a funcion que imprime un AB
	modificarArbol(&a);
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
	if(v != 999)
	{
		b->insertarNodo(v);
		leerAB(b);
	}
}

//==================================================================================================

void eliminarNodo(ArbolBinario *a)
{
	Tipo v;
	cout<<endl<<"Nodo a eliminar: ";
	cin>>v;
	a->eliminarNodo(v);
}

//==================================================================================================

bool visualizacion(ArbolBinario a)
{
	Tipo v;
	cout<<"Ingrese que numero desea buscar: ";
	cin>>v;
	return a.buscarNodo(v);
}

//==================================================================================================

void modificarArbol(ArbolBinario *a)
{
	NodoBinario *p;
	Tipo v,aux;
	cout<<"Que valor desea modificar: ";
	cin>>aux;
	if(a->buscarNodo(aux))
	{
		cout<<"Ingrese nuevo valor: ";
		cin>>v;
		if((aux < a->getRaiz()->getDato() && v > a->getRaiz()->getDato()) || (aux > a->getRaiz()->getDato() && v < a->getRaiz()->getDato()))
		{
			a->eliminarNodo(aux);
			a->insertarNodo(v);
		}
		cout<<"Replace"<<endl;
		
	}else{
		cout<<"El numero no se encuentra"<<endl;
	}
}

//==================================================================================================

void imprimirAB(ArbolBinario a)
{
	cout << endl
		 << "IMPRESION DE ARBOL BINARIO" << endl
		 << endl;
	// a.imprimirABSimple(a.getRaiz());	//llama metodo impresion simple de AB
	a.imprimirABJerarquia(a.getRaiz(), 0); // llama a metodo impresion con formato jerarquico de AB
}

//==================================================================================================
