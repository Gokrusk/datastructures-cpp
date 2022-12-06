// Elaborar un programa, haciendo uso de TDA (pilas, colas, listas), que permita el ingreso de una cadena de caracteres,
// y proceda a generar un listado alfabético de las palabrass encontradas en la misma que corresponda a la letra inicial
// ingresada por el usuario. Repetir el proceso de generación de respuestas la cantidad de veces que el usuairio requiera.

//Notas: 1. Contar caracteres
//2. Insertar cada palabra en lista
//3. Ordenar
//4. Separar lista
#include <iostream>
#include "pila.h"
#include "lista.h"
using namespace std;

int main()
{
    // PROTOTIPOS
    void leerFrase(char a[EXT]); // Lectura de frase
    void separarPalabras(char a[EXT], int tamanio, Lista *l);
    void imprimirPalabras(Lista l);
    Pila frase;
    Lista a;
    char f[EXT];
    int t = 0, n, i = 0;
    leerFrase(f);
    t = 0; // Longitud de cadena
    separarPalabras(f, t, &a);
    imprimirPalabras(a);
}

void leerFrase(char a[EXT])
{
    cout << "Ingrese la frase: ";
    cin.getline(a, EXT, '\n');
}

void separarPalabras(char a[EXT], int tamanio, Lista *l)
{
    Pila b, p;
    char aux[50];
    int cont = 0, cont2 = 0, aux2 = 0;
    string x, y;
    for (int i = 0; i < tamanio; i++) // guarda en que posicion estan los espacios
    {
        if (a[i] == ' ')
        {
            p.push(i);
            cont2++;
        }
    }
    for (int i = 0; i < tamanio; i++) // guarda en que posicion estan los espacios
    {
        if (a[i] == ' ')
        {
            p.push(i);
            cont2++;
        }
    }
    cout<<cont2<<endl;
    //p.push(cont2);
    while (!p.pilaVacia())
    {
        b.push(p.pop());
    }
    do // guarda palabras en una lista, se repite la cantidad de espacios+1
    {
        string x;           // se vacia la variable
        aux2 = b.pop();     // guarda posicion de espacio (" ")
        while (cont < aux2) // mientras cont no llegue a la posicion de espacio
        {
            x += a[cont]; // cada caracter se va agregando a una variable string
            cont++;
        }
        cont += 1; // avanza a la siguiente palabra
        l->insertarNodoFinal(x); // se inserta la palabra en una lista
        x = y;
    } while (cont <= cont2);
}

void imprimirPalabras(Lista a)
{
    // recorrido de la lista
    Nodo *actual; // referencia a nodo actual de la lista
    cout << endl
         << " VALORES ALMACENADOS EN LA LISTA " << endl;
    actual = a.getPrimero(); // almacena temporalmente la posicion del primer nodo
    while (actual != NULL)   // repetir mientras no se alcance el final de la lista
    {
        cout << "> " << actual->getDato() << endl;
        actual = actual->getPunt(); // desplaza el puntero actual al siguiente nodo de la lista
    }
    cout << endl;
}