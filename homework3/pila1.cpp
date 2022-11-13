// Programa que utilice una pila para determinar si cada una de las frases ingresadas por el usuario
// es un palíndromo (frase cuya lectura directa e indirecta es igual: ana, alila, etc).
#include <iostream>
#include <curses.h>
#include <cstring>
using namespace std;
#include "pila1.h"

int main()
{
    // PROTOTIPOS
    void leerFrase(char a[EXT]);                                    //Lectura de frase
    void apilarFrase(Pila * b, char a[EXT], int tamanio);           //Apilar cada caracter en una pila
    void imprimirPila(Pila c);                                      //Imrpimir la pila
    Pila desapilarFrase(Pila a);                                    //Desapilar elementos de <pila a> y apilar en <pila b>
    bool comprobarPalindromo(Pila a, Pila b, int t);                //Comprobar igualdad
    Pila frase, frase2;
    char f[EXT];
    int t = 0, n, i = 0;
    bool comp;
    cout << "Cuantas frases desea comprobar: ";
    cin >> n;
    while (i < n)
    {
        leerFrase(f);
        t = strlen(f);                                               //Longitud de cadena
        apilarFrase(&frase, f, t);
        imprimirPila(frase);
        frase2 = desapilarFrase(frase);                              //Desapilar elementos de <pila a> y apilar en <pila b>
        comp = comprobarPalindromo(frase, frase2, t);                //Comprobacion de igualdad
        if (comp == true)
        {
            cout << f << " es palindromo" << endl;
        }
        else
            cout << f << " no es palindromo" << endl;
        i++;
        while(!frase.pilaVacia())
        {
            frase.pop();
        }
    }
    return 0;
}

void leerFrase(char a[EXT])
{
    cout << "Ingrese la frase: ";
    cin >> a;
}
void apilarFrase(Pila *b, char a[EXT], int tamanio)
{
        for (int i = 0; i < tamanio; i++)
        {
            b->push(a[i]);
        }
}
void imprimirPila(Pila c)
{
    cout << "[ ";
    while (!c.pilaVacia())
    {
        cout << c.pop() << " ";
    }
    cout << "]" << endl;
}
Pila desapilarFrase(Pila a)
{
    Pila b;
    char aux;
    while (!a.pilaVacia())
    {
        aux = a.pop();
        b.push(aux);
    }
    return b;
}
bool comprobarPalindromo(Pila a, Pila b, int t)
{
    Pila c = b;
    char aux, aux2;
    int cont = 0;
    while (!a.pilaVacia())
    {
        aux = a.pop();
        aux2 = b.pop();
        if (aux == aux2)                                                //Cuenta las igualdades
        {
            cont++;
        }
    }
    if (cont == t)                                                      //Son iguales si la cantidad de igualdades es igual a 
    {
        return true;
    }
    return false;
}