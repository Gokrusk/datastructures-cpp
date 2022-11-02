//Programa que permita realizar A elevado a la B, mediante sumas sucesivas por recursividad.

#include<iostream>
using namespace std;
#include "utilidades.h"

int main()
{
	//PROTOTIPOS
	void potencia(int a, int b, int *p);
	
	int A=0,B,P=0,N=1;
	cout<<"Ingrese A: ";
	A = leerN(0,32768);			//lectura A
	cout<<"Ingrese B: ";
	B = leerN(0,32768);			//lectura B
	
	P = A;									//exponente 0
	if(B == 0)
	{
		cout<<A<<" elevado a "<<B<<" = 1"<<endl;
	}else
	{
		potencia(A,B,&P);
		cout<<A<<" elevado a "<<B<<" = "<<P<<endl;
	}
	return 0;
}

void potencia(int a, int b, int *p)
{
	if(b > 1)
	{
		potencia(a,b-1,p);d
		*p += *p;
	}	
}
