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
    void eliminarElementosRepetidos(Cola * a);     // Funcion para eliminar elementos repetidos

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
    // imprimirElementos(c);
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
void eliminarElementosRepetidos(Cola *a) // Funcion para eliminar elementos repetidos
{
    Cola b, c;
    Tipo aux = 0, aux2 = 0, x = 0;
    int cont;
    //b = *a;
    c = *a;
    while (!c.colaVacia())
    {
        b = *a;
        x = c.extraerVal();
        while (!b.colaVacia())
        {
        cont = 0;
            aux = b.extraerVal();
            if (x == aux)
            {
                cont++;
                cout<<aux<<endl;
            }
        }
    }
    //cout<<cont<<endl;
    if (cont > 1)
    {
        aux2 = aux;
    }
    cout << aux2 << endl;
    // while (!a->colaVacia())
    // {
    //     a->extraerVal();
    // }
    // b = c;
    // while (!a->colaLlena())
    // {
    //     aux = b.extraerVal();
    //     if (aux != aux2)
    //     {
    //         a->insertarVal(aux);
    //     }
    // }
}