//Generar una lista con los elementos del ABB recorrido en preorden, otra recorrido en inorden y una más con los elementos recorridos en postorden
#include "ArbolBinario.h"
#include "lista.h"

int main()
{                   // programa principal
    ArbolBinario a; // declara un Arbol binario

    void leerAB(ArbolBinario * b);   // prototipo de funcion ingreso AB
    void imprimirList(Lista l); // prototipo de funcion que imprime una lista
    void listaPreOrden(NodoBinario *p,Lista *l);   // prototipo de funcion que enlista los elementos del arbol
    void listaInOrden(NodoBinario *p,Lista *l);   // prototipo de funcion que enlista los elementos del arbol
    void listaPostOrden(NodoBinario *p,Lista *l);   // prototipo de funcion que enlista los elementos del arbol
    Lista pe, in, po;
    leerAB(&a);    // llamado a funcion de ingreso AB
    cout<<" ARBOL INGRESADO "<<endl;
	a.imprimirABJerarquia(a.getRaiz(),0);
    listaPreOrden(a.getRaiz(),&pe);
    listaInOrden(a.getRaiz(),&in);
    listaPostOrden(a.getRaiz(),&po);
    cout<<" PREORDEN "<<endl;
    imprimirList(pe);
    cout<<" INORDEN "<<endl;
    imprimirList(in);
    cout<<" POSTORDEN "<<endl;
    imprimirList(po);
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

void listaPreOrden(NodoBinario *p,Lista *l)
{
    if(p != NULL){
        l->insertarNodoFinal(p->getDato());   // insertar los elementos del arbol
        listaPreOrden(p -> getIzq(),l); // recorre subarbol izq
		listaPreOrden(p -> getDer(),l); // recorre subarbol der
	}
}

//==================================================================================================

void listaInOrden(NodoBinario *p,Lista *l)
{
    if(p != NULL){
        listaInOrden(p -> getIzq(),l);  // recorre subarbol izq
        l->insertarNodoFinal(p->getDato());   // insertar los elementos del arbol
		listaInOrden(p -> getDer(),l);  // recorre subarbol der
	}
}

//==================================================================================================

void listaPostOrden(NodoBinario *p,Lista *l)
{
    if(p != NULL){
        listaPostOrden(p -> getIzq(),l);    // recorre subarbol izq
		listaPostOrden(p -> getDer(),l);    // recorre subarbol der
        l->insertarNodoFinal(p->getDato());   // insertar los elementos del arbol
	}
}

//==================================================================================================

void imprimirList(Lista l)
{
    Nodo *actual;
    actual = l.getPrimero();    // apuntador temporal a primr elemento de lista
    cout<<"[";
    while (actual != NULL)  //  recorrido de lista
    {
        cout<<actual->getDato();    // imprime dato del apuntador
        cout<<" ";
        actual = actual->getPunt(); // avanza al valor que apunta
    }
    cout<<"]"<<endl;
}