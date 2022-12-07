#ifndef _NODO1_H
#define _NODO1_H
//CONTIENE LA DEFINICION DE LOS NODOS DE UNA LISTA
#include<iostream>
typedef int Tipo;                                       //define el tipo al que corresponde el atributo dato
class Nodo1                                              //definicion de la calse
{
private:                                                //atributos
    Tipo dato;                                          //almacenar el valor de cada Nodo1
    Nodo1* punt;                                         //almanecar el apuntador de siguiente nodo;
public:
    Nodo1();
    Nodo1(Tipo v);                                       //constructor conociendo el valor del dato
    Nodo1(Tipo v, Nodo1* p);                               //constructor conociendo el valor del dato y el apuntador
    void setDato(Tipo v);                               //actualiza el estado del atributo dato
    void setPunt(Nodo1* v);                              //actualiza el estado del apuntador
    Tipo getDato();                                     //devuelve estado del atributo dato
    Nodo1* getPunt();                                    //devuelve estado del apuntador
};

Nodo1::Nodo1()
{
    setDato(0);
    setPunt(NULL);
}
Nodo1::Nodo1(Tipo v)
{
    setDato(v);
    setPunt(NULL);
}
Nodo1::Nodo1(Tipo v, Nodo1* p)
{
    setDato(v);
    setPunt(p);
}
void Nodo1::setDato(Tipo v)
{
    dato = v;
}

void Nodo1::setPunt(Nodo1* v)
{
    punt = v;
}

Tipo Nodo1::getDato()
{
    return dato;
}

Nodo1* Nodo1::getPunt()
{
    return punt;
}
#endif