// Programa principal para gestion del TDA Vector
#include <iostream>
using namespace std;
#include "Vector.h"

int main()
{
	int n, a, x, op,may=0,men=0;
	Vector v; // instanciar clase vector
	cout << "Ingrese cantidad de elementos: ";
	cin >> n;
	v.setN(n); // definir cantidad de elementos
	v.leerV(); // ingresasr valores por cada elemento del vector
	cout << endl
		 << " CONTENIDO DEL VECTOR " << endl;
	v.imprimirV();
	cout << " ORDENAR "<<endl;
	cout << "1. Burbuja" << endl;
	cout << "2. Insercion" << endl;
	cout << "3. Seleccion" << endl;
	cin >> op;
	switch (op)
	{
	case 1:
		cout << "VECTOR ORDENADO" << endl;
		v.ordenarBubble();
		break;
	case 2:
		cout << "VECTOR ORDENADO" << endl;
		v.ordenarInsercion();
		break;
	case 3:
		cout << "VECTOR ORDENADO" << endl;
		v.ordernarSeleccion();
		break;
	default:
		cout << "No existe opcion" << endl;
		break;
	}
	v.imprimirV();
	cout << endl
		 << " BUSCAR EN EL VECTOR " << endl;
	cout << "Ingres valor a buscar: ";
	cin >> a;
	cout << " BUSCAR "<<endl;
	cout << "1. Lineal" << endl;
	cout << "2. Binaria" << endl;
	cin >> op;
	switch (op)
	{
	case 1:
		x = v.buscar(a);
		break;
	case 2:
		x = v.busquedaBinaria(a);
		break;
	default:
		cout << "No existe opcion" << endl;
		break;
	}

	if (x == -1)
	{
		cout << "no se encuentra" << endl;
	}
	else
	{
		cout << "valor " << a << " se encuentra" << endl;
	}
	cout << endl;
	cout<<"NUMERO MAYOR"<<endl;
	may = v.buscarMayor();
	cout<<"El numero mayor es: "<<may<<endl;
	cout<<"NUMERO MENOR"<<endl;
	men = v.buscarMenor();
	cout<<"El numero mayor es: "<<men<<endl;
	return 0;
}
