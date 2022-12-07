//TDA PILA
#define EXT 52
typedef	int Tipo2;		//creación de nuevo Tipo2 de datos

class Pila
{
	private:			//atributos
		Tipo2 vec[EXT];	//pila
		int top;		//apuntador al elemento cima de la pila
	public:				//metodos
		Pila();							//constructor
		void setVec(Tipo2 val, int pos);	//actualiza el valor v en la posicion pos de la pila
		void setTop(int v);				//actualiza valor atributo top
		Tipo2 getVec(int pos);			//retorna elemento top
		int getTop();					//retorna el top
		void limpiarPila();				//vuelve a inicializar la pila
		bool pilaVacia();				//retorna si pila esta vacia
		bool pilaLlena();				//retorna si pila esta llena
		int tamanioPila();				//retorna tamaño pila, cantidad elementos apilados
		bool push(Tipo2 x);				//apila valor y devuelve indicador de exito
		Tipo2 pop();						//desapila valor y devuelve elemento
		Tipo2 cimaPila();				//retorna valor de la cima de pila
		void eliminarElementoPila(Tipo2 x); 	//elimina un elemento de la pila
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
	return (getTop() == EXT-1);
}
int Pila::tamanioPila()
{
	return (getTop()+1);
}
bool Pila::push(Tipo2 x)
{
	if(!pilaLlena())
	{
		setTop(getTop()+1);				//+1 top
		setVec(x, getTop());
		return true;
	}else return false;
}
Tipo2 Pila::pop()
{
	Tipo2 x;
	if(!pilaVacia())
	{
		x = getVec(getTop());			//valor en la cima
		setTop(getTop()-1);				//-1 top
		return x;
	}else return x;						//valor por defecto
}
Tipo2 Pila::cimaPila()
{
	Tipo2 x;
	if(!pilaVacia())
	{
		x = getVec(getTop());			//valor en la cima
		return x;
	}
		return x;						//valor por defecto
}
void Pila::eliminarElementoPila(Tipo2 x)
{
	Tipo2 a1;
	Pila b;

	while(!pilaVacia())				//ciclo para insertar todos los valores en la pila <b> excepto el valor a eliminar
	{
		a1 = pop();
		if(a1 != x)
		{
			b.push(a1);
		}
	}
										//pila <b< llena y pila <a> vacia
	while(!b.pilaVacia())				//ciclo para insertar en pila <a> los valores de pila <b>
	{
		push(b.pop());
	}
}
void Pila::setVec(Tipo2 val, int pos)
{
	vec[pos] = val;
	setTop(pos);
}	
void Pila::setTop(int v)
{
	top = v;
}
Tipo2 Pila::getVec(int pos)
{
	return vec[pos];
}
int Pila::getTop()
{
	return top;
}