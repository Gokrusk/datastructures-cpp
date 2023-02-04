//A partir de dos listas ingresadas por el usuario, construir una sola lista que integre los valores ordenados de las dos listas previas}

#include "Lista.h"

using namespace std;

int main(){
	system("color f0");
	Lista listaA, listaB, listaFinal;

	void ingresarLista(Lista *a);			//funcion que ingresa los valores a incluir en la lista
	void imprimirLista(Lista a);			//funcion que presenta los valores contenidos en los nodos de una lista

	void mergeListas(Lista *listaFinal, Lista listaA, Lista listaB);

	ingresarLista(&listaA);
	imprimirLista(listaA);
	
	ingresarLista(&listaB);
	imprimirLista(listaB);
	
	mergeListas(&listaFinal, listaA, listaB);		//llamado a la funcion que inserta un elemento en medio de una lista

	cout << endl << "VALORES ALMACENADOS EN LA LISTA FINAL ORDENADA ";
	imprimirLista(listaFinal);
	
	cout << endl;
	system("pause");
}

void ingresarLista(Lista *a){	//funcion que ingresa los valores a incluir en la lista
	Tipo aux;			//var de lectura
	Tipo fin = 99999;	//marcador de final de lectura

	do {
		cout << endl << "Ingrese un valor para la lista, finalice con [" << fin <<"]: ";
		cin >> aux;

		if (aux != fin){								//no ingresa marcador de fin de lectura
//			a->insertarAlInicio(aux);					//llamado al metodo que inserta un nuevo nodo al inicio de una lista
			a->insertarNodoFinal(aux);					//llamado al metodo que inserta un nuevo nodo al final de una lista
//			a->insertarEnOrden(aux);					//llamado al metodo que inserta un nuevo nodo ordenadamente en una lista
		}
	}while (aux != fin);								//termina lectura con ingreso de marcador de fin
}

void imprimirLista(Lista a){	//funcion que presenta los valores contenidos en los nodos de una lista
	//recorrido de la lista
	Nodo* actual;		//referencia al nodo actual de la lista

	cout << endl << "VALORES ALMACENADOS EN LA LISTA";
	actual = a.getPrimero();	//almacenar temporalmente la posicion del primero nodo de la lista
	while (actual != NULL){		//repetir mientras no se alcance el final de la lista
		cout << endl << "> " << actual->getDato();
		actual = actual->getPunt();		//desplaza el puntero actual al siguiente nodo de la lista
	}
}

void mergeListas(Lista *listaFinal, Lista listaA, Lista listaB){	//funcion que inserta un elemento en la mitad de una lista
	Tipo val;
	
	while(!listaA.esVacia()){
		val = listaA.getPrimero()->getDato();
		listaFinal->insertarEnOrden(val);
		listaA.eliminarNodo(val);
	}
	
	while(!listaB.esVacia()){
		val = listaB.getPrimero()->getDato();
		listaFinal->insertarEnOrden(val);
		listaB.eliminarNodo(val);
	}
	
}


