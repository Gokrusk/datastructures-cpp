//Programa que permite el ingreso y visualizacion de datos en un TDA Pila
#include<iostream>
using namespace std;
#include "pila.h"
#include "utilidades.h"


int main()
{
	//PROTOTIPO
	void insertarE(Pila *a);
	void imprimirP(Pila a);
	
	Pila p;
	cout<<" INSERTAR ELEMENTO EN LA PILA "<<endl;
	insertarE(&p);
	cout<<endl<<" ELEMENTOS APILADOS "<<endl;
	imprimirP(p);
	cout<<"Tamanio de la pila: "<<p.tamanioPila()<<endl;
	return 0;
}

void insertarE(Pila *a)			//insertar elementos en pila
{
	Tipo n;	
	int fin=999;
	cout<<" -> Nota: Para detener ingreso digite 999 <- "<<endl;
	do
	{
		cout<<"Ingrese valores a la pila: ";
		cin>>n;
		if(n != fin)		//el usuario desea apilar
		{
			a->push(n);		//apilar
		}
		
	}while(n!=fin);
}

void imprimirP(Pila a)			//imprimir elementos de la pila
{	
	while(!a.pilaVacia())
	{
		cout<<"Valor ingresado: "<<a.pop()<<endl;
	}
}