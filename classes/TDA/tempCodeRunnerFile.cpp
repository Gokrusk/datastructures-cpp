/*	while(!a->pilaVacia())				//ciclo para insertar todos los valores en la pila <b> excepto el valor menor
		{
			a1 = a->pop();
			if(a1 != men)
			{
				b.push(a1);
			}
		}
											//pila <b< llena y pila <a> vacia
		while(!b.pilaVacia())				//ciclo para insertar en pila <a> los valores de pila <b>
		{
			a->push(b.pop());
		}*