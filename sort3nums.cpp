//BUSCAR NUMERO MAYOR
//ORDENAR ASCENDENTE Y DESCENDENTE

#include <iostream>
using namespace std;

int main()
{
    int a, b, c, may=0, med, men,op;
    cout << "Ingrese 3 numeros" << endl;
    cin >> a;
    cin >> b;
    cin >> c;

    if (a == b && a == c && b == c){
        cout<<"Los numeros son iguales"<<endl;
    }else if(a >= b && a > c){
        may = a;
    }else if(b > a && b >= c){
        may = b;
    }else if(c >= a && c > b){
        may = c;
    }

    cout<<"El mayor: "<<may<<endl;

    if(a < b && a < c){
        men = a;
    }else if(b < a && b < c){
        men = b;
    }else men = c;

    if(a < may && a > men){
        med = a;
    }else if(b < may && b > men){
        med = b;
    }else med = c;

    cout<<"1. Ascendente"<<endl;
    cout<<"2. Descendente"<<endl;
    cin>>op;

    switch (op)
    {
    case 1:
            cout<<"Ordenado:"<<endl;
            cout<<men<<endl<<med<<endl<<may<<endl;
        break;
    case 2:
            cout<<"Ordenado:"<<endl;
            cout<<may<<endl<<med<<endl<<men<<endl;
        break;
    default:
            cout<<"No existe la opcion"<<endl;
        break;
    }
    
    
    return 0;
}