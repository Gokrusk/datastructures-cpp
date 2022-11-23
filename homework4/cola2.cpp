//Eliminar los N elementos que ocupan las posiciones centrales de una cola 
//previamente ingresada.
#include<iostream>
using namespace std;
#include "cola.h"

int main()
{
    void ingresarCola(Cola * a);                      // metodo para insertar valores a cola
    void imprimirCola(Cola a);                        // metodo para imprimir cola
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