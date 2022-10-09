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
void ordernar(int a[], int n)
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
    cout<<"Vector ascendente: "<<endl;
    imprimirV(a, n);
}
void solucion()
{
    int l;
    // Lectura cantidad de elementos
    cout << "Ingrese la cantidad de elementos a ingresar en vector: ";
    cin >> l;
    int a[l];
    leerV(a, l);       // Lectura elementos de vector
    imprimirV(a, l);   // Imprimir vector
    ordernar(a, l); // Ordenar ascendente
}