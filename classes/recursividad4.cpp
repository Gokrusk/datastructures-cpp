//6. Procedimiento recursivo para verificar si un numero es capícua (se lee igual al revez)
#include<iostream>
using namespace std;
#include "utilidades.h"
//PROTOTIPOS
void individualizarDigito(int x,int *s, int *aux);
int main()
{
	int n, s=0,aux=0;
	n = leerN(-32768,32768);
	individualizarDigito(n,&s,&aux);
	cout<<endl<<"Suma de los digitos: "<<s<<endl;
	cout<<aux<<endl;
	if(n == aux)
	{
		cout<<"\tEs capicua";
	}else{
		cout<<"\tNo es capicua";
	}
	
}
void individualizarDigito(int x,int *s, int *aux)
{
	*aux *= 10;
	*aux += x%10;
	if(x>10 || x<-10)
	{
		individualizarDigito(x/10,s,aux);
	}
	cout<<endl<<"> "<<x%10<<endl;
	*s+=x%10;
}