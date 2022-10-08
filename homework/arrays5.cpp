// 5. Calcular la suma de dos vectores ingresados
//(considérense vectores de distintas dimensiones)

#include <iostream>
using namespace std;

// Prototipos
void leerV(int a[], int n);
void lectura2Vectores();
void imprimirV(int a[], int n);

int main()
{
    lectura2Vectores();
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
void lectura2Vectores()
{
    int n1, n2;
    cout << "Ingrese cantidad de elementos de vector 1:";
    cin >> n1;
    int a[n1];
    leerV(a, n1);
    cout << "Ingrese cantidad de elementos de vector 2:";
    cin >> n2;
    int b[n2];
    leerV(b, n2);
}