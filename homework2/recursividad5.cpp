//5. Determinar si cada número ingresado es un valor primo o compuesto.

#include<iostream>
using namespace std;
#include "utilidades.h"

//PROTOTIPOS
void comprobarPriComp(int n);
void leer(int n, int x);
void primComp(int n);

int main()
{
    int n, x;
    cout<<"Ingrese cuantos numeros a comprobar: ";
    cin>>n;
    leer(n,x);
    return 0;
}

void leer(int n, int x)
{
    if(n>0)
    {
        leer(n-1,x);
        x = leerN(-32768, 32768);
    }
}
void primComp(int n)
{
    if(n>0)
    {
        primComp(n - 1);
    }
    
}