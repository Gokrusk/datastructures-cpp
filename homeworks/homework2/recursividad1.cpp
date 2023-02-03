// 1. Permitir el ingreso de varios números enteros y determinar aquellos
// que posean la mayor cantidad de dígitos.

#include <iostream>
using namespace std;
#include "utilidades.h"

// PROTOTIPOS
void leer(int l, int n, int *c, int a[], int b[], int i);
void contDigitos(int n, int *c);
void mayorCantDig(int a[], int i, int *may, int *p);

int main()
{
    int l, n, c = 0, i, may, p=0;
    cout << "Ingrese la cantidad de numeros a leer: ";
    cin >> l;
    i = l - 1;
    int a[i];
    int b[i];
    leer(l, n, &c, a, b, i);
    mayorCantDig(a, i, &may, &p);
    cout << "El numero "<< b[p] << " tiene la mayor cantidad de digitos: " << may << endl;
    return 0;
}
void leer(int l, int n, int *c, int a[], int b[], int i)
{
    if (l > 0 && i >= 0)
    {
        n = leerN(-32768, 32768); // lectura
        leer(l - 1, n, c, a, b, i - 1);
        contDigitos(n, c);
        a[i] = *c;
        b[i] = n;
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
void mayorCantDig(int a[], int i, int *may, int *p)
{
    if (i >= 0)
    {
        mayorCantDig(a, i - 1, may, p);
        *may = a[0];
        if (a[i] > *may)
        {
            *may = a[i];
            *p = i;
        }
    }
}