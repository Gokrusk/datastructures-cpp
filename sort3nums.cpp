//BUSCAR NUMERO MAYOR
//ORDENAR ASCENDENTE Y DESCENDENTE

#include <iostream>
using namespace std;

int main()
{
	int a, b, c, may=0,men=0,men2=0, op;
	

		cout<<"ingrese 3 numeros"<<endl;
		cin>>a;
		cin>>b;
		cin>>c;
		
		if(a == b && a == c && b == c){
			cout<<"Numeros iguales"<<endl;
		}else if(a > b && a > c){
			may = a;
			cout<<"mayor: "<<may<<endl;	
			
		}else if(b > a && b > c){
			may = b;
			cout<<"mayor: "<<may<<endl;	
		}else{
			may = c;
			cout<<"mayor: "<<may<<endl;	
		}
		
		cout<<"1. Ascendente\n";
		cout<<"2. Descendente\n";
		cout<<"Opcion: "; cin>>op;
		
		switch(op){
			case 1:
				if(a < may  && a < b){
					men = a;
				}else if(b < may && b < a){
					men = b;
				}else{
					men = c;
				}
		
				if(a < may && a > men){
					men2 = a;
				}else if(b < may && b > men){
					men2 = b;
				}else men2 = c;
				
				cout<<"Ordenado:"<<endl;
				cout<<men<<endl<<men2<<endl<<may<<endl;
				
				break;
			case 2:
				cout<<"Ordenado:"<<endl;
				cout<<may<<endl<<men2<<endl<<men<<endl;
				break;
			default: cout<<"No existe opcion"<<endl;
		}
		
			
	return 0;
}                                        