// Implementar el uso del TDA Cola
#include <iostream>
using namespace std;
#include "utilidades.h"
#include "cola.h"

int main()
{
    // PROTOTIPOS
    void ingresarCola(Cola * a);    // Funcion para insertar valores en la cola
    void imprimirElementos(Cola a); // Funcion para imprimir valores de la cola

    Cola c; // Instancia del TDA Cola
    Tipo val;
    cout << "1. TAMANIO QUEUE: " << c.tamanioCola() << endl;
    ingresarCola(&c);
    cout << "2. TAMANIO QUEUE: " << c.tamanioCola() << endl;
    cout << " ELEMENTOS IN QUEUE " << endl;
    imprimirElementos(c);
    cout << "3. TAMANIO QUEUE: " << c.tamanioCola() << endl;
    cout << endl;
    system("pause");
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
void imprimirElementos(Cola a)
{
    cout << "[ ";
    while (!a.colaVacia())
    {
        cout << a.extraerVal() << " ";
    }
    cout << "]" << endl;
}