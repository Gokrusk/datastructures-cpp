//CONTIENE LA DEFINICION DE LOS NODOS DE UNA LISTA
#include<iostream>
using namespace std;
#include <cstring>

typedef string Tipo;                                       //define el tipo al que corresponde el atributo dato
class Nodo                                              //definicion de la calse
{
private:                                                //atributos
    Tipo dato;                                          //almacenar el valor de cada Nodo
    Nodo* punt;                                         //almanecar el apuntador de siguiente nodo;
public:
    Nodo();
    Nodo(Tipo v);                                       //constructor conociendo el valor del dato
    Nodo(Tipo v, Nodo* p);                               //constructor conociendo el valor del dato y el apuntador
    void setDato(Tipo v);                               //actualiza el estado del atributo dato
    void setPunt(Nodo* v);                              //actualiza el estado del apuntador
    Tipo getDato();                                     //devuelve estado del atributo dato
    Nodo* getPunt();                                    //devuelve estado del apuntador
};

Nodo::Nodo()
{
    setDato(0);
    setPunt(NULL);
}
Nodo::Nodo(Tipo v)
{
    setDato(v);
    setPunt(NULL);
}
Nodo::Nodo(Tipo v, Nodo* p)
{
    setDato(v);
    setPunt(p);
}
void Nodo::setDato(Tipo v)
{
    dato = v;
}

void Nodo::setPunt(Nodo* v)
{
    punt = v;
}

Tipo Nodo::getDato()
{
    return dato;
}

Nodo* Nodo::getPunt()
{
    return punt;
}
