// Eliminar los N elementos que ocupan las posiciones centrales de una cola
// previamente ingresada.
#include <iostream>
using namespace std;
#include "cola.h"

int main()
{
    void ingresarCola(Cola * a);               // metodo para insertar valores a cola
    void imprimirCola(Cola a);                 // metodo para imprimir cola
    void elementosCentrales(Cola a, Cola * b); // metodo que busca elementos del medio de la cola
    void eliminarElementosCentrales(Cola * a, Cola b);
    Cola a, b;
    cout << endl
         << " INGRESAR ELEMENTOS " << endl;
    ingresarCola(&a);
    cout << endl
         << " COLA: ";
    imprimirCola(a);
    cout << endl
         << " ELEMENTOS CENTRALES: ";
    elementosCentrales(a, &b);
    imprimirCola(b);
    eliminarElementosCentrales(&a, b);
    imprimirCola(a);
    cout << endl;
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
void elementosCentrales(Cola a, Cola *b) // metodo que busca n elementos del medio de la cola
{
    int n = a.tamanioCola();
    int aux;
    for (int i = 0; i < n; i++)
    {
        aux = a.extraerVal();
        if (i > 0 && i < n - 1)
        {
            b->insertarVal(aux);
        }
    }
}
void eliminarElementosCentrales(Cola *a, Cola b)
{
    int n;
    Tipo aux, aux2;
    Cola c,d=*a;
    do
    {
        cout << "Ingrese cantidad de elementos centrales a eliminar: ";
        cin >> n;
    } while (n > b.tamanioCola());
    if (n == b.tamanioCola())
    {
        while (!b.colaVacia())
        {
            *a = d;
            aux = b.extraerVal();
            while (!a->colaVacia())
            {
                aux2 = a->extraerVal();
                if (aux2 != aux)
                {
                    c.insertarVal(aux2);
                }
            }
        }
    }
    *a = c;
}