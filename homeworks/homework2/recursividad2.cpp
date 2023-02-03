// 2. Generar las N primeras líneas del triángulo de Pascal

#include <iostream>
using namespace std;
#include "utilidades.h"
// PROTOTIPOS
void trianguloPascal(int n, int i);
void pascal(int i, int j);
int factorial(int n);
int combinacion(int n, int r);

int main()
{
    int n, i = 0;
    cout << "Cuantas lineas desea ver del triangulo de pascal: ";
    cin >> n;
    n-=1;
    trianguloPascal(n, i);
    return 0;
}

void trianguloPascal(int n, int i)
{
    pascal(i, 0);
    if (i < n)
    {
        trianguloPascal(n, i + 1);
    }
}
int factorial(int n)
{
    if (n > 0)
    {
        return n * factorial(n - 1);
    }
    else
    {
        return 1;
    }
}
int combinacion(int n, int r)
{
    int x = factorial(n);
    int y = factorial(n - r) * factorial(r);
    return x / y;
}
void pascal(int i, int j)
{
    cout << combinacion(i, j) << " ";
    if (j < i)
    {
        pascal(i, j + 1);
    }
    cout << endl;
}