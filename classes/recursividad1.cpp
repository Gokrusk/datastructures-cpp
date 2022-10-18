// 4. Programa que imprime un mensaje repetidamente
#include <iostream>
using namespace std;
#include "utilidades.h"

// PROTOTIPOS
void imprimirMensaje(int n);
int main()
{
	int n;
	cout << "Ingrese la cantidad de mensajes a imprimir" << endl;
	n = leerN(-32768, 32768); // lectura cantidad de repeticiones
	imprimirMensaje(n);		  // impresion
	cout << endl;
	system("pause");
}
// DEFINICION DE FUNCIONES
void imprimirMensaje(int x)
{
	if (x > 1)
	{
		imprimirMensaje(x - 1);
	}
	cout << endl
		 << x << ". Hola mundo...\t";
}