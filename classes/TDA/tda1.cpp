//Programa principal para gestion del TDA Vector
#include<iostream>
using namespace std;
#include "Vector.h"

int main()
{
	int n,a,x;
	Vector v;	//instanciar clase vector
	cout<<"Ingrese cantidad de elementos: ";
	cin>>n;
	v.setN(n);	//definir cantidad de elementos
	v.leerV();	//ingresasr valores por cada elemento del vector
	cout<<endl<<" CONTENIDO DEL VECTOR "<<endl;
	v.imprimirV();
	cout<<endl<<" BUSCAR EN EL VECTOR "<<endl;
	cout<<"Ingres valor a buscar: ";
	cin>>a;
	x = v.buscar(a);
	if(x == -1)
	{
		cout<<"no se encuentra"<<endl;
	}else{
		cout<<"valor "<<a<<" se encuentra"<<endl;
	}
	
	
	return 0;
}
