// Eliminar el nodo con el valor mayor de un ABB previamente ingresado
#include "ArbolBinario.h"
#include "lista.h"

int main()
{
    void leerAB(ArbolBinario * b);   // prototipo de funcion ingreso AB
    void listaOrden(NodoBinario *p,Lista *l);   // prototipo de funcion que enlista los elementos del arbol
    ArbolBinario a; // declara un Arbol binario
    Lista l;
    leerAB(&a);    // llamado a funcion de ingreso AB
    cout<<" ARBOL INGRESADO "<<endl;
	a.imprimirABJerarquia(a.getRaiz(),0);
    listaOrden(a.getRaiz(),&l);
    a.eliminarNodo(l.ultimoNodo()->getDato());  // eliminando nodo mayor
    cout<<endl;
    cout<<" ARBOL CON EL VALOR MAYOR ELIMINADO "<<endl;
	a.imprimirABJerarquia(a.getRaiz(),0);
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
        listaOrden(p -> getIzq(),l);    //inserta valores subarbol izq
		listaOrden(p -> getDer(),l);    //inserta valores subarbol der
	}
}

//==================================================================================================
