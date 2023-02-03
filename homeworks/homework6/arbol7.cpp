// Determinar si un ABB es un ABM (AB que en su raíz guarda el menor valor, y los subárboles
// izquierdo y derecho tienen la misma propiedad).

#include "ArbolBinario.h"

int main()
{
	void leerAB(ArbolBinario * b); // prototipo de funcion ingreso AB
	bool verificarABM(NodoBinario * p);	// prototipo de funcion que verifica si un ABB es un ABM
	ArbolBinario a; // declara un Arbol binario
	leerAB(&a);		// llamado a funcion de ingreso AB
	cout << endl;
	cout << " ARBOL INGRESADO " << endl;
	a.imprimirABJerarquia(a.getRaiz(), 0);
	cout << "El arbol " << (verificarABM(a.getRaiz()) ? "si" : "no") << " es ABM" << endl;
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

bool verificarABM(NodoBinario *p)	// verifica si un arbol es un ABM
{
	if (p == NULL)
	{
		return false;
	}
	if (p->getIzq() == NULL || p->getDer() == NULL)	//	apuntador a izq y der null es true pq solo hay un valor
	{
		return true;
	}
	else
	{
		if (p->getDato() < p->getIzq()->getDato() && p->getDato() < p->getDer()->getDato())	// si dato es menor a los nodos izq y der
		{
			return true && verificarABM(p->getIzq());	// recorre subAB izq
		}
		if (p->getDato() < p->getIzq()->getDato() && p->getDato() < p->getDer()->getDato())	// si dato es menor a los nodos izq y der
		{
			return true && verificarABM(p->getDer());	// recorre subAB der
		}
	}
	return false;
}