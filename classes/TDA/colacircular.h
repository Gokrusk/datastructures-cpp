// TDA COLA CIRCULAR
// Implementa los métodos requeridos para construir TDA Colas basadas en el empleo de un arreglo circular
// METODOS A EDITAR BORRAR COLA, COLA VACIA, COLA LLENA, TAMANIO COLA, INSERTAR, QUITAR
// METODOS NUEVOS CALCULAR SIGUIENTE
//GAP UNA POSICION NO VA A TENER DATO
#include "cola.h"
typedef int Tipo;
#define EXT 20

class ColaCircular : public Cola // Definir atributos y métodos que hereda de la clase cola
{
public:				   // métodos públicos
	ColaCircular();	   // constructor
	void borrarCola(); // Vuelve a inicializar el TDA
	bool colaVacia();  // Retorna si la cola esta vacia
	bool colaLlena();  // Retorna si la cola esta lleno
	int tamanioCola(); // Retorna tamanio cola
	int calcularSiguiente(int v);
	Tipo extraerVal();			// Extrae y elimina un elemento del TDA
	void insertarVal(Tipo x);	// Inserta un elemento en el TDA
};

ColaCircular::ColaCircular()
{
	setFrente(0);	   // Inicializr la pos apuntada por frente
	setFinal(EXT - 1); // Inicializr la pos apuntada por final
}
int ColaCircular::calcularSiguiente(int v)
{
	return ((v + 1) % EXT);
}
void ColaCircular::borrarCola()
{
	setFrente(0);	   // Inicializr la pos apuntada por frente
	setFinal(EXT - 1); // Inicializr la pos apuntada por final
}

bool ColaCircular::colaVacia()
{
	return (calcularSiguiente(getFinal()) == getFrente());
}
bool ColaCircular::colaLlena()
{
	int x = calcularSiguiente(calcularSiguiente(getFinal()));
	return (x == getFrente());
}
Tipo ColaCircular::extraerVal()
{
	Tipo x; // var para contener el valor a devolver
	if (!colaVacia())
	{
		x = getElem(getFrente());
		setFrente(calcularSiguiente(getFrente()));
		return x;
	}
	return x;
}
void ColaCircular::insertarVal(Tipo x)
{
	if (!colaLlena())
	{
		setFinal(calcularSiguiente(getFinal()));
		setElem(x, getFinal());
	}
}