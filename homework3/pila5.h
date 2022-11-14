// TDA PILA
#define EXT 3
typedef int Tipo; // creación de nuevo tipo de datos
class Pila
{
private: // atributos
	Tipo n = EXT;
	Tipo *vec = new Tipo[n];		// pila
	int top;						// apuntador al elemento cima de la pila
public:								// metodos
	Pila();							// constructor
	void setVec(Tipo val, int pos); // actualiza el valor v en la posicion pos de la pila
	void setTop(int v);				// actualiza valor atributo top
	void setN(int v);				// redimensiona tamanio pila
	Tipo getN();					// retorna tamanio pila
	Tipo getVec(int pos);			   // retorna un elemento de la pila
	int getTop();					   // retorna el top
	void limpiarPila();				   // vuelve a inicializar la pila
	bool pilaVacia();				   // retorna si pila esta vacia
	bool pilaLlena();				   // retorna si pila esta llena
	int tamanioPila();				   // retorna tamaño pila, cantidad elementos apilados
	bool push(Tipo x);				   // apila valor y devuelve indicador de exito
	Tipo pop();						   // desapila valor y devuelve elemento
	Tipo cimaPila();				   // retorna valor de la cima de pila
	void eliminarElementoPila(Tipo x); // elimina un elemento de la pila
	void duplicarTamanio(Tipo *v, Tipo x);	//duplica el tamanio de la pila
};
Pila::Pila()
{
	setTop(-1);
}
void Pila::limpiarPila()
{
	setTop(-1);
}
bool Pila::pilaVacia()
{
	return (getTop() == -1);
}
bool Pila::pilaLlena()
{
	if (getTop() == n - 1)
	{
		return true;
	}
	return false;
}
int Pila::tamanioPila()
{
	return (getTop() + 1);
}
bool Pila::push(Tipo x)
{
	if (pilaLlena())
	{
		duplicarTamanio(vec, getN());
		cout<<"Pila llena!, tamanio duplicado: " << getN() << endl;
		setTop(getTop() + 1); //+1 top
		setVec(x, getTop());
		return true;
	}
	else
	{
		setTop(getTop() + 1); //+1 top
		setVec(x, getTop());
		return true;
	}
	return false;
}
Tipo Pila::pop()
{
	Tipo x;
	if (!pilaVacia())
	{
		x = getVec(getTop()); // valor en la cima
		setTop(getTop() - 1); //-1 top
		return x;
	}
	else
		return x; // valor por defecto
}
Tipo Pila::cimaPila()
{
	Tipo x;
	if (!pilaVacia())
	{
		x = getVec(getTop()); // valor en la cima
		return x;
	}
	return x; // valor por defecto
}
void Pila::eliminarElementoPila(Tipo x)
{
	Tipo a1;
	Pila b;

	while (!pilaVacia()) // ciclo para insertar todos los valores en la pila <b> excepto el valor a eliminar
	{
		a1 = pop();
		if (a1 != x)
		{
			b.push(a1);
		}
	}
	// pila <b< llena y pila <a> vacia
	while (!b.pilaVacia()) // ciclo para insertar en pila <a> los valores de pila <b>
	{
		push(b.pop());
	}
}

void Pila::setVec(Tipo val, int pos)
{
	vec[pos] = val;
	setTop(pos);
}
void Pila::setTop(int v)
{
	top = v;
}
void Pila::setN(int v)
{
	n = v;
}
Tipo Pila::getVec(int pos)
{
	return vec[pos];
}
int Pila::getTop()
{
	return top;
}
Tipo Pila::getN()
{
	return n;
}
void Pila::duplicarTamanio(Tipo *v, Tipo ninicial)
{
	setN(2 * getN());
	Tipo vec2[getN()];									//define vector con tamanio pila duplicado
	for (int i = 0; i < getN(); i++)					//redimensiona vector
	{
		if (ninicial <= i)								//inserta los valores del vector inicial al vector auxiliar
			vec2[i] = 0;
		else
			vec2[i] = v[i];
	}
	v = vec2;
}