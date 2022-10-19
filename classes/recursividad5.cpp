// 7. Programa que permita ingresar varios numeros enteros y determinar los valores perfectos, deficientes, abundantes
// Perfecto: suma de divisores propios es igual al mismo numero ej{8: 1, 2, 4 ; 7}
// Deficiente: suma de divisores propios es menor al mismo numero ej{5: 1; 1}
// Abundante: suma de divisores propios es mayor al mismo numero ej{12: 1, 2, 3, 4, 6; 17}
#include <iostream>
using namespace std;
#include "utilidades.h"

// PROTOTIPOS
void leer(int l, int n, int x, int d, int s);
void detDivisores(int n, int x, int d, int *s);
void detPerfDefAbun(int n, int x, int d, int *s);

int main()
{
	int l, n, d, s = 0;
	cout << "Ingrese la cantidad de veces a leer: ";
	cin >> l;
	leer(l, n, n, d, s); // lectura n numeros
}
void leer(int l, int n, int x, int d, int s)
{
	if (l > 0)
	{
		s = 0;
		n = leerN(-32768, 32768); // lectura
		leer(l - 1, n, x, d, s);
		cout << endl
			 << "Divisores de " << n << ": [ ";
		detDivisores(n, n, d, &s); // determinar divisores
		cout << "]" << endl;
		// s-=n;
		if (n == s)
		{

			cout << "El numero " << n << " es perfecto" << endl;
		}
		else if (s < n)
		{
			cout << "El numero " << n << " es deficiente" << endl;
		}
		else if (s > n)
		{
			cout << "El numero " << n << " ses abundante" << endl;
		}
	}
}
void detDivisores(int n, int x, int d, int *s)
{

	if (n > 1)
	{
		detDivisores(n - 1, x, d, s);
	}
	d = x % n;
	detPerfDefAbun(n, x, d, s); // determinar si es perfecto, deficiente, abundante
}
void detPerfDefAbun(int n, int x, int d, int *s)
{

	if (d == 0 && n < x)
	{
		*s += n;
		cout << n << " ";
	}
}