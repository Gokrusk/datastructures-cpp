#include<iostream>
#define EXT 5					//valor constante
using namespace std;
	
	//PROTOTIPOS
	int leerN(int max);
	void leerV(int a[], int n);
	void printV(int a[], int n);
	void printAlrevez(int a[], int n);
	void calSumVec(int a[], int &acum, int n);
	
int main()
{
	int v[EXT],					//definir vector
		acum=0,					//acumulador sumar
		n; 						//cantidad
	n = leerN(EXT);				//leer cantidad efectiva de valores a procesar
	leerV(v,n);					//leer vector
	printV(v,n);				//imprimir vector
	printAlrevez(v,n);			//imprimir alrevez
	calSumVec(v,acum,n);		//suma elementos vector
	
	cout<<"Suma de elementos: "<<acum<<endl;
	system("pause");
}
	//DEFINICION DE FUNCIONES
	int leerN(int max){
		int aux;
		
		do{
			cout<<endl<<"Ingrese cantidad de valores a procesar [1 .. "<<max<<"]: ";
			cin>>aux;
			if(aux>max){
				cout<<"La cantidad es mayor que "<<max<<endl;
			}else if(aux<1) cout<<"La cantidad es menor que 1"<<endl;
		}while(aux < 1 || aux > max);
		cout<<endl;
		return aux;
	}
	
	void leerV(int a[], int n){
		for(int i=0;i<n;i++)
		{
			cout<<"Ingrese un valor entero para la posicion ["<<i<<"]:"<<endl;
			cin>>a[i];
		}
		cout<<endl;
	}
	void printV(int a[], int n){
		for(int i=0;i<n;i++)
		{
			cout<<"Posicion ["<<i<<"]: "<<a[i]<<endl;
		}
		cout<<endl;
	}
	void printAlrevez(int a[], int n){
		for(int i=n-1;i>=0;i--)
		{
			cout<<"Posicion ["<<i<<"]: "<<a[i]<<endl;
		}
		cout<<endl;
	}
	void calSumVec(int a[], int &acum, int n){
		for(int i=0;i<n;i++)
		{
			acum += a[i];
		}
		cout<<endl;
	}