// Implementar el uso del TDA Cola por recursividad
#include <iostream>
using namespace std;
#include "utilidades.h"
#include "cola.h"

int main()
{
    // PROTOTIPOS
    void ingresarCola(Cola * a, Tipo x, Tipo fin); // Funcion para insertar valores en la cola
    void imprimirElementos(Cola a);                // Funcion para imprimir valores de la cola
    bool revisarRepetidos(Cola a, Tipo x);
    void eliminarElementosRepetidos(Cola * a); // Funcion para eliminar elementos repetidos

    Cola c; // Instancia del TDA Cola
    Tipo val = 0, fin = 999;
    cout << "1. TAMANIO QUEUE: " << c.tamanioCola() << endl;
    ingresarCola(&c, val, fin);
    cout << "2. TAMANIO QUEUE: " << c.tamanioCola() << endl;
    cout << " ELEMENTOS IN QUEUE " << endl;
    cout << "[ ";
    imprimirElementos(c);
    cout << "]" << endl;
    cout << "3. TAMANIO QUEUE: " << c.tamanioCola() << endl;
    cout << endl;
    cout << " ELIMINAR ELEMENTOS REPETIDOS " << endl;
    eliminarElementosRepetidos(&c);
    cout << " ELEMENTOS IN QUEUE " << endl;
    cout << "[ ";
    imprimirElementos(c);
    cout << "]" << endl;
    system("pause");
}

void ingresarCola(Cola *a, Tipo x, Tipo fin)
{

    cout << "Ingrese elemento, (ingrese " << fin << " para finalizar): ";
    cin >> x;
    if (x != fin)
    {
        a->insertarVal(x);
        ingresarCola(a, x, fin);
    }
}
void imprimirElementos(Cola a)
{
    if (!a.colaVacia())
    {
        cout << a.extraerVal() << " ";
        imprimirElementos(a);
    }
}
bool revisarRepetidos(Cola a, Tipo x)
{
    int cont = 0;
    Tipo aux;
    while (!a.colaVacia())
    {
        aux = a.extraerVal();
        if (x == aux)
        {
            cont++;
        }
    }
    if (cont > 1)
    {
        return true;
    }
    return false;
}
void eliminarElementosRepetidos(Cola *a) // Funcion para eliminar elementos repetidos
{
    Cola b, c;
    Tipo aux = 0, aux2 = 0, x = 0;
    int cont;
    //b = *a;
    c = *a;
    do
    {
        while (!c.colaVacia())
        {
            b = *a;
            aux = c.extraerVal();
            if (revisarRepetidos(b, aux))
            {
                while (!a->colaVacia())
                {
                    a->extraerVal();
                }
                while (!b.colaVacia())
                {
                    aux2 = b.extraerVal();
                    if (aux2 != aux)
                    {
                        a->insertarVal(aux2);
                    }
                }
            }
        }
    } while (revisarRepetidos(b, aux));
}