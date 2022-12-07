// ARCHIVO DE CABECERA QUE CONTIENE LA IMPLEMENTACION DEL TDA LISTA
#ifndef _LISTA1_H
#define _LISTA1_H

#include "nodo1.h" //inclusion de la definicion de nodos
#include <iostream>
using namespace std;

class Lista1 // definicion del TDA Lista
{
private:                             // atributos
    Nodo1 *primero;                   // apunta al primer nodo
public:                              // metodos
    Lista1();                         // constructor
    void setPrimero(Nodo1 *x);        // actualizar el estado del atributo primero
    void insertarNodoInicio(Tipo x); // inserta un nuevo valor como primer nodo de la lista
    void insertarNodoFinal(Tipo x);  // inserta un nuevo valor como ultimo nodo de la lista
    void insertarUnNodo(Tipo v, Nodo1* ant);	//metodo que inserta un elemento nuevo en la lista luego del nodo ant
    void insertarEnOrden(Tipo v);			//metodo que inserta ordenadamente un valor dentro de una lista
    Nodo1 *buscarElemento(Tipo x);    // metodo que indica si un valor existe en la lista
    void eliminarNodo(Tipo x);       // metodo que elimina un nodo de la lista
    Nodo1 *ultimoNodo();              // devuelve la direccion del ultimo nodo
    void anular();                   // metodo que vuelve a inicializar una lista
    bool esVacia();                  // devuelve la lista esta vacia
    Nodo1 *getPrimero();
};

Lista1::Lista1() // la lista empieza sin nodos
{
    setPrimero(NULL);
}

void Lista1::setPrimero(Nodo1 *x)
{
    primero = x;
}

Nodo1 *Lista1::getPrimero()
{
    return primero;
}

void Lista1::insertarNodoInicio(Tipo x)
{
    Nodo1 *nuevo; //  var para almacenar direccion de memoria de nuevos nodos a crear
    nuevo = new Nodo1(x, getPrimero());
    setPrimero(nuevo);
}
void Lista1::insertarNodoFinal(Tipo x)
{
    Nodo1 *nuevo, //  var para almacenar direccion de memoria de nuevos nodos a crear
        *ultimo; // var para almacenar direccion de memoria del ultimo nodo de la lista
    nuevo = new Nodo1(x);
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

void Lista1::insertarUnNodo(Tipo v, Nodo1* ant){	//metodo que inserta un elemento nuevo en la lista luego del nodo ant
	Nodo1* nuevo;								//declaracion de un nuevo nodo
	
	nuevo = new Nodo1(v);						//llamar metodo constructor de nodo pasandole el valor recibido como parametro
	nuevo->setPunt(ant -> getPunt());			//llamar al metodo que actualiza la direccion a la cual debe apuntar el nuevo nodo
	ant -> setPunt(nuevo);						//actualiza la direccion del primer elemento de la lista: es el nuevo nodo creado
}

void Lista1::insertarEnOrden(Tipo v){			//metodo que inserta ordenadamente un valor dentro de una lista
	Nodo1* nuevo;								//declaracion de un nuevo nodo
	Nodo1* ant;									//apuntador al nodo anterior al nodo que se va a insertar
	Nodo1* ult = getPrimero();					//apuntador al ultimo nodo de la lista
	
	nuevo = new Nodo1(v);						//llamar metodo constructor de nodo pasandole el valor recibido como parametro
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

bool Lista1::esVacia() // devuelve la lista esta vacia
{
    return (getPrimero() == NULL);
}

void Lista1::anular()
{
    setPrimero(NULL);
}

Nodo1 *Lista1::ultimoNodo()
{
    // recorrido de la lista
    Nodo1 *actual;                     // referencia a nodo actual de la lista
    actual = getPrimero();            // almacena temporalmente la posicion del primer nodo
    while (actual->getPunt() != NULL) // repetir mientras no se alcance el final de la lista
    {
        actual = actual->getPunt(); // desplaza el puntero actual al siguiente nodo de la lista
    }
    return actual;
}

Nodo1 *Lista1::buscarElemento(Tipo x) // metodo que indica si un valor existe en la lista
{
    Nodo1 *actual;                                    // referencia a nodo actual de la lista
    actual = getPrimero();                           // almacena temporalmente la posicion del primer nodo
    while (actual != NULL && actual->getDato() != x) // repetir mientras no se alcance el final de la lista
    {
        actual = actual->getPunt(); // desplaza el puntero actual al siguiente nodo de la lista
    }
    return actual;
}

void Lista1::eliminarNodo(Tipo x)       // metodo que elimina un nodo de la lista
{
    Nodo1* actual;								//apunta al nodo actual de la lista
	Nodo1* ant;									//apuntador al nodo anterior al que debe eliminarse
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