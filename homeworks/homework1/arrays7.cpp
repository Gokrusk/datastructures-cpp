// 7. Ingresar un arreglo unidimensional de valores, y eliminar
// de este todos aquellos valores que se encuentren repetidos

#include <iostream>
using namespace std;

// Prototipos
void leerV(int a[], int n);
void imprimirV(int a[], int n);
void elementosRepetidos(int a[], int n, int *pos, int *cont);
void eleminarRepetido(int a[], int *n, int x, int cant);

int main()
{
    int l = 0, pos = 0, cont = 0;
    cout << "Ingrese la cantidad de elementos a ingresar en vector: ";
    cin >> l;
    int a[l];
    leerV(a, l);                            // Lectura elementos de vector
    imprimirV(a, l);                        // Imprimir vector
    elementosRepetidos(a, l, &pos, &cont); // Elemento repetido
    eleminarRepetido(a, &l, pos, cont);
    imprimirV(a, l);
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
void elementosRepetidos(int a[], int n, int *pos, int *cont) // buscar elementos repetidos
{
    int aux,cant=0;
    for (int i = 0; i < n; i++)
    {
        aux = a[i]; // elemento anclado
        for (int j = 0; j < n; j++)
        {
            if (aux == a[j]) // comproband elemento anclado con todos los elementos
            {
                cant++;
            }
        }
        if (cant > 1)
        {
            *pos = i;
            *cont = cant;
            break;
        }
    }
}
void eleminarRepetido(int a[], int *n, int x, int cant)
{
    int j = 0;
    while (j < cant - 1) // repite nveces se encuentre repetido un elemento
    {
        for (int i = x; i < *n; i++) // inicio: elemento repetido
        {
            a[i] = a[i + 1]; // asigna la siguiente posicion a la posicion del elemento repetido
        }
        *n -= 1;
        j++;
    }
}