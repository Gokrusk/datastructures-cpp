//Implementar el uso del TDA Cola
#include<iostream>
using namespace std;
#include "utilidades.h"
#include "cola.h"

int main()
{
	Cola c;											//Instancia del TDA Cola
	Tipo val;
	int n;
	cout<<"Ingrese la cantidad de elementos a insertar: ";
	cin>>n;
	cout<<"1. TAMANIO QUEUE: "<<c.tamanioCola()<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<"Elemento "<<i<<": ";
		cin>>val;
		c.insertarVal(val);
	}
	cout<<endl;
	cout<<"2. TAMANIO QUEUE: "<<c.tamanioCola()<<endl;
	cout<<" ELEMENTOS IN QUEUE "<<endl;
	cout<<"[ ";
	for(int i=0;i<n;i++)
	{
		cout<<c.extraerVal()<<" ";
	}
	cout<<"]"<<endl;
	
	cout<<"3. TAMANIO QUEUE: "<<c.tamanioCola()<<endl;
	
	cout<<endl;
	system("pause");
}

