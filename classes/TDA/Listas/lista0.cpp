// PROGRAMA QUE PERMITE IMPLEMENTAR NODOS
#include "nodo.h"
using namespace std;

int main()
{
    //PROTOTIPOS
    void leerDatoNodo(Nodo *a);                                 //funcion que permite ingreso de dato para un nodo
    void imprimirNodo(Nodo a);                                  //funcion que permite visualizar los valores almacenados en un nodo
    Nodo n;
    Nodo n1(100,&n); // Declaracion de objeto de tipo nodo
    Tipo aux;
    leerDatoNodo(&n);
    //leerDatoNodo(&n1);
    imprimirNodo(n);
    imprimirNodo(n1);
    
    return 0;
}

void leerDatoNodo(Nodo *a)                                 //funcion que permite ingreso de dato para un nodo
{
    Tipo aux;
    cout << endl << "Ingrese valor para almacenar en el nodo 1: ";
    cin >> aux;
    a->setDato(aux); // almacenar un valor en el atributo dato del objeto nodo
}
void imprimirNodo(Nodo a)                                  //funcion que permite visualizar los valores almacenados en un nodo
{
    cout << endl
         << "El valor almacenado es: " << a.getDato();
    cout << endl << "El nodo apunta a: " << a.getPunt() << endl;
}