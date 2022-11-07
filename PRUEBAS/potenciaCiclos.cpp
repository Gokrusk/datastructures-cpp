// Programa que permita realizar A elevado a la B, mediante sumas sucesivas por recursividad.

#include <iostream>
using namespace std;
#include "utilidades.h"

int main()
{
	// PROTOTIPOS
	int calcularProducto(int a, int b);
	int exponente(int a, int b, int c);

	int A, B, P = 0, N = 1, C=0;
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
		P = exponente(A,B,C);
		cout << A << " elevado a " << B << " = " <<P<< endl;
	}
	return 0;
}

int  calcularProducto(int a, int b)
{
	int c=0;
	for(int i=0; i<b;i++)
	{
		c+=a;
	}
	return c;
}

int exponente(int a, int b, int c)
{
	int ex=0;
	for(int j=0; j<b;j++)
	{
		ex = calcularProducto(a,b);
		c = calcularProducto(ex,b);
	}
	return c;
}

//3 al cubo : v2(v1(3 * 3) * 3) = v1(3 + 3 + 3) ? v2(9 + 9 + 9) ? v3(27 + 27 + 27)