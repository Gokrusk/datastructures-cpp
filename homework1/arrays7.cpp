// 7. Ingresar un arreglo unidimensional de valores, y eliminar
// de este todos aquellos valores que se encuentren repetidos

#include <iostream>
using namespace std;

// Prototipos
void leerV(int a[], int n);
void imprimirV(int a[], int n);
void eleminarRepetido(int a[], int n, int x, int cant);
void elementosRepetidos(int a[], int n);
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
        if (a[i] != 0)
        {
            cout << a[i] << " ";
        }
    }
    cout << "]" << endl;
}
void eleminarRepetido(int a[], int n, int x, int cant)
{
    int j = 0;
    while (j < cant - 1) // repite nveces se encuentre repetido un elemento
    {
        for (int i = x; i < n; i++) // inicio: elemento repetido
        {
            a[i] = a[i + 1]; // asigna la siguiente posicion a la posicion del elemento repetido
        }
        a[n - 1] = {};
        j++;
    }
}
void elementosRepetidos(int a[], int n) // buscar elementos repetidos
{
    int aux, cont = 0;
    for (int i = 0; i < n; i++)
    {
        aux = a[i]; // elemento anclado
        cont = 0;
        for (int j = 0; j < n; j++)
        {
            if (aux == a[j]) // comproband elemento anclado con todos los elementos
            {
                cont++;
            }
        }
        if (cont > 1)
        {
            eleminarRepetido(a, n, i, cont);
            break;
        }
    }
}
void solucion()
{
    int l = 0;
    cout << "Ingrese la cantidad de elementos a ingresar en vector: ";
    cin >> l;
    int a[l];
    leerV(a, l);              // Lectura elementos de vector
    imprimirV(a, l);          // Imprimir vector
    elementosRepetidos(a, l); // Elemento repetido
    imprimirV(a, l);          // Imprimir vector final
}