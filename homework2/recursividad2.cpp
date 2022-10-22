// 2. Generar las N primeras líneas del triángulo de Pascal

#include <iostream>
using namespace std;
#include "utilidades.h"
// PROTOTIPOS
void trianguloPascal(int n, int *i);
void espacios(int r, int n);
void calculoPascal(int r, int n, int *i);

int main()
{
    int n, i = 1;
    cout << "Cuantas lineas desea ver del triangulo de pascal: ";
    cin >> n;
    trianguloPascal(n, &i);
    return 0;
}

void trianguloPascal(int n, int *i)
{
    if (n > 0)
    {
        trianguloPascal(n - 1, i);
        espacios(n,n);
        calculoPascal(n, n, i);
    }
        cout<<endl;
}
void espacios(int r, int n)
{
    if (r > 1)
    {
        espacios(r-n+1, n);
        cout << " ";
    }
}
void calculoPascal(int r, int n, int *i)
{
    if (r <= n)
    {
        calculoPascal(r + 1, n, i);
        cout << *i << " ";
        *i *= (n - r) / r;
    }
}