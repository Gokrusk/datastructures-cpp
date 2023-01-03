// grafo0.cpp
// implementa gestion de un conjunto de vertices

#include "Vertice.h"
#include "utilidades.h"

int main(){
	system("color fc");
	Vertice* v;									//arreglo de vertices
	int n;										//variable indicadora de cantidad de vertices
	
	cout << endl << "CANTIDAD DE VERTICES A INGRESAR" << endl;
	n = leerN(1, 100);							//lectura de cantidad de vertices a procesar
	v = new Vertice[n];							//creacion dinamica de n vertices en el arreglo
	
	void ingresarVertices(Vertice* v1, int n1);	//prototipo de funcion que permite ingreso de datos para vertice
	void imprimirVertices(Vertice* v1, int n1);	//prototipo de funcion que imprime los datos de cada vertice	
	void buscarVerticesPorNombre(Vertice* v1, int n1);	//prototipo de funcion que busca un valor entre arreglo de vertices
	void buscarVerticesPorNumero(Vertice* v1, int n1);	//prototipo de funcion que busca un valor entre arreglo de vertices
	
	ingresarVertices(v, n);						//llamado a funcion que ingresa valores de vertices
	imprimirVertices(v, n);						//llamado a funcion que imprime valores de los vertices
	buscarVerticesPorNombre(v, n);				//llamado a funcion que implemente busqueda de vertices
	buscarVerticesPorNumero(v, n);				//llamado a funcion que busca vertices por numero

	cout << endl;
	system("pause");
}

void ingresarVertices(Vertice* v1, int n1){		//funcion que permite ingreso de datos para vertice
	string aux;									//var de lectura
	cout << endl << "INGRESO DE DATOS DE LOS VERTICES" << endl;
	for (int i = 0; i < n1; i++){
		cout << endl << "Vertice No. " << i;
		cout << endl << "Nombre: ";
		cin >> aux;
		v1[i].setNombre(aux);
		v1[i].setNumero(i);
	}
}

void imprimirVertices(Vertice* v1, int n1){		//funcion que imprime los datos de cada vertice	
	cout << endl << "IMPRESION DE DATOS DE LOS VERTICES" << endl;
	for (int i = 0; i < n1; i++){
		cout << endl << "Vertice No. " << v1[i].getNumero() << " - Nombre: " << v1[i].getNombre();
	}
}

void buscarVerticesPorNombre(Vertice* v1, int n1){		//funcion que busca un valor entre arreglo de vertices
	int n;										//cantidad de valores a buscar
	string aux;									//var de lectura
	bool enc;									//var bandera indicadora de valor encontrado
	
	cout << endl << "BUSQUEDA DE VERTICES POR NOMBRES INGRESADOS";
	cout << endl << "CANTIDAD DE VALORES A BUSCAR";
	n = leerN(1,100);	

	for (int i=1; i <= n; i++){					//ciclo de lectura de valores a buscar
		cout << endl << "Nombre a buscar: ";
		cin >> aux;
		enc = false;							//inicializacion de var bandera
		for (int j = 0; (j < n1); j++){			//ciclo de recorrido del arreglo de vertices
			if (v1[j].igual(aux)){				//metodo que compara devuelve verdadero
				cout << endl << "Valor encontrado....";
				cout << endl << "Vertice No. " << v1[j].getNumero() << " - Nombre: " << v1[j].getNombre();
				enc = true;						//actualiza indicador de encuentro
			}
		}
		if (!enc){								//este valor no se encontro entre los vertices
			cout << endl << "Valor NO encontrado entre los vertices ingresados....";
		}		
		cin.clear();
	}
}

void buscarVerticesPorNumero(Vertice* v1, int n1){		//funcion que busca un valor entre arreglo de vertices
	int n;										//cantidad de valores a buscar
	int aux;									//var de lectura
	bool enc;									//var bandera indicadora de valor encontrado
	
	cout << endl << "BUSQUEDA DE VERTICES POR NUMEROS INGRESADOS";
	cout << endl << "CANTIDAD DE VALORES A BUSCAR";
	n = leerN(1,100);	

	for (int i=1; i <= n; i++){					//ciclo de lectura de valores a buscar
		cout << endl << "Numero a buscar: ";
		cin >> aux;
		enc = false;							//inicializacion de var bandera
		for (int j = 0; (j < n1); j++){			//ciclo de recorrido del arreglo de vertices
			if (v1[j].igual(aux)){			//metodo que compara devuelve verdadero
				cout << endl << "Valor encontrado....";
				cout << endl << "Vertice No. " << v1[j].getNumero() << " - Nombre: " << v1[j].getNombre();
				enc = true;						//actualiza indicador de encuentro
			}
		}
		if (!enc){								//este valor no se encontro entre los vertices
			cout << endl << "Valor NO encontrado entre los vertices ingresados....";
		}		
	}
}
