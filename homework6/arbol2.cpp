// Eliminar el nodo con el valor mayor de un ABB previamente ingresado
#include "ArbolBinario.h"
#include "lista.h"

int main()
{                   // programa principal
    ArbolBinario a; // declara un Arbol binario

    void leerAB(ArbolBinario * b);   // prototipo de funcion ingreso AB
    void imprimirAB(ArbolBinario a); // prototipo de funcion que imprime AB
    void listaOrden(NodoBinario *p,Lista *l);   // prototipo de funcion que enlista los elementos del arbol
    Lista l;
    leerAB(&a);    // llamado a funcion de ingreso AB
    imprimirAB(a); // llamado a funcion que imprime un AB
    listaOrden(a.getRaiz(),&l);
    a.eliminarNodo(l.ultimoNodo()->getDato());  // eliminando nodo mayor
    imprimirAB(a); // llamado a funcion que imprime un AB
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
    if (v != 999)
    {
        b->insertarNodo(v);
        leerAB(b);
    }
}

//==================================================================================================

void listaOrden(NodoBinario *p,Lista *l)
{
    if(p != NULL){
        l->insertarEnOrden(p->getDato());   // insertar en orden los elementos del arbol
        listaOrden(p -> getIzq(),l);
		listaOrden(p -> getDer(),l);
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
