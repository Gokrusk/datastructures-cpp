// ArbolBinario2.cpp
// implementa un AB basico con proceso de lectura e impresion

#include "ArbolBinario.h"

int main(){					//programa principal
	system("color f0");
	ArbolBinario a;			//declara un Arbol binario
	
	void leerAB(ArbolBinario *b);			//prototipo de funcion ingreso AB
	void imprimirAB(ArbolBinario a);		//prototipo de funcion que imprime AB
	void verDatosAB(ArbolBinario a);		//visualizar datos generales de un arbol
	void verHojasAB(ArbolBinario a);		//visualizar los nodos hoja del Ab
	void recorrerAB(ArbolBinario a);		//protipo de la funcion que implementa los diversos recorridos de un AB
	void buscarNodoEnABB(ArbolBinario a);	//prototipo de la funcion que realiza la busqueda de un nodo en un ABB
	
	leerAB(&a);								//llamado a funcion de ingreso AB
	verDatosAB(a);							//llamado a impresion datos generales AB
	imprimirAB(a);							//llamado a funcion que imprime un AB
	verHojasAB(a);							//llamado a impresion de nodos hoja del AB
	recorrerAB(a);							//llamado a recorrido del AB
	buscarNodoEnABB(a);						//llamado a la funcion que realiza la busqueda de un nodo en un ABB
	
	cout << endl;
	system("pause");
}

//==================================================================================================

void leerAB(ArbolBinario *b){
	cout << endl << "LECTURA DE ARBOL BINARIO" << endl << endl;
	b -> leer();							//llama a metodo de lectura de nodos de AB
}

//==================================================================================================

void imprimirAB(ArbolBinario a){
	cout << endl << "IMPRESION DE ARBOL BINARIO" << endl << endl;
	//a.imprimirABSimple(a.getRaiz());	//llama metodo impresion simple de AB
	a.imprimirABJerarquia(a.getRaiz(), 0);	//llama a metodo impresion con formato jerarquico de AB
}

//==================================================================================================

void verDatosAB(ArbolBinario a){		//visualizar datos generales de un arbol
	cout << endl << "IMPRESION DE DATOS GENERALES DE ARBOL BINARIO" << endl << endl;
	cout << endl << "El arbol " << (a.esVacio() ? "SI" : "NO") << " esta vacio";
	cout << endl << "El arbol posee " << a.contarNodos(a.getRaiz()) << " nodos";
	cout << endl << "La altura del arbol es " << a.calcularAltura(a.getRaiz());
	cout << endl << "El nodo raiz es: " << a.getRaiz()->getDato();
}

//==================================================================================================

void verHojasAB(ArbolBinario a){		//visualizar los nodos hoja del Ab
	cout << endl << "IMPRESION DE NODOS HOJA DE ARBOL BINARIO" << endl << endl;
	a.verHojas(a.getRaiz());			//llama a metodo que visualiza nodos hoja del AB
}

//==================================================================================================

void recorrerAB(ArbolBinario a){		//funcion que implementa los diversos recorridos de un AB
	cout << endl << "RECORRIDOS DE ARBOL BINARIO" << endl << endl;
	cout << endl << "RECORRIDO EN PREORDEN" << endl;
	a.recorrerEnPreorden();		//llama al metodo correspondiente
	cout << endl << "RECORRIDO EN INORDEN" << endl;
	a.recorrerEnInorden();		//llama al metodo correspondiente
	cout << endl << "RECORRIDO EN POSORDEN" << endl;
	a.recorrerEnPostorden();		//llama al metodo correspondiente
}

//==================================================================================================

void buscarNodoEnABB(ArbolBinario a){	//funcion que realiza la busqueda de un nodo en un ABB
	Tipo aux;							//var de lectura
	
	cout << endl << "BUSQUEDA DE UN VALOR DENTRO DE UN ABB" << endl << endl;
	cout << endl << "Ingrese el valor a buscar: ";
	cin >> aux;
	cout << endl << "El valor ingresado " << (a.buscarNodo(aux) ? "SI" : "NO") << " se encuentra entre los nodos del ABB";
}

//==================================================================================================

