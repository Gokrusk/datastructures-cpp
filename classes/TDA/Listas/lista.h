// ARCHIVO DE CABECERA QUE CONTIENE LA IMPLEMENTACION DEL TDA LISTA
#include "nodo.h" //inclusion de la definicion de nodos
#include <iostream>

class Lista // definicion del TDA Lista
{
private:                             // atributos
    Nodo *primero;                   // apunta al primer nodo
public:                              // metodos
    Lista();                         // constructor
    void setPrimero(Nodo *x);        // actualizar el estado del atributo primero
    void insertarNodoInicio(Tipo x); // inserta un nuevo valor como primer nodo de la lista
    void insertarNodoFinal(Tipo x);  // inserta un nuevo valor como ultimo nodo de la lista
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