//  Sesión 34 - 03/11/2021

#include <stdio.h>		//  par ala I/O del programa
#include <stdlib.h>		//  para system()
#include <malloc.h>		// "Memory ALLOCation" - Asignacion de memoria -

struct Nodo 
{
	char info;
	struct Nodo *sig;
};						//  DEfinimos las características del Nodo

typedef struct Nodo nodo;	//  Definimos el nuevo tipo de dato nodo

nodo *raiz = NULL;			// DEfiniendo una lista ligada vacía

nodo *insert(nodo *raiz, char dato)	
{
	nodo *nuevo = NULL;
	nuevo = (nodo *) malloc( sizeof(nodo) ); // Creamos el nuevo nodo y guardamos su dirección en nuevo
	if( nuevo == NULL )					// Ya no hay memoria - Error de Overflow
	{
		printf("Ya no hay memoria disponible.");
		system("pause");
		return raiz;
	}
	nuevo->info = dato;
	nuevo->sig = NULL;
	if( raiz == NULL )			// La lista está vacía?
	{							//  Verdadero: la lista está vacía
		raiz = nuevo;
	} 
	else						// falso: la lista no está vacía
	{
		nodo *ultimo = raiz;
		while( ultimo -> sig != NULL )		//  ¿ultimo No es el último nodo de la lista?
		{								//  Verdadero: Es el ultimo nodo de la lista
			ultimo = ultimo -> sig;			//  Avanzo al siguiente nodo de la lista
		}
		ultimo->sig = nuevo;
	}	
	return raiz;
}

nodo *insertn(nodo *raiz, char dato, int n)	
{
	nodo *nuevo = NULL;
	nuevo = (nodo *) malloc( sizeof(nodo) ); // Creamos el nuevo nodo y guardamos su dirección en nuevo
	if( nuevo == NULL )					// Ya no hay memoria - Error de Overflow
	{
		printf("Ya no hay memoria disponible.");
		system("pause");
		return raiz;
	}
	nuevo->info = dato;
	nuevo->sig = NULL;
	if( raiz == NULL )			// La lista está vacía?
	{							//  Verdadero: la lista está vacía
		raiz = nuevo;
	} 
	if(n == 1)
	{
		nodo *ultimo = raiz;
		raiz = nuevo;
		raiz ->sig = ultimo;
	}
	if(n >= 2)						//  Para el resto de los nodos
	{
		int cont = 1;
		nodo *anterior = raiz;		// Posicionamos anterior
		nodo *siguiente = anterior -> sig;	// Posicionamos siguiente
		while((cont != n - 1) && (anterior->sig != NULL) )		// El error fue que era diferente de en lugar de igual a
		{
			anterior = anterior ->sig;
			siguiente = siguiente->sig;
			cont++;
		}
		anterior ->sig = nuevo;		//  Insertamos el nuevo nodo
		nuevo -> sig = siguiente;
	}	
	return raiz;
}


nodo *insert1(nodo *raiz, char dato)	
{
	nodo *nuevo = NULL;
	nuevo = (nodo *) malloc( sizeof(nodo) ); // Creamos el nuevo nodo y guardamos su dirección en nuevo
	if( nuevo == NULL )					// Ya no hay memoria - Error de Overflow
	{
		printf("Ya no hay memoria disponible.");
		system("pause");
		return raiz;
	}
	nuevo->info = dato;
	nuevo->sig = NULL;
	if( raiz == NULL )			// La lista está vacía?
	{							//  Verdadero: la lista está vacía
		raiz = nuevo;
	} 
	else						// falso: la lista no está vacía
	{
		nodo *ultimo = raiz;
		raiz = nuevo;
		raiz ->sig = ultimo;
	}	
	return raiz;
}

void imprimeLista(nodo *raiz)
{
	nodo *recorre = raiz;
	while( recorre != NULL )		//  ¿ultimo No es el último nodo de la lista?
	{								//  Verdadero: Es el ultimo nodo de la lista
		printf("%c, ", recorre->info);
		recorre = recorre -> sig;			//  Avanzo al siguiente nodo de la lista
	}
	putchar('\n');
}

nodo *remueven(nodo *raiz, int n, char *dato)
{
	nodo *anterior = NULL;
	nodo *siguiente = NULL;
	nodo *elimina = NULL;
	;
	if(raiz != NULL)			//  Si podemos sacar información de la lista
	{
		if(n == 1)
		{
			elimina = raiz;
			siguiente = elimina->sig;
			raiz = siguiente;
			*dato = elimina ->info;
			free(elimina);		// Liberamos memoria reservada por malloc

		}
		else
		{
			int cont = 1;
			anterior = raiz;
			while((cont != n - 1) )	
			{
				anterior = anterior ->sig;
				cont++;
				if(anterior->sig == NULL)		//  Es elúltimo nodo de la lista?
					{
						printf("No existe el nodo %d \n", n);
						//system("pause");
						return '\0';
					}
			}
			elimina = anterior->sig;
			siguiente = elimina -> sig;
			anterior ->sig = siguiente;
			*dato = elimina ->info;
			free(elimina);		// Liberamos memoria reservada por malloc
			return raiz;
		}
	}
	else            //No hay nada que sacar - Error deUnderflow!
	{
		printf("No hay nada que sacar de la lista");
		system("pause");
		return NULL;
	}
	return raiz;
}

char remueve()
{
	nodo *anterior = raiz;
	nodo *siguiente = NULL;
	nodo *elimina = NULL;
	char dato;
	if(raiz != NULL)			//  Si podemos sacar información de la lista
	{
		if(anterior ->sig == NULL)		//  Solo hay un nodo en la lista
		{
			raiz = NULL;		// Alternativa: raiz = anterior -> sig
			dato = anterior ->info;
			free(anterior);		// Liberamos memoria reservada por malloc
			return dato;
		}
		else					// Hay mas de un nodo en la lista
		{
			elimina = anterior ->sig;
			while( elimina ->sig != NULL )	
			{
				anterior = anterior ->sig;
				elimina = elimina -> sig;
			}	
			dato = elimina ->info;
			anterior -> sig = NULL;
			free(elimina);		// Liberamos memoria reservada por malloc
			return dato;
		}
	}
	else            //No hay nada que sacar - Error deUnderflow!
	{
		printf("No hay nada que sacar de la lista");
		system("pause");
		return;
	}
}

nodo *remueve1(nodo *raiz, char *dato)
{
	nodo *siguiente = NULL, *elimina = NULL;
	;
	if(raiz != NULL)			//  Si podemos sacar información de la lista
	{
		elimina = raiz;
		siguiente = elimina->sig;
		raiz = siguiente;
		*dato = elimina ->info;
		free(elimina);		// Liberamos memoria reservada por malloc
		return raiz;
	}
	else            //No hay nada que sacar - Error deUnderflow!
	{
		printf("No hay nada que sacar de la lista");
		system("pause");
		return NULL;
	}
}

nodo *invert(nodo *raiz)
{
	nodo *raiz2 =  NULL;
	nodo *recorre = raiz;
	while(recorre != NULL)
	{
		raiz2 = insert1(raiz2, recorre->info);
		recorre = recorre->sig;
	}
	return raiz2;
}

nodo *merge(nodo* raiz1, nodo *raiz2)
{

}

int main(void)
{
	nodo *nombre = NULL;
	nodo *apellido = NULL;
	nodo *materno = NULL;
	nodo *invertida = NULL;
	char letra;

	nombre = insert(nombre, 'R');
	nombre = insert(nombre, 'o');
	nombre = insert(nombre, 'b');
	nombre = insert(nombre, 'e');
	nombre = insert(nombre, 'r');
	nombre = insert(nombre, 't');
	nombre = insert(nombre, 'o');

	apellido = insert1(apellido, 'S');
	apellido = insert1(apellido, 'a');
	apellido = insert1(apellido, 'l');
	apellido = insert1(apellido, 'a');
	apellido = insert1(apellido, 'z');
	apellido = insert1(apellido, 'a');
	apellido = insert1(apellido, 'r');

	materno = insertn(materno, 'M', 50);
	materno = insertn(materno, 'a', 1);
	materno = insertn(materno, 'r', 1);
	materno = insertn(materno, 'q', 2);
	materno = insertn(materno, 'u', 2);
	materno = insertn(materno, 'e', 4);
	materno = insertn(materno, 'z', 5);

	imprimeLista(nombre);
	imprimeLista(apellido);
	imprimeLista(materno);

	invertida = invert(materno);

	imprimeLista(invertida);

	nombre = remueven(nombre, 2, &letra);
	printf("El dato que salió de la lista fue: %c\n", letra);

	imprimeLista(nombre);

	nombre = remueven(nombre, 3, &letra);
	printf("El dato que salió de la lista fue: %c\n", letra);

	imprimeLista(nombre);
	//-----------------------

	apellido = remueve1(apellido, &letra);
	printf("El dato que salió de la lista fue: %c\n", letra);

	imprimeLista(apellido);


		

	system("pause");
	return 1;
}