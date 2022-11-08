// Programa que permita realizar A elevado a la B, mediante sumas sucesivas por recursividad.

#include <iostream>
using namespace std;
#include "utilidades.h"

int main()
{
	// PROTOTIPOS
	void calcularProducto(int a, int b, int *c);
	void exponente(int a, int b, int *c);
	int potencia(int a, int b, int p);

	int A, B, P = 0, C = 0;
	cout << "Ingrese A: ";
	A = leerN(0, 32768); // lectura A
	cout << "Ingrese B: ";
	B = leerN(0, 32768); // lectura B

	if (B == 0)
	{
		cout << A << " elevado a " << B << " = 1" << endl;
	}
	else
	{
		C = potencia(A,B,P);
		cout << A << " elevado a " << B << " = " << C << endl;
	}
	return 0;
}

int potencia(int a, int b, int p)
{
	int n = 1;
	for (int i = 0; i < b; i++)
	{
		p = 0;
		for (int j = 0; j < a; j++)
		{
			p += n;
		}
		n = p;
	}
	return p;
}

// 3 al cubo : v2(v1(3 * 3) * 3) = v1(3 + 3 + 3) ? v2(9 + 9 + 9) ? v3(27 + 27 + 27)