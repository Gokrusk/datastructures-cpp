//CONTIENE LA DEFINICION DE LOS NODOS DE UNA LISTA
#include<iostream>
using namespace std;
#include <string>
#include <cstring>
typedef string Tipo1;                                       //define el tipo al que corresponde el atributo dato
class Nodo                                              //definicion de la calse
{
private:                                                //atributos
    Tipo1 dato;                                          //almacenar el valor de cada Nodo
    Nodo* punt;                                         //almanecar el apuntador de siguiente nodo;
public:
    Nodo();
    Nodo(Tipo1 v);                                       //constructor conociendo el valor del dato
    Nodo(Tipo1 v, Nodo* p);                               //constructor conociendo el valor del dato y el apuntador
    void setDato(Tipo1 v);                               //actualiza el estado del atributo dato
    void setPunt(Nodo* v);                              //actualiza el estado del apuntador
    Tipo1 getDato();                                     //devuelve estado del atributo dato
    Nodo* getPunt();                                    //devuelve estado del apuntador
};

Nodo::Nodo()
{
    setDato(0);
    setPunt(NULL);
}
Nodo::Nodo(Tipo1 v)
{
    setDato(v);
    setPunt(NULL);
}
Nodo::Nodo(Tipo1 v, Nodo* p)
{
    setDato(v);
    setPunt(p);
}
void Nodo::setDato(Tipo1 v)
{
    dato = v;
}

void Nodo::setPunt(Nodo* v)
{
    punt = v;
}

Tipo1 Nodo::getDato()
{
    return dato;
}

Nodo* Nodo::getPunt()
{
    return punt;
}
