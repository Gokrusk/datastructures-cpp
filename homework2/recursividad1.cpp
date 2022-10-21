// 1. Permitir el ingreso de varios números enteros y determinar aquellos
// que posean la mayor cantidad de dígitos.

#include <iostream>
using namespace std;
#include "utilidades.h"

// PROTOTIPOS
void leer(int l, int n, int *c, int a[], int i);
void contDigitos(int n, int *c);

int main()
{
    int l, n, c = 0, i;
    cout << "Ingrese la cantidad de numeros a leer: ";
    cin >> l;
    i = l - 1;
    int a[i];
    leer(l, n, &c, a, i);
    return 0;
}
void leer(int l, int n, int *c, int a[], int i)
{
    if (l > 0 && i >= 0)
    {
        n = leerN(-32768, 32768); // lectura
        leer(l - 1, n, c, a, i - 1);
        contDigitos(n, c);
        a[i] = *c;
    }
}
void contDigitos(int n, int *c)
{
    *c = 0;
    if (n > 10 || n < -10)
    {
        contDigitos(n / 10, c);
    }
    *c += 1;
}