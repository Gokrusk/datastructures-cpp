//GESTIONA UN GRAFO CON LISTA DE ADYACENCIA

#include "GrafoLista.h"
#include "utilidades.h"

int main(){
	GrafoLista g;						//declara un grafo para manipular las clases
	int n;								//cantidad de vertices a crear
	
	GrafoLista ingresarVertices(int n1);
	void ingresarArcos(GrafoLista *g);			//a�ade arcos => grafos no valorados
	void ingresarArcosValor(GrafoLista *g);		//a�ade arcos => grafos valorados
	void imprimirGrafo(GrafoLista g);			//prototipo de la funcion que presenta los vertices del grafo
	void imprimirLista(GrafoLista g);			//prototipo de la funcion que presenta los vertices apuntados desde cada uno, y su peso
	int calcularGradoSalida(GrafoLista g, int i);
	void verticeAccede(GrafoLista g, int i);
	void imprimirGrafo2(GrafoLista g);
	
	cout << endl << "CANTIDAD DE VERTICES DEL GRAFO"<<endl;
	n = leerN(1,20);					//lectura de cantidad de vertices del grafo
	cin.ignore();
	
	g = ingresarVertices(n);				//llamado a funcion de ingreso de los datos referentes al grafo
	//ingresarArcos(&g);					//llamado a la funcion que ingresa los arcos del grafo
	ingresarArcosValor(&g);				//llamado a la funcion que ingresa los arcos valorados del grafo
	imprimirGrafo(g);					//llamado a la funcion que imprime la matriz de adyacencia
	//imprimirLista(g);
	//verticeAccede(g, 3);
	imprimirGrafo2(g);
	cout << endl;
	system("pause");
}

GrafoLista ingresarVertices(int n1){				//funcion que ingresa los datos de los v�rtices de un grafo
	string aux;
	GrafoLista a(n1);

	for (int i = 0; (i < n1); i++){
		cout << endl << "Ingrese el nombre del vertice No. " << (i+1) << ": ";
		getline(cin, aux);
		a.nuevoVertice(aux);
	}
	return a;
}

void ingresarArcos(GrafoLista *g){				//funcion que ingresa los datos de los arcos de un grafo
	int nv = g -> getNumVerts();
	int na;
	string aux;

	for (int i = 0; (i < nv); i++){
		Vertice x = g -> getVertice(i);
		cout << endl << "Vertice No. " << x.getNumero()+1 << " - " << x.getNombre() << " - ";
		cout << endl << "CANTIDAD DE ARCOS DE SALIDA DEL VERTICE"<<endl;
		na = leerN(0, 10);
		cin.ignore();
		
		for (int j = 0; (j < na); j++){
			cout << endl << "Identificador del Vertice Destino: ";
			getline(cin, aux);
			g -> setArco(x.getNombre(), aux);
		}
	}
}

void ingresarArcosValor(GrafoLista *g){			//funcion que ingresa los datos de los arcos de un grafo incluido peso
	int nv = g -> getNumVerts();
	int na;
	int peso;						//peso del arco
	string aux;

	for (int i = 0; (i < nv); i++){
		Vertice x = g -> getVertice(i);
		cout << endl << "Vertice No. " << x.getNumero()+1 << " - " << x.getNombre() << " - ";
		cout << endl << "CANTIDAD DE ARCOS DE SALIDA DEL VERTICE"<<endl;
		na = leerN(0, 10);
		cin.ignore();
		
		for (int j = 0; (j < na); j++){
			cout << endl << "Identificador del Vertice Destino: ";
			getline(cin, aux);
			cout << endl << "PESO DEL ARCO";
			peso = leerN(0, 100);
			cin.ignore();
			g -> setArco(x.getNombre(), aux, peso);
		}
	}
}

int calcularGradoSalida(GrafoLista g, int i) // prototipo de funcion que permite calcular grado
{
	int cont = 0;
	int nv = g.getNumVerts();
	cont = 0;
	for (int j = 0; (j < nv); j++)
	{
		if (g.adyacente(i, j))
		{
			cont++;
		}
	}
	return cont;
}
void verticeAccede(GrafoLista g, int i) {					//retorna el valor del arco almacenado en la matriz de adyacencia para dos numeros de v�rtices que recibe como par�metro por numero
	int nv = g.getNumVerts();
	int x = 0;
	for (int j = 0; j < nv; j++)
	{
		x = g.getArco(j,i);
		if(x != 0)
		{
			Vertice z = g.getVertice(j);
			cout<<z.getNumero()<<endl;
		}
	
	}
}
int calcularGradosEntrada(GrafoLista g, int i) {					//retorna el valor del arco almacenado en la matriz de adyacencia para dos numeros de v�rtices que recibe como par�metro por numero
	int cont = 0;
	int nv = g.getNumVerts();
	cont = 0;
	for (int j = 0; (j < nv); j++)
	{
		if (g.adyacente(j, i))
		{
			cont++;
		}
	}
	return cont;
}
void imprimirGrafo(GrafoLista g){				//funcion que presenta los datos del grafo
	int nv = g.getNumVerts();
	int na;
	string aux;
	cout << endl << "===============================================";
	cout << endl << "L I S T A    D E    A D Y A C E N C I A";

	for (int i = 0; (i < nv); i++){
		Vertice x = g.getVertice(i);
		cout << endl << "Vertice No. " << x.getNumero()+1 << " - " << x.getNombre() << " - "<<"GRADO SALIDA: "<<calcularGradoSalida(g,i);
	
		for (int j = 0; (j < nv); j++){
			if (g.adyacente(i,j)){
				Vertice x = g.getVertice(j);
				cout << endl << "\t\t--->" << x.getNombre();
			}
		}
	}
	cout << endl << "===============================================";
	cout << endl;
}

void imprimirLista(GrafoLista g){				//funcion que presenta los datos del grafo
	int nv = g.getNumVerts();
	NodoG* actual;					//apunta al nodo actual de la lista

	cout << endl << "ELEMENTOS CONTENIDOS EN LA LISTA";

	for (int i = 0; (i < nv); i++){
		Vertice x = g.getVertice(i);
		cout << endl << "Vertice No. " << x.getNumero()+1 << " - " << x.getNombre() << " - ";

		ListaG vlista = g.listaAdyacencia(i);
		actual = vlista.getPrimero();		//copiar la direccion del primer nodo de la lista

		while (actual != NULL){			//repetir el ciclo mientras haya nodos en la lista
			cout << endl << "> " << actual->getDato() << " > " << actual->getPeso();	//visualiza el contenido del nodo actual de la lista
			actual = actual->getPunt();					//apuntador actual avanza al siguiente nodo
		}
	}
}
void imprimirGrafo2(GrafoLista g)
{ // funcion que presenta los datos del grafo con vertices de entrada 
	int nv = g.getNumVerts();
	cout << endl
		 << "===============================================";
	cout << endl << "L I S T A    D E    A D Y A C E N C I A VERTICES DE ENTRADA";

	for (int i = 0; (i < nv); i++)
	{
		Vertice x = g.getVertice(i);
		cout << endl
			 << "Vertice No. " << x.getNumero() + 1 << " - " << x.getNombre() << " - "
			 << "\nGrados Entrada: " << calcularGradosEntrada(g, i);
		;

		for (int j = 0; (j < nv); j++)
		{
			if (g.adyacente(j, i))
			{
				Vertice x = g.getVertice(j);
				cout << endl
					 << "\t\t--->" << x.getNombre();
			}
		}
	}
	cout << endl
		 << "===============================================";
	cout << endl;
}
