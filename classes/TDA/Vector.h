// TDA Vector
#define EXT 20

class Vector					//Definicion de la clase
{
	private:	
			int n, 				//dimension vector
				vec[EXT];
	public:
			Vector()			//constructor
			{
				setN(0);
			}
			void leerV()
			{
				int aux;		//var lectura
				for(int i=0;(i<getN());i++)		//ciclo recorrido vector
				{
					cout<<"Ingrese valor para posicion ["<<i<<"]: ";
					cin>>aux;
					setV(aux,i);			//actualizar arreglo
				}
			}
			void imprimirV()
			{
				for(int i=0;(i<getN());i++)		//ciclo recorrido vector
				{
					cout<<"Valor almacenado en la posicion ["<<i<<"] "<<getV(i)<<endl;
				}
			}
			int buscar(int n)
			{
				for(int i=0;(i<getN());i++)		//ciclo recorrido vector
				{
					if(getV(i) == n)
					{
						return i;	//posicion en que se encuentra el valor
					}
				}
				return -1;
			}
			void setN(int val)	//modifica estado del atributo n
			{
				n = val;
			}
			void setV(int val, int pos)	//modifica estado del atributo vec
			{
				vec[pos] = val;
			}
			int getN()
			{
				return n;
			}
			int getV(int pos)
			{
				return vec[pos];
			}		
};