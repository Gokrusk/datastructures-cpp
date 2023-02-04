// Administrar un array con recursividad

#include <iostream>
using namespace std;
#include "utilidades.h"

int main()
{
    int n, sum = 0;
    void leerArray(int n, int a[]);                        // funcion recursiva para leer array
    void printArray(int n, int a[]);                       // funcion recursiva para imprimir array
    void calSumVec(int n, int a[], int *sum);              // funcion recursiva que suma los elementos de un array
    void eliminarX(int a[], int *n);                       // funcion para eliminar un elemento de un array
    void eliminarXArray(int a[], int n, int pos);          // funcion recursiva para eliminar un elemento de un array
    void printAlrevez(int n, int a[]);                     // funcion recursiva que imprime array alrevez
    void insertarElemento(int a[], int *n);                // funcion insertar un elemento en el array
    void moverElementos(int a[], int n, int val, int pos); // funcion recursiva para mover elementos en el array
    void buscar(int a[], int n, int op);                   // funcion para buscar un elemento en el array
    int busquedaSecuencial(int a[], int n, int x);         // funcion recursiva que busca secuencialmente un elemento en el array
    int busquedaBinaria(int a[], int n, int val);          // funcion recursiva que buscar de forma binaria un elemento en el array
    void bubbleSort(int a[], int n, int j);                // funcion recursiva para ordenar elementos de un array mediante bubble sort
    void insertionSort(int a[], int n);                    // funcion recursiva para ordenar elementos de un array mediante insertion sort
    void selectionSort(int a[], int n, int j, int k);      // funcion recursiva para ordenar elementos de un array mediante selection sort

    cout << endl
         << "LONGITUD DE ARRAY" << endl;
    n = leerN(2, 20);
    n -= 1;
    int a[n];
    cout << endl
         << "LECTURA DE ARRAY" << endl;
    leerArray(n, a);
    cout << endl
         << "IMPRESION DE ARRAY" << endl;
    cout << "[ ";
    printArray(n, a);
    cout << "]";
    // cout << endl
    //      << "IMPRESION DE ARRAY AL REVEZ" << endl;
    // cout << "[ ";
    // printAlrevez(n, a);
    // cout << "]";
    // calSumVec(n, a, &sum);
    // cout << endl
    //      << "SUMA DE ELEMENTOS: " << sum << endl;
    // cout << endl
    //      << "INSERCION DE ELEMENTO";
    // insertarElemento(a, &n);
    // cout << endl
    //      << "\nELIMINAR ELEMENTO" << endl;
    // eliminarX(a, &n);
    // cout << endl
    //      << "BUBBLE SORT" << endl;
    // bubbleSort(a,n,n);
    // cout << endl
    //      << "INSERTION SORT" << endl;
    // insertionSort(a, n);
    cout << endl
         << "SELECTION SORT" << endl;
    selectionSort(a, n, 0, n);
    cout << "SORTED ARRAY" << endl;
    cout << "[ ";
    printArray(n, a);
    cout << "]";
    // cout << endl
    //      << "\nBUSQUEDA SECUENCIAL" << endl;
    // buscar(a, n, 1);
    cout << "\nBUSQUEDA BINARIA" << endl;
    buscar(a, n, 2);
    return 0;
}

void leerArray(int n, int a[]) // funcion recursiva para leer array
{
    if (n >= 0)
    {
        leerArray(n - 1, a);
        int x;
        cout << "Ingrese elemento de posicion " << n << ": ";
        cin >> x;
        a[n] = x;
    }
}

void printArray(int n, int a[]) // funcion recursiva para imprimir array
{
    if (n >= 0)
    {
        printArray(n - 1, a);
        cout << a[n] << " ";
    }
}

void printAlrevez(int n, int a[]) // funcion recursiva que imprime array alrevez
{
    if (n >= 0)
    {
        cout << a[n] << " ";
        printAlrevez(n - 1, a);
    }
}

void calSumVec(int n, int a[], int *sum) // funcion recursiva que suma los elementos de un array
{
    if (n >= 0)
    {
        *sum += a[n];
        calSumVec(n - 1, a, sum);
    }
}

void moverElementos(int a[], int n, int pos) // funcion recursiva paa insertar un elemento en el array
{
    if (n + 1 > pos)
    {
        a[n + 1] = a[(n + 1) - 1];
        moverElementos(a, n - 1, pos);
    }
}

void insertarElemento(int a[], int *n) // funcion insertar un elemento en el array
{
    int v, pos;
    cout << endl
         << "Elemento a insertar: ";
    cin >> v;
    cout << "Posicion: ";
    cin >> pos;
    moverElementos(a, *n, pos);
    a[pos] = v;
    *n += 1;
    cout << "IMPRESION DE ARRAY" << endl;
    cout << "[ ";
    printArray(*n, a);
    cout << "]";
}

void eliminarXArray(int a[], int n, int pos) // funcion recursiva para eliminar un elemento de un array
{
    if (n >= pos)
    {
        eliminarXArray(a, n - 1, pos);
        a[n] = a[n + 1];
    }
}

void eliminarX(int a[], int *n) // funcion para eliminar un elemento de un array
{
    int x = 0;
    cout << "Posicion: ";
    cin >> x;
    eliminarXArray(a, *n, x);
    *n -= 1;
    cout << "IMPRESION DE ARRAY" << endl;
    cout << "[ ";
    printArray(*n, a);
    cout << "]";
}

int busquedaSecuencial(int a[], int n, int x) // funcion recursiva que busca secuencialmente un elemento en el array
{
    if (n >= 0)
    {
        if (a[n] == x)
        {
            return n;
        }
        else
        {
            busquedaSecuencial(a, n - 1, x);
        }
    }
    else
    {
        return -1;
    }
}

int busquedaBinaria(int a[], int n, int val, int i, int m, int f) // funcion recursiva que buscar de forma binaria un elemento en el array
{
    if (i <= f)
    {
        m = (i + f) / 2;
        cout << "I: " << i << " F: " << f << " M: " << m << endl;
        if (a[m] == val)
        {
            return m;
        }
        else
        {
            if (a[m] < val)
            {
                i = m + 1;
                busquedaBinaria(a, n, val, i, m, f);
            }
            else
            {
                f = m - 1;
                busquedaBinaria(a, n, val, i, m, f);
            }
        }
    }
    else
    {
        return -1;
    }
}

void buscar(int a[], int n, int op) // funcion para buscar un elemento en el array
{
    int x = 0,
        pos = 0,
        i = 0,
        f = n,
        m = (i + f) / 2;
    cout << "Ingrese elemento a buscar: ";
    cin >> x;
    switch (op)
    {
    case 1:
        pos = busquedaSecuencial(a, n, x);
        break;
    case 2:
        pos = busquedaBinaria(a, n, x, i, 0, f);
    }
    if (pos == -1)
    {
        cout << "El elemento no existe" << endl;
    }
    else
    {
        cout << "El elemento " << x << " se encuentra en la posicion: " << pos << endl;
    }
}

void bubbleSort(int a[], int n, int j) // funcion recursiva para ordenar elementos de un array mediante bubble sort
{
    int aux = 0;
    if (n >= 0)
    {
        if (j >= n)
        {
            if (a[j] > a[j + 1])
            {
                aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
            }
            bubbleSort(a, n, j - 1);
        }
        bubbleSort(a, n - 1, j);
    }
}

int loop(int *j, int a[], int aux)
{
    if (*j >= 0 && a[*j] > aux)
    {
        a[*j + 1] = a[*j];
        *j -= 1;
        loop(j, a, aux);
    }
}

void insertionSort(int a[], int n) // funcion recursiva para ordenar elementos de un array mediante insertion sort
{
    int j = 0, aux = 0;
    if (n >= 1)
    {
        insertionSort(a, n - 1);
        j = n - 1;
        aux = a[n];
        loop(&j, a, aux);
        a[j + 1] = aux;
    }
}

void loop2(int a[], int j, int k, int n, int min, int aux)
{
    if (j < n)
    {
        loop2(a, j + 1, k, n, min, aux);
        if (a[j] < a[min])
        {
            min = j;
        }
    }
    aux = a[min];
    a[min] = a[k];
    a[k] = aux;
}

void selectionSort(int a[], int n, int j, int k) // funcion recursiva para ordenar elementos de un array mediante selection sort
{
    int min = 0;
    if (n >= 1)
    {
        selectionSort(a, n - 1, j, k);
        min = n - 1;
        loop2(a, n, n - 1, k, min, 0);
    }
}