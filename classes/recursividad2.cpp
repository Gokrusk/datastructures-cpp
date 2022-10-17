//5. Procedimiento recursivo para individualizar digitos
#include<iostream>
using namespace std;
#include "utilidades.h"
//PROTOTIPOS
void individualizarDigito(int x);
int main()
{
	int n;
	n = leerN(-32768,32768);
	individualizarDigito(n);
}
void individualizarDigito(int x)
{
	if(x>10 || x<-10)
	{
		individualizarDigito(x/10);
	}
	cout<<endl<<"> "<<x%10<<endl;
}