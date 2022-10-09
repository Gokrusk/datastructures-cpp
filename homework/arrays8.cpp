// 8. Ingresar un arreglo de números enteros, proceda a ordenarlos e
// Insertar varios valores en el mismo, de forma tal que se conserve
// el orden antes implementado

#include <iostream>
using namespace std;

// Prototipos
void leerV(int a[], int n);
void imprimirV(int a[], int n);
void ordenarasc(int a[], int n);
void ordenardesc(int a[], int n);
void insertar(int a[], int n);
void solucion();

int main()
{
    solucion();
    return 0;
}
void leerV(int a[], int n) // leer vector(array, nelementos)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> a[i];
    }
}
void imprimirV(int a[], int n) // imprimir vector(array, nelementos)
{
    cout << "Vector: [";
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
        if (i < n - 1)
        {
            cout << ",";
        }
    }
    cout << "]" << endl;
}
void ordernarAsc(int a[], int n) // ordenar ascendente
{
    int aux;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[j] > a[j + 1])
            {
                aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
            }
        }
    }
    cout << "Vector ascendente: " << endl;
    imprimirV(a, n);
}
void ordernarDesc(int a[], int n) // ordenar descendente
{
    int aux;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (a[j] > a[j - 1])
            {
                aux = a[j];
                a[j] = a[j - 1];
                a[j - 1] = aux;
            }
        }
    }
    cout << "Vector descendente: " << endl;
    imprimirV(a, n);
}
void insertar(int a[], int n)
{
    int x;
    cout << "Ingrese la cantidad de valores a insertar: ";
    cin >> x;
    int y = x + n; // cantidad total de elementos
    int b[y];
    for (int i = 0; i < y; i++)
    {
        if (i < n)
        {
            b[i] = a[i]; // insertar valores del vector inicial
        }
        else
        {
            cout << "Ingrese valor a insertar: "; // insertar nuevos valores
            cin >> b[i];
        }
    }
    imprimirV(b, y);
}
void solucion()
{
    int l, op;
    // Lectura cantidad de elementos
    cout << "Ingrese la cantidad de elementos a ingresar en vector: ";
    cin >> l;
    int a[l];
    leerV(a, l);     // Lectura elementos de vector
    imprimirV(a, l); // Imprimir vector
    cout << "1. Ascendente" << endl;
    cout << "2. Descendente" << endl;
    cin >> op;
    switch (op)
    {
    case 1:
        ordernarAsc(a, l); // Ordenar ascendente
        insertar(a, l);
        break;
    case 2:
        ordernarDesc(a, l); // Ordenar descendente
        insertar(a, l);
        break;
    default:
        cout << "No existe la opcion" << endl;
        break;
    }
}