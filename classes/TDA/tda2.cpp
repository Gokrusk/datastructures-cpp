//Programa que permite el ingreso y visualizacion de datos en un TDA Pila
#include<iostream>
using namespace std;
#include "pila.h"

int main()
{
	Tipo n;
	int cont=3;
	Pila p;
	cout<<" INSERTAR ELEMENTO EN LA PILA "<<endl;
	for(int i=1;i<=cont;i++)
	{
		cout<<"Ingrese datos a insertar: ";
		cin>>n;
		p.push(n);
	}
	cout<<" ELEMENTOS APILADOS "<<endl;
	for(int i=1;i<=cont;i++)
	{
		cout<<"Valor ingresado: "<<p.pop()<<endl;
	}
	return 0;
}