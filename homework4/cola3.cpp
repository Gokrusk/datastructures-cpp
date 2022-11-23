//Insertar N elementos a partir de la ubicación X de una 
//cola previamente ingresada.
#include<iostream>
using namespace std;
#include "cola.h"

int main()
{
    void ingresarCola(Cola * a);                      // metodo para insertar valores a cola
    void imprimirCola(Cola a);                        // metodo para imprimir cola
    void insertarDesdeNPosicion(Cola * a);              // metodo para insertar n elementos desde una posicion x
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