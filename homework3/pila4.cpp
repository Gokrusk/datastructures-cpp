// Con las operaciones definidas en el archivo de cabecera pila.h, elaborar un programa
// que permita visualizar el contenido de una pila de valores tipo char ingresados por el
// usuario. Nótese que la pila debe mantener los valores inicialmente ingresados hasta
// la finalización del programa.

#include <iostream>
using namespace std;
#include "pila2.h"

int main()
{
    // PROTOTIPOS
    void lecturaPila(Pila * p);                                         //Lectura de elementos
    void imprimirPila(Pila p);                                          //Impresion de elementos sin desapilar
    Pila a;
    lecturaPila(&a);
    cout << "1. TAMANIO PILA: " << a.tamanioPila() << endl;
    cout << " ELEMENTOS EN PILA " << endl;
    imprimirPila(a);
    cout << endl
         << "2. TAMANIO PILA: " << a.tamanioPila() << endl;
    return 0;
    cout << endl;
}
void lecturaPila(Pila *p)
{
    double x = 999, d;
    do
    {
        cout << "Ingrese numero (999 para finalizar): ";
        cin >> d;
        if (d != x)
        {
            p->push(d);
        }
    } while (d != x);
}
void imprimirPila(Pila p)
{
    cout << "[ ";
    while (!p.pilaVacia())
    {
        cout << p.pop() << " ";
    }
    cout << "]";
}
