// 1. Determinar si los elementos de cada arreglo unidimensional ingresado presentan una disposición ordenada de valores (ascendente o descendentemente)
#include <iostream>
using namespace std;

// Prototipos
void leerV(int a[], int n);
void imprimirV(int a[], int n);
bool arrayIgual(int a[], int n);
bool ordenDesc(int a[], int n);
bool ordenAsc(int a[], int n);

int main()
{
    int l = 0, n = 0;
    bool igual = false, asc = false, desc = false;
    cout << "Ingrese cantidad de vectores: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        // Lectura cantidad de elementos
        cout << "Ingrese la cantidad de elementos a ingresar en vector "<<i+1<<": ";
        cin >> l;
        int a[l];
        // Lectura elementos de vector
        leerV(a, l);
        // Imprimir vector
        imprimirV(a, l);
        // Elementos iguales
        igual = arrayIgual(a, l);
        if (igual == false)
        {
            asc = ordenAsc(a, l);   // ascendente
            desc = ordenDesc(a, l); // descendente
            if (asc == false && desc == false)
            {
                cout << "Los elementos no tiene un orden especifico" << endl;
            }
        }
        cout<<endl;
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
bool arrayIgual(int a[], int n)
{
    bool flag = false;
    int aux = a[0];
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1)
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
    if (flag)
    {
        cout << "Los elementos de los vectores son iguales" << endl;
    }
    return flag;
}
bool ordenDesc(int a[], int n)
{
    bool flag = false;
    int aux = a[0];
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1)
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
bool ordenAsc(int a[], int n)
{
    bool flag = false;
    for (int i = 0; i < n; i++)
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