//Verificar que cada palabra de una cadena es palindromo

#include <iostream>
#include <cstring>
#define EXT 30 // cte que marca el tamaño maximo de la estructura
using namespace std;

int main()
{
    char f[EXT];
    char pal[EXT / 2][EXT];
    int np = 0;
    // Prototipos de funciones
    void LeerCadena(char f[]);
    bool esPalindromo(char f[], int i, int j);
    void pasarAPalabras(char f[], char p[][EXT], int *npal, int i, int j, int k);
    void Imprimir(char f[], char p[][EXT], int *npal, int i, int j);
    LeerCadena(f);
    pasarAPalabras(f, pal, &np, 0, 0, 0);
    Imprimir(f, pal, &np, 0, 0);

    system("pause");
    return 0;
}

void LeerCadena(char f[])
{
    cout << "Ingrese una cadena de caracteres: " << endl;
    cin.getline(f, EXT, '.');
}

bool esPalindromo(char f[], int i, int j)
{
    if (i < j)
    {
        if (f[i] != f[j])
        {
            return false;
        }
        esPalindromo(f, i + 1, j--);
    }
    return true;
}

void pasarAPalabras(char f[], char p[][EXT], int *npal, int i, int j, int k)
{
    if (i < strlen(f))
    {
        if (((f[i] >= 'A') && (f[i] <= 'Z')) || ((f[i] >= 'a') && (f[i] <= 'z')))
        {
            p[j][k] = f[i];
            k++;
        }
        else
        {
            if (k > 0)
            {
                p[j][k] = '\0';
                j++;
                k = 0;
            }
        }
        pasarAPalabras(f, p, npal, i + 1, j, k);
    }
    else
    {
        p[j][k] = '\0';
        *npal = j + 1;
    }
}

void Imprimir(char f[], char p[][EXT], int *npal, int i, int j)
{
    if (i < *npal)
    {
        cout << "La palabra ingresada es: " << p[i] << endl;
        cout << "Esa cadena " << (esPalindromo(p[i], 0, strlen(p[i]) - 1) ? "si" : "no") << " es un palindromo." << endl;
        Imprimir(f, p, npal, i + 1, strlen(f) - 1);
    }
}