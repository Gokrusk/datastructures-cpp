// Administracion de una pila  con recursividad
#include <iostream>
using namespace std;
#include "pila.h"

int main()
{
    Tipo n = 0;
    Pila p, q, r;
    void insertElements(Pila * p, Tipo x);   // funcion recursiva para insertar elementos en una pila
    void printStack(Pila p);                 // funcion recursiva para imprimir elementos de una pila
    bool compaSize(Pila p, Pila q);          // funcion para comparar tamanios de pila
    bool compStacksUnsorted(Pila p, Pila q); // funcion recursiva para comparar dos pilas sin importar su orden
    bool compStacksSorted(Pila p, Pila q);   // funcion recursiva para comparar dos pilas
    void sortDesc(Pila * p, Pila b, Pila c); // funcion recursiva para ordenar descendentemente una pila

    cout
        << endl
        << "INSERCION EN PILA" << endl;
    insertElements(&p, 0);
    cout << endl
         << "IMPRESION DE PILA" << endl;
    cout << "[ ";
    printStack(p);
    cout << "]" << endl;
    // cout << endl
    //      << "INSERCION EN PILA" << endl;
    // insertElements(&q, 0);
    // cout << endl
    //      << "IMPRESION DE PILA" << endl;
    // cout << "[ ";
    // printStack(q);
    // cout << "]" << endl;
    // cout << endl
    //      << "COMPARACION" << endl;
    // cout << "Las pilas " << (compaSize(p, q) ? (compStacksSorted(p,q) ? "si" : "no" )
    //                                         : "no") << " son iguales";
    // cout << "Las pilas " << (compaSize(p, q) ? (compStacksUnsorted(p,q) ? "si" : "no" )
    //                                         : "no") << " son iguales";
    cout << endl
         << "DESC SORTED" << endl;
    cout << "[ ";
    sortDesc(&p, q, r);
    printStack(p);
    cout << "]" << endl;
    return 0;
}

void insertElements(Pila *p, Tipo x) // funcion recursiva para insertar elementos en una pila
{
    Tipo f = 999;
    if (x != f)
    {
        cout << "Ingrese elemento: ";
        cin >> x;
        if (x != f)
        {
            p->push(x);
        }
        insertElements(p, x);
    }
}

void printStack(Pila p) // funcion recursiva para imprimir elementos de una pila
{
    if (!p.pilaVacia())
    {
        cout << p.pop() << " ";
        printStack(p);
    }
}

bool compaSize(Pila p, Pila q) // funcion para comparar tamanios de pila
{
    return (p.tamanioPila() == q.tamanioPila());
}

bool loopComp(Pila p, Tipo x)
{
    if (!p.pilaVacia())
    {
        if (x == p.pop())
        {
            return true;
        }
        else
        {
            loopComp(p, x);
        }
    }
    else
    {
        return false;
    }
}

bool compStacksUnsorted(Pila p, Pila q) // funcion recursiva para comparar dos pilas sin importar su orden
{
    Tipo eA, eB;
    Pila c;
    bool flag;          // encontre o no valores iguales
    if (!p.pilaVacia()) // ya se sabe q tienen el mismo tamanio
    {
        eA = p.pop();
        flag = false;
        c = q;
        flag = loopComp(c, eA);
        compStacksUnsorted(p, q);
    }
    return flag;
}

bool compStacksSorted(Pila p, Pila q) // funcion recursiva para comparar dos pilas
{
    bool flag = true; // encuentra o no valores iguales
    if (!p.pilaVacia())
    {
        if (p.pop() != q.pop())
        {
            flag = false;
        }
        else
        {
            compStacksSorted(p, q);
        }
    }
    return flag;
}

Tipo loopDesc(Pila p, Tipo men)
{
    Tipo a1;
    if (!p.pilaVacia()) // ciclo para buscar valor menor de la pila
    {
        a1 = p.pop();
        if (a1 < men)
        {
            men = a1;
        }
        loopDesc(p, men);
    }
    return men;
}

void sortDesc(Pila *p, Pila b, Pila c) // funcion recursiva para ordenar descendentemente una pila
{
    Tipo men;
    if (!p->pilaVacia()) // mientras no este vacia
    {
        b = *p; // pila <b> llena
        men = b.pop();
        men = loopDesc(b, men);
        c.push(men);                  // valor menor se inserta en pila de respuesta
        p->eliminarElementoPila(men); // pila <b> vacia y pila <a> llena
        sortDesc(p, b, c);
    }
    else
    {
        *p = c; // asignar valor de pila <respuesta> a pila <a>
    }
}