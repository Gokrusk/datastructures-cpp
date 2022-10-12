// 8. Ingresar un arreglo de números enteros, proceda a ordenarlos e
// Insertar varios valores en el mismo, de forma tal que se conserve
// el orden antes implementado

#include <iostream>
using namespace std;

// Prototipos
void leerV(int a[], int n);
void imprimirV(int a[], int n);
void ordenarAsc(int a[], int n);
void ordenarDesc(int a[], int n);
void insertar(int a[], int *n);

int main()
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
        ordenarAsc(a, l); // Ordenar ascendente
        imprimirV(a, l);
        insertar(a, &l);
        imprimirV(a, l);
        break;
    case 2:
        ordenarDesc(a, l); // Ordenar descendente
        imprimirV(a, l);
        insertar(a, &l);
        imprimirV(a, l);
        break;
    default:
        cout << "No existe la opcion" << endl;
        break;
    }
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
void ordenarAsc(int a[], int n) // ordenar ascendente
{
    int aux;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
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
}
void ordenarDesc(int a[], int n) // ordenar descendente
{
    int aux;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= n - i; j--)
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
}
void insertar(int a[], int *n)
{
    int x=0, j = 0, val=0;
    cout << "Ingrese la cantidad de valores a insertar: ";
    cin >> x;
    while (j < x)
    {
        cout << "Ingrese el valor " << j + 1 << ": ";
        cin >> val;
        for (int i = *n; i < *n + 1; i++)
        {
            a[i] = val;
        }
        *n += 1;
        j++;
    }
}