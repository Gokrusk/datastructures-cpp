// heaps01
// programa que implementa uso de un heap

#include <stdlib.h>			//para posibilitar empleo rand
#include "monticulo.h"
#include "utilidades.h"

int main(){											//programa principal
	int n;
	
	n = leerN(1,20);								//cantidad de elementos
	Monticulo m(n);									//creacion de monticulo
	
	void leerMonticulo(Monticulo * m1, int n1);		//prototipo de la funcion que lee un monticulo de datos
	void imprimirMonticulo(Monticulo m1, int n1);	//prototipo de la funcion que imprime un monticulo
	void imprimirMinimo(Monticulo m1);				//prototipo de la funcion que imprime el valor minimo del monticulo
	void eliminarMinimo(Monticulo *m1);				//prototipo de la funcion que elimina el valor minimo del monticulo y lo reordena
	void ordenacionVectorHeaps();					//prototipo de la funcion que demuestra ordenacion de vector por medio de heaps

	leerMonticulo(&m, n);							//llamada a ingreso de monticulo
	imprimirMonticulo(m, n);						//llamada a impresion de monticulo

	imprimirMinimo(m);

	eliminarMinimo(&m);
	imprimirMonticulo(m, n);

	ordenacionVectorHeaps();						//llama a funcion demostrativa de ordenamiento vectores => metodo 1
	
	cout << endl;
	system("pause");
}

void leerMonticulo(Monticulo* m1, int n1){		//funcion que lee n datos y los inserta en un monticulo
	Clave aux;

	cout << endl << "INGRESO DE ELEMENTOS EN UN MONTICULO";
	for (int i=0; i < n1; i++){					//ciclo
		cout << endl << "Ingrese un valor: ";
		cin >> aux;
		m1->Insertar(aux);						//insercion de elemento en monticulo
	}
}

void imprimirMonticulo(Monticulo m1, int n1){	//funcion que imprime un monticulo
	Clave aux;									

	cout << endl << "IMPRESION DE ELEMENTOS DESDE MONTICULO";
	for (int i = 0; i < m1.getNumDatosAct(); i++){
		aux = m1.getValor(i);						//calcula valor extraido del monticulo
		cout << endl << "Valor obtenido del Monticulo: " << aux;
	}
}

void imprimirMinimo(Monticulo m1){				//funcion que imprime el valor minimo del monticulo
	cout << endl << "El valor minimo incluido en el Monticulo es : " << m1.BuscarMinimo();
}

void eliminarMinimo(Monticulo *m1){				//funcion que elimina el valor minimo del monticulo y lo reordena
	Clave min;
	
	cout << endl << "Eliminando el valor minimo incluido en el Monticulo .......";
	min = m1 -> EliminarMinimo();				//elimina el valor minimo 
	cout << endl << "El valor eliminado del Monticulo es: " << min;
}

void ordenacionVectorHeaps(){					//funcion que demuestra ordenacion de vector por medio de heaps
	cout << endl << "CANTIDAD DE ELEMENTOS A GENERAR";
	int n = leerN(1, 10);

	Monticulo m2(n);								//construye el monticulo

	Clave *v0;									//declara vector de valores originales
	v0 = new Clave[n];							//crear elementos en el arreglo
	
	cout << endl << " V A L O R E S     O R I G I N A L E S" << endl;
	for (int i = 0; i < n; i++){				//llena el vector con valores aleatorios
		v0[i] = rand()%51;						//genera un valor aleatorio entre 0 y 50
		cout << " " << v0[i];					//genera un valor aleatorio
	}

	m2.ordenar(v0, n);				//llama a metodo de ordenamiento
	
	cout << endl << " V A L O R E S     O R D E N A D O S" << endl;
	for (int i = 0; i < n; i++){								//RECORRE el vector con valores ordenados
		cout << " " << v0[i];
	}
}
