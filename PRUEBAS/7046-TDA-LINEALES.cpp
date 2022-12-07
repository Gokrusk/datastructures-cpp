// Elaborar un programa, haciendo uso de TDA (pilas, colas, listas), que permita el ingreso de una cadena de caracteres,
// y proceda a generar un listado alfabético de las palabrass encontradas en la misma que corresponda a la letra inicial
// ingresada por el usuario. Repetir el proceso de generación de respuestas la cantidad de veces que el usuairio requiera.

#include <iostream>
#include "pila.h"
#include "lista.h"
#include "lista1.h"
using namespace std;

int main()
{
    // PROTOTIPOS
    void leerFrase(char a[EXT]);                              // Lectura de frase
    void separarPalabras(char a[EXT], int tamanio, Lista *l); // separa las palabras de la frase y las guarda en una lista alfabeticamente
    void imprimirPalabras(Lista l);                           // imprime las palabras de la lista
    void imprimirPalabras2(Lista l[]);                        // imprime las palabras de la lista
    // void imprimirPalabras3(Lista1 l);                              // imprime las palabras de la lista
    void formarListasAlfabeticas(Lista l, Lista1 alfb, Lista m[]); // genera las listas de palabras por inicial
    void inicialesListasAlfabeticas(Lista m[], Lista1 alfb);       // crea listas con cada letra del abecedario
    int contarElementosLista(Lista l);                             // cuenta elementos de la lista
    int convertToASCII(string s);                                  // convertir letra en codigo ascii
    void abecedarioASCII(Lista1 * a);                              // guarda en una lista el abecedario en codigo ascii, primero mayusculas luego minusculas
    Pila frase;
    Lista a, b[EXT];
    Lista1 alfb;
    char f[EXT];
    int t = 0, n, i = 0;
    leerFrase(f);
    t = strlen(f); // Longitud de cadena
    separarPalabras(f, t, &a);
    imprimirPalabras(a);
    abecedarioASCII(&alfb);
    inicialesListasAlfabeticas(b, alfb);
    formarListasAlfabeticas(a, alfb, b);
    imprimirPalabras2(b);
    return 0;
    system("pause");
}

void leerFrase(char a[EXT])
{
    cout << "Ingrese la frase: ";
    gets(a);
}

void separarPalabras(char a[EXT], int tamanio, Lista *l)
{
    Pila b, p;
    Lista m;
    int cont = 0, aux2 = 0;
    string x, y;
    for (int i = 0; i < tamanio; i++) // guarda en que posicion estan los espacios
    {
        if (a[i] == ' ')
        {
            p.push(i);
        }
    }
    p.push(tamanio);
    while (!p.pilaVacia())
    {
        b.push(p.pop());
    }
    do // guarda palabras en una lista, se repite la cantidad de espacios+1
    {
        aux2 = b.pop();     // guarda posicion de espacio (" ")
        while (cont < aux2) // mientras cont no llegue a la posicion de espacio
        {
            x += a[cont]; // cada caracter se va agregando a una variable string
            cont++;
        }
        m.insertarEnOrden(x); // se inserta la palabra en orden en una lista
        cont += 1;            // avanza a la siguiente palabra
        x = y;
    } while (cont < tamanio + 1);
    *l = m;
}

void imprimirPalabras(Lista a)
{
    // recorrido de la lista
    Nodo *actual; // referencia a nodo actual de la lista
    cout << endl
         << " PALABRAS ALMACENADAS EN LA LISTA " << endl;
    actual = a.getPrimero(); // almacena temporalmente la posicion del primer nodo
    while (actual != NULL)   // repetir mientras no se alcance el final de la lista
    {
        cout << "> " << actual->getDato() << endl;
        actual = actual->getPunt(); // desplaza el puntero actual al siguiente nodo de la lista
    }
    cout << endl;
}

int contarElementosLista(Lista l) // cuenta elementos de la lista
{
    Nodo *actual;
    actual = l.getPrimero();
    int cont = 0;
    while (actual != NULL)
    {
        cont++; // cuenta cada elemento
        actual = actual->getPunt();
    }
    return cont;
}

void imprimirPalabras2(Lista a[])
{
    string s, t;
    bool flag = false;
    cout << "De que letra inicial desea conocer las palabras: ";
    cin >> s;
    // recorrido de la lista
    Nodo *actual; // referencia a nodo actual de la lista
    cout << endl
         << " PALABRAS ALMACENADOS EN LA LISTA " << endl;

    for (int i = 0; i <= 51; i++)
    {
        t = a[i].getPrimero()->getDato();
        if (t == s && contarElementosLista(a[i]) > 1) // si la letra inicial coincide y tiene mas de un elemento (elemento 1 es letra inicial)
        {
            actual = a[i].getPrimero(); // almacena temporalmente la posicion del primer nodo
            actual = actual->getPunt(); // para no imprimir las letras iniciales
            while (actual != NULL)      // repetir mientras no se alcance el final de la lista
            {
                cout << "> " << actual->getDato() << endl; // muestra las palabras
                actual = actual->getPunt();                // desplaza el puntero actual al siguiente nodo de la lista
            }
            cout << endl;
            flag = true;
        }
    }
    if(!flag)
    {
        cout<<"No se encontraron palabras con esa inicial"<<endl;
    }
    }

    // for (int i = 0; i <= 51; i++)
    // {
    //     if (!a[i].esVacia() && contarElementosLista(a[i]) > 1) // si no esta vacia y tiene mas de un elemento, (el primer elemento es la letra inicial)
    //     {
    //         cout << "Lista " << i << endl;
    //         actual = a[i].getPrimero(); // almacena temporalmente la posicion del primer nodo
    //         actual = actual->getPunt(); // para no imprimir las letras iniciales
    //         while (actual != NULL)      // repetir mientras no se alcance el final de la lista
    //         {
    //             cout << "> " << actual->getDato() << endl;
    //             actual = actual->getPunt(); // desplaza el puntero actual al siguiente nodo de la lista
    //         }
    //         cout << endl;
    //     }
    // }
}

// void imprimirPalabras3(Lista1 a)
// {
//     // recorrido de la lista
//     Nodo1 *actual; // referencia a nodo actual de la lista
//     cout << endl
//          << " PALABRAS ALMACENADAS EN LA LISTA " << endl;
//     actual = a.getPrimero(); // almacena temporalmente la posicion del primer nodo
//     while (actual != NULL)   // repetir mientras no se alcance el final de la lista
//     {
//         cout << "> " << actual->getDato() << endl;
//         actual = actual->getPunt(); // desplaza el puntero actual al siguiente nodo de la lista
//     }
//     cout << endl;
// }

// int convertToASCII(string s)
// {
//     int x;
//     for (int i = 0; i < s.length(); i++)
//     {
//         x = (int)s[i];
//     }
//     return x;
// }

string convertToString(int x)
{
    char c = x;
    string s(1, c);
    return s;
}

void inicialesListasAlfabeticas(Lista m[], Lista1 alf) // crea listas con cada letra del abecedario
{
    Nodo1 *actual;
    actual = alf.getPrimero();
    int i = 0;
    string x, y;
    while (actual != NULL) // recorre lista de alfabeto ascii
    {
        x = convertToString(actual->getDato()); // convierte a string
        m[i].insertarEnOrden(x);                // inserta letra inicial en cada lista
        actual = actual->getPunt();             // avanza posicion en alfabeto
        i++;
        x = y;
    }
}

void formarListasAlfabeticas(Lista l, Lista1 alfb, Lista m[])
{
    Nodo *actual;
    Nodo1 *actual2;
    Nodo *actual3;
    actual = l.getPrimero();
    string a, b;
    int x, i;
    actual = l.getPrimero();
    string h;
    while (actual != NULL) // mientras no se alcance el final de la lista de palabras
    {
        i = 0;
        a = actual->getDato();
        b = a.front();
        while (i <= 51)
        {
            actual3 = m[i].getPrimero(); // obtiene letra inicial
            if (b == actual3->getDato()) // si es igual inserta en esa lista
            {
                m[i].insertarEnOrden(a);
            }
            i++; // aumenta contador para siguiente lista
        }
        actual = actual->getPunt(); // recorre lista de palabras
    }
}

void abecedarioASCII(Lista1 *a) // guarda en una lista el abecedario en codigo ascii, primero mayusculas luego minusculas
{
    int ini = 65, fin = 90, ini2 = 97, fin2 = 122, aux = 0;
    while (ini <= fin)
    {
        a->insertarNodoFinal(ini);
        ini++;
    }
    while (ini2 <= fin2)
    {
        a->insertarNodoFinal(ini2);
        ini2++;
    }
}

/*
    A: 65 B 66 C 67 D 68 E 69 F 70 G 71 H 72 I 73 J 74 K 75 L 76 M 77 N 78 O 79 P 80 Q 81 R 82 S 83 T 84 U 85 V 86 W 97 X 88 Y 89 Z 90
    a 97 b 98 c 99 d 100 e 101 f 102 g 103 h 104 i 105 j 106 k 107 l 108 m 109 n 110 o 111 p 112 q 113 r 114 s 115 t 116 u 117 v 118 w 119 x 120 y 121 z 122
*/