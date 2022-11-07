//TDA COLA
typedef int Tipo;
#define EXT 20
class Cola{											//Definicion de clase
	private:										//Atributos
			int frente;
			int final;
			Tipo elem[EXT];							//Arreglos de valores de la cola
	public:											//Metodos
			Cola();
			void setFrente(int x);					//Actualiza atributo frente
			void setFinal(int x);					//Actualiza atributo final
			void setElem(int v, int p);				//Actualiza atributo elem[x,p]
			int getFrente();						//Retorna atributo frente
			int getFinal();							//Retorna atributo final
			Tipo getElem(int p);					//Retorna elemento atributo elem
};

Cola::Cola()
{
	setFrente(0);									//Inicializr la pos apuntada por frente
	setFinal(-1);									//Inicializr la pos apuntada por final
}
void Cola::setFrente(int x)
{
	frente = x;
}				
void Cola::setFinal(int x)
{
	final = x;
}					
void Cola::setElem(int v, int p)
{
	elem[p] = v;
}
int Cola::getFrente()
{
	return frente;
}
int Cola::getFinal()
{
	return final;
}
Tipo Cola::getElem(int p)
{
	return elem[p];
}



