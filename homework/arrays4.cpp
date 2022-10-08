// 4. Determinar aquellos elementos que no se encuentran repetidos entre
// los valores de un vector ingresado por el usuario, así como las ubicaciones
// en que se encuentra cada uno

#include <iostream>
using namespace std;

// Prototipos
void leerV(int a[], int n);
void imprimirV(int a[], int n);
void elementosDiferentes(int a[], int n);
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
void elementosDiferentes(int a[], int n) // buscar elementos diferntes
{
    int aux, cont = 0;
    for (int i = 0; i < n; i++)
    {
        aux = a[i]; // elemento anclado
        cont = 0;
        for (int j = 0; j < n; j++)
        {
            if (aux == a[j]) // comprobando elemento anclado con todos los elementos
            {
                cont++;
            }
        }
        if (cont <= 1)
        {
            cout << "[" << i << "]: " << aux << endl; // posicion y elemento sin repetir
        }
    }
}
void solucion()
{
    int l;
    bool repet;
    cout << "Ingrese la cantidad de elementos a ingresar: ";
    cin >> l;
    int a[l];
    leerV(a, l);     // Lectura elementos de vector
    imprimirV(a, l); // Imprimir vector
    cout << "Numeros que no se repiten:" << endl;
    elementosDiferentes(a, l); // Elemento repetido
}