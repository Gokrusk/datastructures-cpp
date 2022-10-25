// TDA Vector
#define EXT 20

class Vector // Definicion de la clase
{
private:
	int n, // dimension vector
		vec[EXT];

public:
	Vector(); // constructor
	void leerV();
	void imprimirV();
	int buscar(int n);
	int busquedaBinaria(int val);
	void ordenarBubble();
	void ordenarInsercion();
	void ordernarSeleccion();
	int buscarMayor();
	int buscarMenor();
	void setN(int val); // modifica estado del atributo n
	void setV(int val, int pos); // modifica estado del atributo vec
	int getN();
	int getV(int pos);
};

Vector::Vector()
	{
		setN(0);
	}
void Vector::leerV()
	{
		int aux;						   // var lectura
		for (int i = 0; (i < getN()); i++) // ciclo recorrido vector
		{
			cout << "Ingrese valor para posicion [" << i << "]: ";
			cin >> aux;
			setV(aux, i); // actualizar arreglo
		}
	}
void Vector::imprimirV()
	{
		for (int i = 0; (i < getN()); i++) // ciclo recorrido vector
		{
			cout << "Valor almacenado en la posicion [" << i << "] " << getV(i) << endl;
		}
	}
int Vector::buscar(int n)
	{
		for (int i = 0; (i < getN()); i++) // ciclo recorrido vector
		{
			if (getV(i) == n)
			{
				return i; // posicion en que se encuentra el valor
			}
		}
		return -1;
	}
int Vector::busquedaBinaria(int val)
	{
		int i = 0, fin = getN() - 1; // posinicial y posfinal

		while (i <= fin) // mientras posinicioo este a la izq de posfinal
		{
			int m = (i + fin) / 2; // posicion central
			cout << "I: " << i << " F:" << fin << " M:" << m << endl;
			if (getV(m) == val) // elemento del vector igual al valor buscado
			{
				return m; // devolver posicion que ocupa el valor buscado
			}
			else
			{
				if (getV(m) < val)
				{			   // elemento pos central es menor que lo buscado
					i = m + 1; // posini es siguiente a la pos central
				}
				else			 // pos centra es mayor que lo buscado				{
					fin = m - 1; // posfin es anterior a poscentral
			}
		}
		return -1;
	}
void Vector::ordenarBubble()
	{
		int aux;
		for (int i = 0; i < getN(); i++)
		{
			for (int j = 0; j < getN() - 1; j++)
			{
				if (getV(j) > getV(j + 1)) // elemento1 > a elemento siguiente se intercambia posiciones
				{
					aux = getV(j);
					setV(getV(j + 1), j);
					setV(aux, j + 1);
				}
			}
		}
	}
void Vector::ordenarInsercion()
	{
		int i, aux, j;
		for (i = 1; i < getN(); i++)
		{
			aux = getV(i);
			j = i - 1;
			while (j >= 0 && getV(j) > aux)
			{
				setV(getV(j), (j + 1));
				j = j - 1;
			}
			setV(aux, (j + 1));
		}
	}
void Vector::ordernarSeleccion()
	{
		int aux, min;
		for (int i = 0; i < getN() - 1; i++)
		{
			for (int j = i + 1; j < getN(); j++)
			{
				if (getV(j) < getV(min))
				{
					min = j;
				}
				if (min != i)
				{
					aux = getV(min);
					setV(getV(i), min);
					setV(aux, i);
				}
			}
		}
	}
int Vector::buscarMayor()
	{
		return getV(n-1);
	}
int Vector::buscarMenor()
	{
		return getV(0);
	}
void Vector::setN(int val) // modifica estado del atributo n
	{
		n = val;
	}
void Vector::setV(int val, int pos) // modifica estado del atributo vec
	{
		vec[pos] = val;
	}
int Vector::getN()
	{
		return n;
	}
int Vector::getV(int pos)
	{
		return vec[pos];
	}