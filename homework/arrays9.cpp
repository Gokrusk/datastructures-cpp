// 9. Ingresar un arreglo unidimensional y determinar aquellos
// intervalos de elementos (posición inicial y final) en los que
// los valores se encuentren ordenados.
#include <iostream>
using namespace std;

// Prototipos
void leerV(int a[], int n);
void imprimirV(int a[], int n);
void intervalos(int a[], int n);
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
bool ordenDesc(int a[], int n, int pi, int pf)
{
    bool flag = false;
    int aux = a[0];
    for (int i = pi; i < pf; i++)
    {
        if (i < pf - 1)
        {
            if (aux > a[i + 1])
            {
                flag = true;
                aux = a[i + 1];
            }
            else
            {
                flag = false;
                break;
            }
        }
    }
    if (flag)
    {
        cout << "Vector descendente" << endl;
    }
    return flag;
}
bool ordenAsc(int a[], int n, int pi, int pf)
{
    bool flag = false;
    for (int i = pi; i < pf; i++)
    {
        if (a[i] < a[i + 1])
        {
            flag = true;
        }
        else
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << "Vector ascendente" << endl;
    }
    return flag;
}
bool arrayIgual(int a[], int n, int pi, int pf)
{
    bool flag = false;
    int aux = a[0];
    for (int i = pi; i < pf; i++)
    {
        if (i < pf - 1)
        {
            if (aux == a[i + 1])
            {
                flag = true;
                aux = a[i + 1];
            }
            else
            {
                flag = false;
                break;
            }
        }
    }
    return flag;
}
void intervalos(int a[], int n)
{
    int ini, fin, cont, aux;
    bool igual = false, asc = false, desc = false;
    for (int i = 0; i < n; i++)
    {
        aux = a[i];
        if (i < n - 1)
        {
            for (int j = 0; j < n; j++)
            {
                igual = arrayIgual(a, n, i, j + 1);
                if (igual == false)
                {
                    asc = ordenAsc(a, n, i, j + 1);   // ascendente
                    desc = ordenDesc(a, n, i, j + 1); // descendente
                    if (asc == true)
                    {
                        cout << "Intervalo ascendente: [" << i << ", " << j + 1 << "]" << endl;
                        break;
                    }
                    if (desc == true)
                    {
                        cout << "Intervalo descendente: [" << i << ", " << j + 1 << "]" << endl;
                        break;
                    }
                }
            }
        }
    }
    if (igual)
    {
        cout << "Los elementos del vector son iguales" << endl;
    }
}
void solucion()
{
    int l;
    cout << "Ingrese la cantidad de elementos a ingresar en vector: ";
    cin >> l;
    int a[l];
    leerV(a, l);      // Lectura elementos de vector
    imprimirV(a, l);  // Imprimir vector
    intervalos(a, l); // Determinar orden
}