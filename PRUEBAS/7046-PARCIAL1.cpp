// Programa que permita realizar A elevado a la B, mediante sumas sucesivas por recursividad.

#include <iostream>
using namespace std;
#include "utilidades.h"

int main()
{
	// PROTOTIPOS
	void base(int a, int b, int *p, int *n);
	void cicloExp(int a, int b, int *p, int *n);
	void inicio(int a, int b, int p, int n);

	int A, B, P = 0, N = 1;
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
		cicloExp(A,B,&P,&N);
		cout << A << " elevado a " << B << " = " << N << endl;
	}
	return 0;
}

void base(int a, int b, int *p, int *n)			//ciclo para llenar p con la base
{
	if(a > 0)	
	{
		*p += *n;
		base(a-1,b,p,n);
	}
	*n = *p;
}
void cicloExp(int a, int b, int *p, int *n)		//ciclo de sumas sucesivas segun exponente
{
	if (b > 0)
	{
		*p = 0;
		base(a,b,p,n);
		cicloExp(a, b - 1, p,n);
	}
}

// 2 al cuadrado:
/*
	cicloexp(...)				se repite las veces del expo	(2)
		vuela 1
		p = 0
		base(...) -> n=1		se repite las veces de la base	(2)
		p = p + n
		p = 2
		n = 2
		vuelta 2 -> n = 2
		p = p + n
		p = 4
		n = 4
	2 al cuadrado = 4
*/

// 3 al cubo:
/*
	cicloexp(...)				se repite las veces del expo	(3)
		vuela 1
		p = 0
			base(...) -> n=1		se repite las veces de la base	(3)
			p = p + n
			p = 3
			n = 3
		vuelta 2 -> n = 3 / p = 0
		p = p + n
		p = 9
		n = 9
		vuelta 3 -> n = 9 / p =0
		p = p + n
		p = 27
		n = 27
	3 al cubo = 27
*/