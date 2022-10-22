// 5. Determinar si cada número ingresado es un valor primo o compuesto.

#include <iostream>
using namespace std;
#include "utilidades.h"

// PROTOTIPOS
void comprobarPriComp(int n);
void leer(int n, int x, int *c, int d);
void contar(int n, int x, int d, int *c);
void primComp(int n, int *c);

int main()
{
    int n, x, c=0, d=0;
    cout << "Ingrese cuantos numeros a comprobar: ";
    cin >> n;
    leer(n, x, &c, d);
    return 0;
}

void leer(int n, int x, int *c, int d)
{
    if (n > 0)
    {
        leer(n - 1, x, c, d);
        x = leerN(-32768, 32768);
        contar(x, x, d, c);
        primComp(x, c);
    }
}
void contar(int n, int x, int d, int *c)
{
    *c = 0;
    if (n > 1)
    {
        contar(n - 1, x, d, c);
    }
    d = x % n;
    if(d==0)
    {
        *c = *c +1;
    }
}
void primComp(int n, int *c)
{
    if (*c == 2)
    {
        cout << "El numero "<< n << " es primo"<<endl;
    }
    else
    {
        cout << "El numero "<< n << " es compuesto"<<endl;
    }
}