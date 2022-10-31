//Programa que permite el ingreso de pilas de valores y determine si son iguales
#include<iostream>
using namespace std;
#include "pila.h"
#include "utilidades.h"


int main()
{
	//PROTOTIPO
	void insertarE(Pila *a);
	void imprimirP(int x, Pila a);
	bool comparacionPilas(Pila a, Pila b);
	
	Pila p,q;
	bool comp;
	cout<<" INSERTAR ELEMENTOS EN LA PILA 1"<<endl;
	insertarE(&p);
	cout<<" INSERTAR ELEMENTOS EN LA PILA 2"<<endl;
	insertarE(&q);
	
	cout<<endl<<" ELEMENTOS APILADOS PILA 1"<<endl;
	imprimirP(1, p);
	cout<<endl<<" ELEMENTOS APILADOS PILA 2"<<endl;
	imprimirP(2, q);
	
	cout<<endl;
	if(p.tamanioPila() == q.tamanioPila())
	{
		comp = comparacionPilas(p,q);	
		if(comp)
		{
			cout<<endl<<"Las pilas son iguales"<<endl;
		}else cout<<endl<<"Las pilas no son iguales"<<endl;
	}else cout<<endl<<"Las pilas no son iguales"<<endl;
	
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

void imprimirP(int x, Pila a)			//imprimir elementos de la pila
{	
	cout<<"Pila "<<x<<": [";
	while(!a.pilaVacia())
	{
		cout<<a.pop()<<" ";
	}
	cout<<"]";
}

bool comparacionPilas(Pila a, Pila b)
{
	
	while(!a.pilaVacia())			//ya se sabe q tienen el mismo tamanio
	{
		if(a.pop() != b.pop())
		{
			return false;
		}
	}
	return true;
}