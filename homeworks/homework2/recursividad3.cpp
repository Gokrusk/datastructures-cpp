// 3. Ingresar varios números enteros, y de cada uno de ellos, calcular el
// valor factorial (producto de los valores menores o iguales al número).
// Implemente todos los ajustes necesarios para permitir el cálculo
// del factorial también para los valores negativos.

#include <iostream>
using namespace std;
#include "utilidades.h"

// PROTOTIPOS
void leer(int n, int x);
int factorial(int n);
int factorial2(int n);

int main()
{
    int n, x;
    cout << "Ingrese cuantos numeros se calculara el factorial: ";
    cin >> n;
    leer(n, x);
    return 0;
}

void leer(int n, int x)
{
    if (n > 0)
    {
        leer(n - 1, x);
        x = leerN(-32768, 32768);
        if (x > 0)
        {
            cout << "El factorial de " << x << " es: " << factorial(x) << endl;
        }
        else
        {
            cout << "El factorial de " << x << " es: " << factorial2(x) << endl;
        }
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
int factorial2(int n)
{
    if (n < 0)
    {
        return n * factorial2(n + 1);
    }
    else
    {
        return 1;
    }
}