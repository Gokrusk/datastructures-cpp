//Generar una lista con los elementos del ABB recorrido en preorden, otra recorrido en inorden y una más con los elementos recorridos en postorden
#include "ArbolBinario.h"
#include "lista.h"

int main()
{                   // programa principal
    ArbolBinario a; // declara un Arbol binario

    void leerAB(ArbolBinario * b);   // prototipo de funcion ingreso AB
    void imprimirAB(ArbolBinario a); // prototipo de funcion que imprime AB
    void imprimirList(Lista l); // prototipo de funcion que imprime una lista
    void listaPreOrden(NodoBinario *p,Lista *l);   // prototipo de funcion que enlista los elementos del arbol
    void listaInOrden(NodoBinario *p,Lista *l);   // prototipo de funcion que enlista los elementos del arbol
    void listaPostOrden(NodoBinario *p,Lista *l);   // prototipo de funcion que enlista los elementos del arbol
    Lista pe, in, po;
    leerAB(&a);    // llamado a funcion de ingreso AB
    imprimirAB(a); // llamado a funcion que imprime un AB
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
        listaPreOrden(p -> getIzq(),l);
		listaPreOrden(p -> getDer(),l);
	}
}

//==================================================================================================

void listaInOrden(NodoBinario *p,Lista *l)
{
    if(p != NULL){
        listaInOrden(p -> getIzq(),l);
        l->insertarNodoFinal(p->getDato());   // insertar los elementos del arbol
		listaInOrden(p -> getDer(),l);
	}
}

//==================================================================================================

void listaPostOrden(NodoBinario *p,Lista *l)
{
    if(p != NULL){
        listaPostOrden(p -> getIzq(),l);
		listaPostOrden(p -> getDer(),l);
        l->insertarNodoFinal(p->getDato());   // insertar los elementos del arbol
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

void imprimirList(Lista l)
{
    Nodo *actual;
    actual = l.getPrimero();
    cout<<"[";
    while (actual != NULL)
    {
        cout<<actual->getDato();
        cout<<" ";
        actual = actual->getPunt();
    }
    cout<<"]"<<endl;
}