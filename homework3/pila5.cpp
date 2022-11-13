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
    int lecturaPila(Pila * p);           // Lectura de elementos
    void imprimirPila(Pila p, int cont); // Impresion de elementos sin desapilar
    Pila a;
    int cont = 0;
    cont = lecturaPila(&a);
    cout << " ELEMENTOS EN PILA " << endl;
    imprimirPila(a, cont);
    cout << endl
         << "2. TAMANIO PILA: " << a.tamanioPila() << endl;
    return 0;
    cout << endl;
}
int lecturaPila(Pila *p)
{
    double x = 999, d;
    int cont = 0;
    Tipo y = EXT * 2;
    do
    {
        cout << "Ingrese numero (999 para finalizar): ";
        cin >> d;
        if (d != x)
        {
            p->push(d);
            if (p->pilaLlena())
            {
                cout << "Pila llena!" << endl;
                for (int i = EXT; i < y; i++)
                {
                    p->setVec(d, p->getTop() + 1);
                }
            }
            cont++;
        }
    } while (d != x);
    return cont;
}
void imprimirPila(Pila p, int cont)
{
    cout << "[ ";
    for (int i = 0; i < cont; i++)
    {
        cout << p.getVec(i) << " ";
    }

    cout << "]";
}
