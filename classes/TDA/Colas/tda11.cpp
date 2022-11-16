//Implementar uso de TDA cola circular
#include <iostream>
using namespace std;
#include "colacircular.h"

int main()
{
    // PROTOTIPOS
    void ingresarCola(ColaCircular * a, Tipo x, Tipo fin); // Funcion para insertar valores en la cola
    void imprimirElementos(ColaCircular a);                // Funcion para imprimir valores de la cola

    ColaCircular c; // Instancia del TDA Cola
    Tipo val = 0, fin = 999;
    //cout << "1. TAMANIO QUEUE: " << c.tamanioCola() << endl;
    ingresarCola(&c, val, fin);
    //cout << "2. TAMANIO QUEUE: " << c.tamanioCola() << endl;
    cout << " ELEMENTOS IN QUEUE " << endl;
    cout << "[ ";
    imprimirElementos(c);
    cout << "]" << endl;
    system("pause");
}

void ingresarCola(ColaCircular *a, Tipo x, Tipo fin)
{
    cout << "Ingrese elemento, (ingrese " << fin << " para finalizar): ";
    cin >> x;
    if (x != fin)
    {
        a->insertarVal(x);
        ingresarCola(a, x, fin);
    }
}
void imprimirElementos(ColaCircular a)
{
    if (!a.colaVacia())
    {
        cout << a.extraerVal() << " ";
        imprimirElementos(a);zzzzzz
    }
}