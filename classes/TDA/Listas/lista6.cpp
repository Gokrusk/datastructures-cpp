// Programa que permite ingresar elementos y generar listas de elementos que terminen en cada uno de los digitos del sistema de base 10
#include "lista.h"
using namespace std;
#include <iostream>

int main()
{
    // PROTOTIPOS
    void leerLista(Lista * a);     // insertar datos en una lista
    void imprimirLista(Lista a[]); // presenta los valores contenidos en los nodos de una lista
    // void generarListas(Lista a); // genera listas en base al ultimo digito de los elementos
    void generarListas(Lista a[]); // genera listas en base al ultimo digito de los elementos
    Lista l[10];
    cout << " LISTA " << endl;
    leerLista(l);
    imprimirLista(l);
    generarListas(l);
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
void imprimirLista(Lista a[])
{
    // recorrido de la lista
    Nodo *actual; // referencia a nodo actual de la lista
    cout << endl
         << " VALORES ALMACENADOS EN LA LISTA " << endl;
         
    for (int i = 0; i < 9; i++)
    {
        if(!a[i].esVacia())
        {
            cout << "Lista " << i << endl;
            actual = a[i].getPrimero(); // almacena temporalmente la posicion del primer nodo
            while (actual != NULL)      // repetir mientras no se alcance el final de la lista
            {
                cout << "> " << actual->getDato() << endl;
                actual = actual->getPunt(); // desplaza el puntero actual al siguiente nodo de la lista
            }
        }
        cout << endl;
    }
}

void generarListas(Lista a[]) // genera listas en base al ultimo digito de los elementos
{
    // recorrido de la lista
    Nodo *actual; // referencia a nodo actual de la lista
    Tipo x;
    actual = a[1].getPrimero(); // almacena temporalmente la posicion del primer nodo
    while (actual != NULL)      // repetir mientras no se alcance el final de la lista
    {
        x = actual->getDato();
        if (x < 0)
        {
            x *= -1;
        }
        switch (x % 10)
        {
        case 1:
            a[2].insertarEnOrden(actual->getDato());
            // b = New Lista.insertarEnOrden(actual->getDato());
            break;
        case 2:
            a[3].insertarEnOrden(actual->getDato());
            break;
        case 3:
            a[4].insertarEnOrden(actual->getDato());
            break;
        case 4:
            a[5].insertarEnOrden(actual->getDato());
            break;
        case 5:
            a[6].insertarEnOrden(actual->getDato());
            break;
        case 6:
            a[7].insertarEnOrden(actual->getDato());
            break;
        case 7:
            a[8].insertarEnOrden(actual->getDato());
            break;
        case 8:
            a[9].insertarEnOrden(actual->getDato());
            break;
        case 9:
            a[10].insertarEnOrden(actual->getDato());
            break;
        }
        actual = actual->getPunt();
        cout << endl;
    }
}
// void generarListas(Lista a) // genera dos listas a partir de la original, 1. elementos pares, 2. elementos impares
// {
//     Lista b,c,d,e,f,g,h,i,j;
//     // recorrido de la lista
//     Nodo *actual; // referencia a nodo actual de la lista
//     Tipo x;
//     actual = a.getPrimero(); // almacena temporalmente la posicion del primer nodo
//     while (actual != NULL)   // repetir mientras no se alcance el final de la lista
//     {
//         x = actual->getDato();
//         if(x < 0)
//         {
//             x *= -1;
//         }
//         switch (x%10)
//         {
//         case 1:
//             b.insertarEnOrden(actual->getDato());
//             //b = New Lista.insertarEnOrden(actual->getDato());
//             break;
//         case 2:
//             c.insertarEnOrden(actual->getDato());
//             break;
//         case 3:
//             d.insertarEnOrden(actual->getDato());
//             break;
//         case 4:
//             e.insertarEnOrden(actual->getDato());
//             break;
//         case 5:
//             f.insertarEnOrden(actual->getDato());
//             break;
//         case 6:
//             g.insertarEnOrden(actual->getDato());
//             break;
//         case 7:
//             h.insertarEnOrden(actual->getDato());
//             break;
//         case 8:
//             i.insertarEnOrden(actual->getDato());
//             break;
//         case 9:
//             j.insertarEnOrden(actual->getDato());
//             break;
//         }
//         actual = actual->getPunt();
//     }
//     cout << endl;
//     if(!b.esVacia())
//     {
//         imprimirLista(b);
//     }
//     if(!c.esVacia())
//     {
//         imprimirLista(c);
//     }
//     if(!d.esVacia())
//     {
//         imprimirLista(d);
//     }
//     if(!e.esVacia())
//     {
//         imprimirLista(e);
//     }
//     if(!f.esVacia())
//     {
//         imprimirLista(f);
//     }
//     if(!g.esVacia())
//     {
//         imprimirLista(g);
//     }
//     if(!h.esVacia())
//     {
//         imprimirLista(h);
//     }
//     if(!i.esVacia())
//     {
//         imprimirLista(i);
//     }
//     if(!j.esVacia())
//     {
//         imprimirLista(j);
//     }
// }