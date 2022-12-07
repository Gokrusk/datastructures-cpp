// Clase que contiene metodos de gestion deun arbol
#ifndef _ARBOL_BINARIO_H
#define _ARBOL_BINARIO_H
#include "nodobinario.h" //aceder a metodos de nodos

class ArbolBinario
{
private:
    NodoBinario *raiz; // apuntador al nodo raiz
public:
    ArbolBinario();                   // constructor
    void setNodoRaiz(NodoBinario *v); // metodo que actualiza el atributo
    NodoBinario *getRaiz();           // metodo que devuelve el atributo nodo raiz
    bool esVacio();                   // metodo que determina si el arbol binario carece de nodos
    NodoBinario *construirAB(Tipo d, NodoBinario *izq, NodoBinario *der);
};

ArbolBinario::ArbolBinario() // constructor
{
    setNodoRaiz(NULL); // al inicio no hay nodos en el arbol
}
void ArbolBinario::setNodoRaiz(NodoBinario *v) // metodo que actualiza el atributo
{
    raiz = v;
}
NodoBinario *ArbolBinario::getRaiz() // metodo que devuelve el atributo nodo raiz
{
    return raiz;
}
bool ArbolBinario::esVacio()
{
    return (getRaiz() == NULL); // true si raiz == NULL
}
NodoBinario *ArbolBinario::construirAB(Tipo d, NodoBinario *izq, NodoBinario *der)
{
    return new NodoBinario(d,izq,der);  // construye un nuevo nodo con los parametros y devuelve
}
#endif