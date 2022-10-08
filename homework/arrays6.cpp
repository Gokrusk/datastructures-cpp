// 6. Calcular el factorial del producto de los elementos de un
// vector comprendidos entre las posiciones M y N

#include <iostream>
using namespace std;

// Prototipos
void leerV(int a[], int n);
void imprimirV(int a[], int n);
void productoPosiciones(int a[], int n, int &produc);
void factorial(double a);
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
void productoPosiciones(int a[], int n, int &produc)
{
    int ini, fin;
    do
    {
        do
        {
            cout << "Indique posicion inicial: ";
            cin >> ini;
        } while (ini < 1 || ini > n);
        do
        {
            cout << "Indique posicion final: ";
            cin >> fin;
        } while (fin < 1 || fin > n);
    } while (ini > fin || fin < ini);

    for (int i = ini - 1; i < fin; i++)
    {
        produc *= a[i];
    }
    cout << "El producto es: " << produc << endl;
}
void factorial(double a) // factorial(n)
{
    double f = 1;
    for (int i = 1; i <= a; i++)
    {
        f *= i;
    }

    cout << "Factorial: " << f << endl;
}
void solucion()
{
    int l, produc = 1;
    cout << "Ingrese la cantidad de elementos a ingresar: ";
    cin >> l;
    int a[l];
    leerV(a, l);                      // Lectura elementos de vector
    imprimirV(a, l);                  // Imprimir vector
    productoPosiciones(a, l, produc); // Producto posiciones
    factorial(produc);                // factorial de producto
}