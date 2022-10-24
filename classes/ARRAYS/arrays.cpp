#include <iostream>
#define EXT 5
using namespace std;

// PROTOTIPOS
void leerV(int a[]);
void printV(int a[]);
void printAlrevez(int a[]);
void calSumVec(int a[], int &acum);

int main()
{
	// DEFINIR VECTOR
	int v[EXT],
		// ACUMULADOR DE SUMA
		acum = 0;
	// LECTURA VECTOR
	leerV(v);
	// IMPRIMIR VECTOR
	printV(v);
	// IMPRIMIR ALREVEZ
	printAlrevez(v);
	// SUMA ELEMENTOS DE VECTOR
	calSumVec(v, acum);

	cout << "Suma de elementos: " << acum << endl;
	system("pause");
}
// DEFINICION DE FUNCIONES
void leerV(int a[])
{
	for (int i = 0; i < EXT; i++)
	{
		cout << "Ingrese un valor entero para la posicion [" << i << "]:" << endl;
		cin >> a[i];
	}
	cout << endl;
}
void printV(int a[])
{
	for (int i = 0; i < EXT; i++)
	{
		cout << "Posicion [" << i << "]: " << a[i] << endl;
	}
	cout << endl;
}
void printAlrevez(int a[])
{
	for (int i = EXT - 1; i >= 0; i--)
	{
		cout << "Posicion [" << i << "]: " << a[i] << endl;
	}
	cout << endl;
}
void calSumVec(int a[], int &acum)
{
	for (int i = 0; i < EXT; i++)
	{
		acum += a[i];
	}
	cout << endl;
}