// 3. Teniendo los números 50, 25, 20, 10, 5, 3, 2, 1,
// encuéntrese la secuencia de tres números distintos tal
// que la sumatoria del doble de cada uno sea igual a 96

#include <iostream>
using namespace std;

// Prototipos
void solucion(int a[], int n);

int main()
{
    int a[] = {50, 25, 20, 10, 5, 3, 2, 1};
    solucion(a, 7);

    return 0;
}
void solucion(int a[], int n)
{
    int aux, aux2, aux3, sum;
    for (int i = 0; i < n; i++)
    {
        aux = 2 * a[i]; // elemento1 anclado
        for (int j = i + 1; j < n; j++)
        {
            aux2 = 2 * a[j]; // elemento2 anclado
            for (int k = j + 1; k < n; k++)
            {
                aux3 = 2 * a[k];         // elemento3 anclado
                sum = aux + aux2 + aux3; // suma
                if (sum == 96)           // comprobacion
                {
                    cout << "Secuencia de numeros: [" << aux / 2 << " " << aux2 / 2 << " " << aux3 / 2 << "]" << endl;
                    cout << "Suma: " << sum << endl;
                    // break;
                }
            }
        }
    }
}