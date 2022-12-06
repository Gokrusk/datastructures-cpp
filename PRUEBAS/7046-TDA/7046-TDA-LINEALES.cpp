// Elaborar un programa, haciendo uso de TDA (pilas, colas, listas), que permita el ingreso de una cadena de caracteres,
// y proceda a generar un listado alfabético de las palabrass encontradas en la misma que corresponda a la letra inicial
// ingresada por el usuario. Repetir el proceso de generación de respuestas la cantidad de veces que el usuairio requiera.

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
    t = strlen(f); // Longitud de cadena
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
    string x;
    int cont = 0;
    int aux2 = 0;
    for (int i = 0; i < tamanio; i++) // guarda en que posicion estan los espacios
    {
        if (a[i] == ' ')
        {
            p.push(i);
        }
    }
    do // guarda palabras en una lista, se repite la cantidad de espacios+1
    {
        aux2 = p.pop();     // guarda posicion de espacio (" ")
        while (cont < aux2) // mientras cont no llegue a la posicion de espacio
        {
            // x += a[cont]; // cada caracter se va agregando a una variable string
        cont++;
        }
            cout << cont << endl;
        cont += 2; // avanza a la siguiente palabra
        // cout<<x;
        // l->insertarNodoFinal(x); // se inserta la palabra en una lista
        string x; // se vacia la variable
    } while (cont <= tamanio);
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