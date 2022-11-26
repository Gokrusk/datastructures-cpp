// Partir de dos colas ingresadas, y proceder a la conformación de una tercera cola
// cuyos elementos se encuentren ordenados ascendentemente y deberán corresponder a
// la fusión de las colas iniciales.
#include <iostream>
using namespace std;
#include "cola.h"

int main()
{
    void ingresarCola(Cola * a);                  // metodo para insertar valores a cola
    void imprimirCola(Cola a);                    // metodo para imprimir cola
    void fusionarColas(Cola a, Cola b, Cola * c); // metodo para fusionar colas
    void ordernarCola(Cola * a);                  // metodo para ordenar elementos de cola
    Cola a, b, c;
    cout << endl
         << " INGRESAR ELEMENTOS COLA A " << endl;
    ingresarCola(&a);
    cout << endl
         << " INGRESAR ELEMENTOS COLA B " << endl;
    ingresarCola(&b);
    cout << endl
         << " COLA A: ";
    imprimirCola(a);
    cout << endl
         << " COLA B: ";
    imprimirCola(b);
    cout << endl;
    cout << endl
         << " COLAS FUSIONADAS " << endl;
    fusionarColas(a, b, &c);
    imprimirCola(c);
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

void fusionarColas(Cola a, Cola b, Cola *c) // metodo para fusionar colas
{
    Cola d, e, f;
    Tipo aux, aux2, aux3;
    bool flag = false;
    while (!a.colaVacia())
    {
        aux = a.extraerVal();
        c->insertarVal(aux);
    }
    d = *c;                     //guarda la cola c para no alterar sus elementos
    e = b;                      //guarda la cola b para no alterar sus elementos
    f = b;                      //guarda la cola b para no alterar sus elementos
    aux = 0;
    while (!d.colaVacia())
    {
        aux = 0;
        aux2 = 0;
        aux3 = 0;
        flag = false;
        e = b;
        aux = d.extraerVal();
        //cout << "->a: " << aux << endl;
        while (!e.colaVacia())                          //busca los elementos de cola <a> que esten repetidos en cola <b>
        {
            aux2 = e.extraerVal();
            //cout << "b: " << aux2 << endl;
            if (aux2 == aux)
            {
                flag = true;
            }
        }
        e = b;
        if (flag)                                       //si encuentra, elimina los elementos repetidos de cola <b>
        {
            //cout << "REPETIDO: " << aux << endl;
            while (!b.colaVacia())
            {
                b.extraerVal();
            }
            while (!f.colaVacia())
            {
                aux3 = f.extraerVal();
                if (aux3 != aux)
                {
                    b.insertarVal(aux3);
                }
            }
        }
        f = e;
    }
    while (!b.colaVacia())                              //fusiona cola <a> y cola <b> en cola <c>
    {
        aux = b.extraerVal();
        c->insertarVal(aux);
    }
}

void ordernarCola(Cola *a) // metodo para ordenar elementos de cola
{
    cout << endl;
}