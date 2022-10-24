//6. Procedimiento recursivo para sumar digitos
#include<iostream>
using namespace std;
#include "utilidades.h"
//PROTOTIPOS
void individualizarDigito(int x,int *s);
int main()
{
	int n, s=0;
	n = leerN(-32768,32768);
	individualizarDigito(n,&s);
	cout<<endl<<"Suma de los digitos: "<<s<<endl;
}
void individualizarDigito(int x,int *s)
{
	if(x>10 || x<-10)
	{
		individualizarDigito(x/10,s);
	}
	cout<<endl<<"> "<<x%10<<endl;
	*s+=x%10;	
}