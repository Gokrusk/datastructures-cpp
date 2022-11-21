// ARCHIVO DE CABECERA QUE CONTIENE LA IMPLEMENTACION DEL TDA LISTA
#include "nodo.h" //inclusion de la definicion de nodos
#include<iostream>

class Lista // definicion del TDA Lista
{
private:                      // atributos
    Nodo *primero;            // apunta al primer nodo
public:                       // metodos
    Lista();                  // constructor
    void setPrimero(Nodo *x); // actualizar el estado del atributo primero
    Nodo *getPrimero();
};

Lista::Lista()                  // la lista empieza sin nodos
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
