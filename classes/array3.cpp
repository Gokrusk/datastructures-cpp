//3. Insertar, eliminar, buscar un elemento de un vector
#include <iostream>
#define EXT 5 // valor constante
using namespace std;

// PROTOTIPOS
int leerN(int max);
void leerV(int a[], int n);
void printV(int a[], int n);
void printAlrevez(int a[], int n);
void calSumVec(int a[], int *acum, int n);
void insertarElemento(int a[], int *n, int val, int pos);
void eliminarElemento(int a[], int *n, int pos);
int buscarElemento(int a[], int n, int x);

int main()
{
	int v[EXT],			   // definir vector
		acum = 0,		   // acumulador sumar
		n,pos,val,poseli,pos2;				   // cantidad elementos, posicion, valor, posicioneliminar
	n = leerN(EXT);		   // leer cantidad efectiva de valores a procesar
	leerV(v, n);		   // leer vector
	printV(v, n);		   // imprimir vector
	//printAlrevez(v, n);	   // imprimir alrevez
	calSumVec(v, &acum, n); // suma elementos vector
	cout<<"Ingrese el valor a insertar: ";
	cin>>val;
	cout<<"Ingrese la posicion en la que va a insertar: ";
	cin>>pos;
	insertarElemento(v,&n,val,pos);	//insertar elemento
	printV(v,n);
	
	cout<<"Ingrese la posicion a eliminar: ";
	cin>>poseli;
	eliminarElemento(v,&n,poseli);	//eliminar elemento
	printV(v,n);
	
	cout<<"Ingrese elemento a buscar: ";
	cin>>val;
	pos2=buscarElemento(v,n,val);
	if(pos2==-1){
		cout<<"El valor no existe"<<endl;
	}else{
		cout<<"El elemento "<<val<<" se encuentra en la posicion: "<<pos2<<endl;
	}
	
	cout << "Suma de elementos: " << acum << endl;
	system("pause");
}
// DEFINICION DE FUNCIONES
int leerN(int max)
{
	int aux;

	do
	{
		cout << endl
			 << "Ingrese cantidad de valores a procesar [1 .. " << max << "]: ";
		cin >> aux;
		if (aux > max)
		{
			cout << "La cantidad es mayor que " << max << endl;
		}
		else if (aux < 1)
			cout << "La cantidad es menor que 1" << endl;
	} while (aux < 1 || aux > max);
	cout << endl;
	return aux;
}

void leerV(int a[], int n){
	for (int i = 0; i < n; i++)
	{
		cout << "Ingrese un valor entero para la posicion [" << i << "]:" << endl;
		cin >> a[i];
	}
	cout << endl;
}
void printV(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Posicion [" << i << "]: " << a[i] << endl;
	}
	cout << endl;
}
void printAlrevez(int a[], int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		cout << "Posicion [" << i << "]: " << a[i] << endl;
	}
	cout << endl;
}
void calSumVec(int a[], int *acum, int n)
{
	for (int i = 0; i < n; i++)
	{
		*acum += a[i];
	}
	cout << endl;
}
void insertarElemento(int a[], int *n, int val, int pos){
	for(int i=(*n+1);i>pos;i--){//ciclo de recorrido de valores
		a[i] = a[i-1];
	}
	a[pos] = val;//inserta valor
	*n +=1;//incremento cantidad de valores
}
void eliminarElemento(int a[], int *n, int pos){
	for(int i=pos;i<*n;i++){//ciclo recorrido de valores
		if(i < *n-1){
		a[i] = a[i+1];
		}
	}
	*n -=1;
}
int buscarElemento(int a[], int n, int x){
	for(int i=0;i<n;i++)
	{
		if(a[i]==x){
			return i;
		}
	}
	return -1;	//devolver posicion inexistente para indicar no presencia de valor
}