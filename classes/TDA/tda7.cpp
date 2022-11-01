//Programa que permite ordernar descendentemente los elementos de una pila
#include<iostream>
using namespace std;
#include "pila.h"
#include "utilidades.h"


int main()
{
	//PROTOTIPO
	void insertarE(Pila *a);
	void imprimirP(Pila a);
	void ordenarDescPila(Pila *a);
	
	
	Pila p;
	
	cout<<" INSERTAR ELEMENTOS EN LA PILA 1"<<endl;
	insertarE(&p);
		
	cout<<endl<<" ELEMENTOS EXISTENTES EN PILA 1"<<endl;
	imprimirP(p);
	
	cout<<endl<<" PILA ORDENADA DESCENDENTEMENTE"<<endl;
	ordenarDescPila(&p);
	imprimirP(p);
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
	cout<<"Pila: [";
	while(!a.pilaVacia())
	{
		cout<<a.pop()<<" ";
	}
	cout<<"]";
}

void ordenarDescPila(Pila *a) // ordenar descendente
{
    Tipo a1,men;
    Pila b,c;			//pilas auxiliares{b: para calculos / c: para respuesta}
	
	while(!a->pilaVacia())					//mientras no este vacia
	{
		b = *a;								//pila <b> llena
		men = b.pop();						
		
		while(!b.pilaVacia())				//ciclo para buscar valor menor de la pila
		{
			a1 = b.pop();
			if(a1 < men)
			{
				men = a1;				
			}
		}
											//pila <b> se vacia
		c.push(men);						//valor menor se inserta en pila de respuesta
		
	/*	while(!a->pilaVacia())				//ciclo para insertar todos los valores en la pila <b> excepto el valor menor
		{
			a1 = a->pop();
			if(a1 != men)
			{
				b.push(a1);
			}
		}
											//pila <b< llena y pila <a> vacia
		while(!b.pilaVacia())				//ciclo para insertar en pila <a> los valores de pila <b>
		{
			a->push(b.pop());
		}*/
		a.eliminarElementoPila(men);							//pila <b> vacia y pila <a> llena
	}
	*a = c;									//asignar valor de pila <respuesta> a pila <a>
}
	 