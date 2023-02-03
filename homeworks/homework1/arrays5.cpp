// 5. Calcular la suma de dos vectores ingresados
//(considérense vectores de distintas dimensiones)

#include <iostream>
using namespace std;

// Prototipos
void leerV(int a[], int n);
void sumaVectores(int amay[], int bmen[], int c[], int nmay, int nmen);
void vectorResultante(int a[], int n);

int main()
{
    int n1, n2, may;
    cout << "Ingrese cantidad de elementos de vector 1: ";
    cin >> n1;
    int a[n1];
    leerV(a, n1);
    cout << "Ingrese cantidad de elementos de vector 2: ";
    cin >> n2;
    int b[n2];
    leerV(b, n2);
    if (n1 > n2) // comprobando vector mayor
    {
        int c[n1];
        sumaVectores(a, b, c, n1, n2);
        vectorResultante(c, n1);
    }
    else
    {
        int c[n2];
        sumaVectores(b, a, c, n2, n1);
        vectorResultante(c, n2);
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
void sumaVectores(int amay[], int bmen[], int c[], int nmay, int nmen)
{
    for (int i = 0; i < nmay; i++)
    {
        if (i < nmen)
        {
            c[i] = amay[i] + bmen[i]; // asginar la suma de elementos en posiciones iguales
        }
        else
        {
            c[i] = amay[i]; // asignar directamente al llegar a la posicion mayor
        }
    }
}
void vectorResultante(int a[], int n) // imprimir vector resultante
{
    cout << "Vector resultante: [";
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