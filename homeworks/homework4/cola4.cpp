// Una cola prioridad tiene una estructura similar a la de una cola, con la diferencia 
// que cada elemento tiene un campo que indica su prioridad. Los elementos se ingresan 
// en la cola según el orden de prioridad. Permitir insertar y eliminar elementos de 
// esta cola de prioridad. Utilizar para ello una nueva definición del TDA COLA, 
// que incorpore las modificaciones necesarias para cumplir lo solicitado.
#include<iostream>
using namespace std;
#include "colaPrioridad.h"

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