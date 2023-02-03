// ARCHIVO DE CABECERA QUE CONTIENE LA IMPLEMENTACION DEL TDA LISTA
#ifndef _LISTA_H
#define _LISTA_H

#include "nodo.h" //inclusion de la definicion de nodos
#include <iostream>
using namespace std;

class Lista // definicion del TDA Lista
{
private:                             // atributos
    Nodo *primero;                   // apunta al primer nodo
public:                              // metodos
    Lista();                         // constructor
    void setPrimero(Nodo *x);        // actualizar el estado del atributo primero
    void insertarNodoInicio(Tipo x); // inserta un nuevo valor como primer nodo de la lista
    void insertarNodoFinal(Tipo x);  // inserta un nuevo valor como ultimo nodo de la lista
    void insertarUnNodo(Tipo v, Nodo* ant);	//metodo que inserta un elemento nuevo en la lista luego del nodo ant
    void insertarEnOrden(Tipo v);			//metodo que inserta ordenadamente un valor dentro de una lista
    Nodo *buscarElemento(Tipo x);    // metodo que indica si un valor existe en la lista
    void eliminarNodo(Tipo x);       // metodo que elimina un nodo de la lista
    Nodo *ultimoNodo();              // devuelve la direccion del ultimo nodo
    void anular();                   // metodo que vuelve a inicializar una lista
    bool esVacia();                  // devuelve la lista esta vacia
    Nodo *getPrimero();
};

Lista::Lista() // la lista empieza sin nodos
{
    setPrimero(NULL);
}

void Lista::setPrimero(Nodo *x)
{
    primero = x;
}

Nodo *Lista::getPrimero()
{
    return primero;
}

void Lista::insertarNodoInicio(Tipo x)
{
    Nodo *nuevo; //  var para almacenar direccion de memoria de nuevos nodos a crear
    nuevo = new Nodo(x, getPrimero());
    setPrimero(nuevo);
}
void Lista::insertarNodoFinal(Tipo x)
{
    Nodo *nuevo, //  var para almacenar direccion de memoria de nuevos nodos a crear
        *ultimo; // var para almacenar direccion de memoria del ultimo nodo de la lista
    nuevo = new Nodo(x);
    if (esVacia()) // la lista no tiene nodos
    {
        setPrimero(nuevo); // el apuntador primero apunte a nuevo
    }
    else
    {                          // sino que el ultimo nodo apunte al nuevo nodo
        ultimo = ultimoNodo(); // asigna la direccion de memoria del ultimo nodo
        ultimo->setPunt(nuevo);
    }
}

void Lista::insertarUnNodo(Tipo v, Nodo* ant){	//metodo que inserta un elemento nuevo en la lista luego del nodo ant
	Nodo* nuevo;								//declaracion de un nuevo nodo
	
	nuevo = new Nodo(v);						//llamar metodo constructor de nodo pasandole el valor recibido como parametro
	nuevo->setPunt(ant -> getPunt());			//llamar al metodo que actualiza la direccion a la cual debe apuntar el nuevo nodo
	ant -> setPunt(nuevo);						//actualiza la direccion del primer elemento de la lista: es el nuevo nodo creado
}

void Lista::insertarEnOrden(Tipo v){			//metodo que inserta ordenadamente un valor dentro de una lista
	Nodo* nuevo;								//declaracion de un nuevo nodo
	Nodo* ant;									//apuntador al nodo anterior al nodo que se va a insertar
	Nodo* ult = getPrimero();					//apuntador al ultimo nodo de la lista
	
	nuevo = new Nodo(v);						//llamar metodo constructor de nodo pasandole el valor recibido como parametro
	if (ult == NULL){							//lista vacia => nuevo nodo será el primero
		setPrimero(nuevo);						//el inicio de la lista apunta al nuevo nodo
	} else {									//lista no vacia
		if (v < ult -> getDato()){				//nuevo valor es menor que lo almacenado en el nodo apuntado desde ult
			nuevo -> setPunt(getPrimero());		//el nuevo apunta al inicio de la lista
			setPrimero(nuevo);					//el nuevo se situa al inicio de la lista
		} else {								//el nuevo valor no es menor
			ant = ult;							//guardar la direccion del nodo analizado como el nodo anterior
			while((ult -> getPunt() != NULL) && (v > ult->getDato())){
				ant = ult;						//guardar la direccion del nodo ant
				ult = ult -> getPunt();			//ult avanzar en la lista
			}
			if (v > ult->getDato()){
				ant = ult;
			}
			nuevo -> setPunt(ant->getPunt());
			ant->setPunt(nuevo);
		}
	}
}

bool Lista::esVacia() // devuelve la lista esta vacia
{
    return (getPrimero() == NULL);
}

void Lista::anular()
{
    setPrimero(NULL);
}

Nodo *Lista::ultimoNodo()
{
    // recorrido de la lista
    Nodo *actual;                     // referencia a nodo actual de la lista
    actual = getPrimero();            // almacena temporalmente la posicion del primer nodo
    while (actual->getPunt() != NULL) // repetir mientras no se alcance el final de la lista
    {
        actual = actual->getPunt(); // desplaza el puntero actual al siguiente nodo de la lista
    }
    return actual;
}

Nodo *Lista::buscarElemento(Tipo x) // metodo que indica si un valor existe en la lista
{
    Nodo *actual;                                    // referencia a nodo actual de la lista
    actual = getPrimero();                           // almacena temporalmente la posicion del primer nodo
    while (actual != NULL && actual->getDato() != x) // repetir mientras no se alcance el final de la lista
    {
        actual = actual->getPunt(); // desplaza el puntero actual al siguiente nodo de la lista
    }
    return actual;
}

void Lista::eliminarNodo(Tipo x)       // metodo que elimina un nodo de la lista
{
    Nodo* actual;								//apunta al nodo actual de la lista
	Nodo* ant;									//apuntador al nodo anterior al que debe eliminarse
	bool enc;									//bandera que indica si v se encuentra o no en la lista
	
	actual = getPrimero();						//copiar la direccion del primer nodo de la lista
	ant = NULL;									//por defecto, no existe un nodo antes del inicio de la lista
	enc = false;								//por defecto, el valor v no se encientra en la lista	

	while ((actual != NULL) && (!enc)){			//repetir el ciclo mientras el nodo apuntado por actual no apunta a NULL y no lo encuentre aun
		enc = (actual -> getDato() == x);		//actualiza el valor de la var bandera: encontrado true, no encontrado false
		
		if (!enc){								//valor aun no esta en el nodo actual
			ant = actual;						//el nodo actual se transforma en anterior
			actual = actual -> getPunt();		//actual avanza un nodo en la lista
		}
	}
												//termino la busqueda: encontramos el valor?
	if (actual != NULL){						//si el nodo actual no esta al final de la lista
		if (actual == getPrimero()){			//estamos en inicio de la lista
			setPrimero(actual -> getPunt());	//apuntador primero apuntara a donde apuntaba el nodo actual
		} else {								//no estamos al inicio de la lista
			ant -> setPunt(actual -> getPunt());// nodo anterior apunte a donde apuntaba el nodo actual
		}
	}
}
#endif