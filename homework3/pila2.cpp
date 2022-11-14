// Permitir el ingreso de varios números double desde teclado, incorporarlos
// en una pila, visualizar su contenido, y proceder a eliminar de esta todos
// aquellos valores que posean una cantidad impar de dígitos.

#include <iostream>
using namespace std;
#include "pila.h"

int main()
{
    // PROTOTIPOS
    void lecturaNums(Pila * p);                      // Lectura de numeros
    void imprimirPila(Pila p);                       // Impresion de elementos de pila
    int convertEntero(double a);                     // Convertir a entero un numero decimal
    int contarDigitos(int x);                        // Cuenta los digitos de un numero
    void eliminarElementosCDigitosImpar(Pila * p); // Elimina los elementos con cantidad de digitos impoar
    Pila a;
    lecturaNums(&a);
    cout << " ELEMENTOS EN PILA " << endl;
    imprimirPila(a);
    eliminarElementosCDigitosImpar(&a);
    cout << endl
         << " ELEMENTOS CON CANTIDAD IMPAR DE DIGITOS ELIMINADOS " << endl;
    imprimirPila(a);
    cout << endl;
    return 0;
}
void lecturaNums(Pila *p)
{
    Tipo x = 999, d;
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
int convertEntero(double a)
{
    int x;
    x = a;
    while (a != x)
    {
        a *= 10;
        x = a;
    }
    x = a;
    return x;
}
int contarDigitos(int x)
{
    int cont = 0;
    while (x > 0 || x <= -1)
    {
        x /= 10;
        cont++;
    }
    return cont;
}
void eliminarElementosCDigitosImpar(Pila *p)
{
    Pila b = *p;
    int aux, dig;
    double aux2;
    while (!b.pilaVacia())
    {
        aux2 = b.pop();
        aux = convertEntero(aux2);
        dig = contarDigitos(aux);
        if (dig % 2 != 0)
        {
            p->eliminarElementoPila(aux2);
        }
    }
}