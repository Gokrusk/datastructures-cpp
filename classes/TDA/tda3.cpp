//Programa que permite el ingreso y visualizacion de datos en un TDA Pila
#include<iostream>
using namespace std;
#include "pila.h"
#include "utilidades.h"

//PROTOTIPO
void insertarE(int x, Pila *a);
void imprimirP(int x, Pila a);

int main()
{
	Pila p;
	int x;						//Cantidad de valores
	x = leerN(1,EXT);			//funcion para ingresar cantidad de valores
	cout<<" INSERTAR ELEMENTO EN LA PILA "<<endl;
	insertarE(x,&p);
	cout<<" ELEMENTOS APILADOS "<<endl;
	imprimirP(x,p);
	cout<<"Tamanio de la pila: "<<p.tamanioPila()<<endl;
	return 0;
}

void insertarE(int x, Pila *a)			//insertar elementos en pila
{
	Tipo n;	
	for(int i=0;i<x;i++)
		cin>>n;
		a->push(n);
	}
}

void imprimirP(int x, Pila a)			//imprimir elementos de la pila
{
	for(int i=0;i<x;i++)
	{
		cout<<"Valor ingresado: "<<a.pop()<<endl;
	}
}