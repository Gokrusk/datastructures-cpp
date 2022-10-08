// 2. Ingresar un vector y formar, a partir de este, un arreglo de valores primos y otro de valores compuestos.

#include <iostream>
#include <cmath>
using namespace std;

// Prototipos
void leerV(int a[], int n);
void imprimirV(int a[], int n);
void asignarVectorPrimo(int a[], int n);
void asignarVectorComp(int a[], int n);
void calcNums(int a[], int n);

int main()
{
    int l = 0, cont = 0, cont2 = 0,
        nprimos = 0, ncomp = 0;
    // Lectura cantidad de elementos
    cout << "Ingrese la cantidad de elementos a ingresar: ";
    cin >> l;
    int a[l];
    // Lectura elementos de vector
    leerV(a, l);
    // Imprimir vector
    imprimirV(a, l);
    // Buscar primo
    calcNums(a, l);
    return 0;
}

void leerV(int a[], int n)              // leer vector(array, nelementos)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> a[i];
    }
}
void imprimirV(int a[], int n)          // imprimir vector(array, nelementos)
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
void asignarVectorPrimo(int a[], int b[], int n, int npri) // array, nelementos, cantidadprimos
{
    int cont = 0, aux, posicion = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= a[i]; j++)
        {
            if (a[i] % j == 0)
            {
                cont++;
            }
        }

        if (cont <= 2)
        {
            b[posicion] = a[i];
            posicion++;
        }
        cont = 0;
    }
    cout << "Vector de Primos: [";
    for (int k = 0; k < npri; k++)
    {
        cout << b[k];
        if (k < npri - 1)
        {
            cout << ",";
        }
    }
    cout << "]" << endl;
}
void asignarVectorComp(int a[], int b[], int n, int ncomp) // array, nelementos, cantidadcompuestos
{
    int cont = 0, aux, posicion = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= a[i]; j++)
        {
            if (a[i] % j == 0)
            {
                cont++;
            }
        }

        if (cont > 2)
        {
            b[posicion] = a[i];
            posicion++;
        }
        cont = 0;
    }
    cout << "Vector de Compuestos: [";
    for (int k = 0; k < ncomp; k++)
    {
        cout << b[k];
        if (k < ncomp - 1)
        {
            cout << ",";
        }
    }
    cout << "]" << endl;
}
void calcNums(int a[], int n)          // calcular cantidad de primos y compuestos (array, nelementos)
{
    int cont = 0, contp = 0, contc = 0, aux;
    for (int i = 0; i < n; i++)
    {
        aux = a[i];
        for (int j = 1; j <= aux; j++)
        {
            if (aux % j == 0)
            {
                cont++;
            }
        }
        if (cont > 2)
        {
            contc++; // compuesto
        }
        else
        {
            contp++; // primo
        }
        cont = 0;
    }
    int vectorPrimos[contp];
    asignarVectorPrimo(a, vectorPrimos, n, contp);
    int vectorComp[contc];
    asignarVectorComp(a, vectorComp, n, contc);
}