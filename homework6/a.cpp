#include <iostream>
using namespace std;

int main()
{
    void imprimirA(int cont, int n);
    void espacio(int n);
    void visualizacion(int cont, int n);
    visualizacion(1, 5);
    return 0;
}

void imprimirA(int cont, int n)
{
    if (cont <= n)
    {
        cout << "a ";
        imprimirA(cont + 1, n);
    }
}

void espacio(int n)
{
    if (n > 0)
    {
        cout << "  ";
        espacio(n - 1);
    }
}

void visualizacion(int cont, int n)
{
    if (cont <= n)
    {
        espacio(n - cont);
        imprimirA(1, cont);
        cout << endl;
        visualizacion(cont + 1, n);
    }
}