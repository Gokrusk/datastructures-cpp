// 4. Calcular el cociente y el residuo obtenidos de dividir cada una de
// varias parejas de números mediante la aplicación del algoritmo de
// restas sucesivas.

#include <iostream>
using namespace std;
#include "utilidades.h"

// PROTOTIPOS
void division(int dividendo, int divisor, int *resto, int *cociente);
void leer(int n, int dividendo, int divisor, int resto, int cociente);

int main()
{
    int divisor, dividendo, resto, cociente, n;
    cout << "Ingrese la cantidad de divisiones a realizar: ";
    cin >> n;
    leer(n, divisor, dividendo, resto, cociente);
    return 0;
}

void leer(int n, int dividendo, int divisor, int resto, int cociente)
{
    if (n > 0)
    {
        do
        {
            leer(n - 1, dividendo, divisor, resto, cociente);
            cout << "Ingrese dividendo: ";
            cin >> dividendo;
            cout << "Ingrese divisor: ";
            cin >> divisor;
            resto = dividendo;
            cociente = 0;
            if (dividendo < 0 || divisor < 0)
            {
                cout << "dividendo o divisor no puede ser negativo" << endl;
            }
        } while (dividendo < 0 || divisor < 0);
        division(dividendo, divisor, &resto, &cociente);
        cout << "Cociente: " << cociente << endl;
        cout << "Resto: " << resto << endl;
    }
}
void division(int dividendo, int divisor, int *resto, int *cociente)
{
    if (*resto >= divisor)
    {
        *resto = *resto - divisor;
        *cociente = *cociente + 1;
        division(dividendo, divisor, resto, cociente);
    }
}