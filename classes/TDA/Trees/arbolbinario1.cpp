//Implementa un arbol binario base
#include <iostream>
using namespace std;
#include "arbolbinario.h"

int main()
{
    ArbolBinario a;
    cout<< "El arbol " <<(a.esVacio() ? "si" :"no") << " esta vacio"<<endl;
    return 0;
}