// Definicion de clase que origina los nodos de un Arbol
#ifndef _NODO_BINARIO_H
#define _NODO_BINARIO_H
#include<iostream>
typedef int Tipo;

class NodoBinario
{
private:
    Tipo dato;        // atributo para contener el valor de nodo
    NodoBinario *izq; // apuntador al subarbol izq
    NodoBinario *der; // apuntador al subarbol der

public:
    NodoBinario();
    void setDato(Tipo v);                 // metodo que actualiza el atributo dato
    void setNodoBinarioI(NodoBinario *v); // metodo que actualiza atributo de nodo izquierdo
    void setNodoBinarioD(NodoBinario *v); // metodo que actualiza atributo de nodo derecho
    Tipo getDato();                       // metodo que devuelve el atributo dato
    NodoBinario *getIzq();                // metodo que devuelve atributo de nodo izquierdo
    NodoBinario *getDer();                // metodo que devuelve atributo de nodo derecho
};

NodoBinario::NodoBinario()
{
    setNodoBinarioI(NULL);
    setNodoBinarioD(NULL);
}
void NodoBinario::setDato(Tipo v) // metodo que actualiza el atributo dato
{
    dato = v;
}
void NodoBinario::setNodoBinarioI(NodoBinario *v) // metodo que actualiza atributo de nodo izquierdo
{
    izq = v;
}
void NodoBinario::setNodoBinarioD(NodoBinario *v) // metodo que actualiza atributo de nodo derecho
{
    der = v;
}
Tipo NodoBinario::getDato() // metodo que devuelve el atributo dato
{
    return dato;
}
NodoBinario *NodoBinario::getIzq() // metodo que devuelve atributo de nodo izquierdo
{
    return izq;
}
NodoBinario *NodoBinario::getDer() // metodo que devuelve atributo de nodo derecho
{
    return der;
}
#endif
