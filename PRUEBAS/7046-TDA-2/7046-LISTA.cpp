// Programa que permite insertar elementos al final de una lista
#include "lista.h"
using namespace std;

int main()
{
    // PROTOTIPOS
    void leerLista(Lista * a);           // insertar datos en una lista
    void imprimirLista(Lista a);         // presenta los valores contenidos en los nodos de una lista
    int contarElementos(Lista a);        // cuenta elementos de la lista
    void ordenarLista(Lista * a);        // ordena elementos de lista previamente ingresada
    void alterarLista(Lista * a, int x); // altera el orden de los elementos de la lista
    Lista l, m;
    Tipo x;
    int cont;
    leerLista(&l);
    imprimirLista(l);
    cont = contarElementos(l);
    ordenarLista(&l);
    alterarLista(&l, cont);
    imprimirLista(l);
    return 0;
}
void leerLista(Lista *a) // insertar datos en una lista
{
    Tipo x, fin = 999;
    do
    {
        cout << "Ingrese valor para la lista (fin 999): ";
        cin >> x;
        if (x != fin)
        {
            a->insertarNodoFinal(x);
        }
    } while (x != fin);
}
void imprimirLista(Lista a)
{
    // recorrido de la lista
    Nodo *actual; // referencia a nodo actual de la lista
    cout << endl
         << " VALORES ALMACENADOS EN LA LISTA " << endl;
    actual = a.getPrimero(); // almacena temporalmente la posicion del primer nodo
    while (actual != NULL)   // repetir mientras no se alcance el final de la lista
    {
        cout << "> " << actual->getDato() << endl;
        actual = actual->getPunt(); // desplaza el puntero actual al siguiente nodo de la lista
    }
    cout << endl;
}
int contarElementos(Lista a) // cuenta elementos de la lista
{
    Nodo *actual;
    int cont = 0;
    actual = a.getPrimero();
    while (actual != NULL) // recorre la lista
    {
        cont++; // cuenta los elementos
        actual = actual->getPunt();
    }
    return cont; // retorna el valor
}
void ordenarLista(Lista *a)
{
    Nodo *actual;
    Lista b;
    actual = a->getPrimero();
    while (actual != NULL) // recorre la lista
    {
        b.insertarEnOrden(actual->getDato()); // inserta ordenadamente los valores de la otra lista
        actual = actual->getPunt();
    }
    *a = b; // reasigna a lista principal
}

// void alterarLista(Lista *a, int x) // altera el orden de los elementos de la lista
// {
//     Lista b, c, d;
//     Nodo *actual, *actual1;
//     int cont = 0, cont1 = 0;
//     actual = a->getPrimero();
//     while (actual != NULL && cont <= x)
//     {

//         cont1 = cont + 3;

//         while (cont < cont1)
//         {
//             b.insertarNodoFinal(actual->getDato());
//             a->eliminarNodo(actual->getDato());
//             cont++;
//             actual = actual->getPunt();
//         }

//         cont1 = cont + 3;

//         while (cont < cont1)
//         {
//             c.insertarNodoInicio(actual->getDato());
//             a->eliminarNodo(actual->getDato());
//             cont++;

//             actual = actual->getPunt();
//         }
//         actual1 = c.getPrimero();

//         cont1 = cont + 3;

//         while (cont < cont1)
//         {
//             b.insertarNodoFinal(actual1->getDato());
//             cont++;
//             actual1 = actual1->getPunt();
//         }
//         c = d;
//     }
//     *a = b; // reasigna a lista principal
// }
void alterarLista(Lista *a, int x) // altera el orden de los elementos de la lista
{
    Lista b,c, d;
    Nodo *actual, *actual1;
    int cont = 0, cont1 = 0, aux = x;
    actual = a->getPrimero();
    while (actual != NULL && cont <= x)
    {
        if(aux >= 3)
        {
            cont1 = cont + 3;
        }else{
            cont1 = cont + aux;
        }
        while (cont < cont1)
        {
            b.insertarNodoFinal(actual->getDato());
            a->eliminarNodo(actual->getDato());
            cont++;
            aux--;
            actual = actual->getPunt();
        }
        if(aux >= 3)
        {
            cont1 = cont + 3;
        }else{
            cont1 = cont + aux;
        }
        while (cont < cont1)
        {
            c.insertarNodoInicio(actual->getDato());
            a->eliminarNodo(actual->getDato());
            cont++;
            aux--;
            actual = actual->getPunt();
        }
        actual1 = c.getPrimero();
        while (actual1 != NULL)
        {
            b.insertarNodoFinal(actual1->getDato());
            actual1 = actual1->getPunt();
        }
        c = d;
    }
    *a = b; // reasigna a lista principal
}