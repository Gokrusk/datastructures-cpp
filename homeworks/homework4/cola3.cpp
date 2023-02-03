// Insertar N elementos a partir de la ubicación X de una
// cola previamente ingresada.
#include <iostream>
using namespace std;
#include "cola.h"

int main()
{
    void ingresarCola(Cola * a);                          // metodo para insertar valores a cola
    void imprimirCola(Cola a);                            // metodo para imprimir cola
    void insertarDesdeNPosicion(Cola * a, Cola b, int n); // metodo para insertar n elementos desde una posicion x
    Cola a, b;
    int n;
    ingresarCola(&a);
    cout << endl << " COLA INGRESADA " << endl;
    imprimirCola(a);
    cout << endl << " INGRESE LOS ELEMENTOS A INSERTAR" << endl;
    ingresarCola(&b);
    cout << endl << " DESDE QUE POSICION DESEA INSERTAR: ";
    cin >> n;
    insertarDesdeNPosicion(&a, b, n);
    cout << endl << " COLA CON ELEMENTOS INSERTADOS " << endl;
    imprimirCola(a);
    return 0;
}

void ingresarCola(Cola *a)
{
    Tipo val = 0, fin = 999;
    do
    {
        cout << "Ingrese elemento, (ingrese " << fin << " para finalizar): ";
        cin >> val;
        if (val != fin)
        {
            a->insertarVal(val);
        }
    } while (val != fin);
}

void imprimirCola(Cola a)
{
    cout << "[ ";
    while (!a.colaVacia())
    {
        cout << a.extraerVal() << " ";
    }
    cout << "]";
}

void insertarDesdeNPosicion(Cola *a, Cola b, int n) // metodo para insertar n elementos desde una posicion x
{
    Cola c;
    Tipo aux;
    int i = 0;
    while (!a->colaVacia() && i < n)
    {
        aux = a->extraerVal();
        c.insertarVal(aux);
        i++;
    }
    while (!b.colaVacia())
    {
        aux = b.extraerVal();
        c.insertarVal(aux);
    }
    while (!a->colaVacia())
    {
        aux = a->extraerVal();
        c.insertarVal(aux);
    }
    *a  = c;
}