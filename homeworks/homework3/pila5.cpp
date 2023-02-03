// La implementación del TAD Pila con arrays establece un tamaño máximo de la pila que
// se controla con la función pilaLlena(). Modificar la función de tal forma que cuando
// se llene la pila se amplíe el tamaño del array a justamente el doble de la capacidad
// actual.

#include <iostream>
using namespace std;
#include "pila5.h"

int main()
{
    // PROTOTIPOS
    void lecturaPila(Pila * p); // Lectura de elementos
    void imprimirPila(Pila p); // Impresion de elementos sin desapilar
    Pila a;
    lecturaPila(&a);
    cout << " ELEMENTOS EN PILA " << endl;
    imprimirPila(a);
    cout << endl
         << " TAMANIO PILA: " << a.tamanioPila() << endl;
    return 0;
    cout << endl;
}
void lecturaPila(Pila *p)
{
    Tipo x = 999, d;
    int y = 0;
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
    for (int i = 0; i <= p.getTop(); i++)
    {
        cout << p.getVec(i) << " ";
    }

    cout << "]";
}
