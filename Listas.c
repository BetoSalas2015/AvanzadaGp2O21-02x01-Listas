//  Sesión 32 - 8/10/2021

#include <stdio.h>		//  par ala I/O del programa
#include <stdlib.h>		//  para system()
#include <malloc.h>		// "Memory ALLOCation" - Asignacion de memoria -

struct Nodo 
{
	char info;
	struct Nodo *sig;
};						//  DEfinimos las características del Nodo

typedef struct Nodo nodo;	//  Definimos el nuevo tipo de dato nodo

nodo *raiz = NULL;			// DEfiendo una lista ligada vacía

void insert(char dato)	
{
	nodo *nuevo = NULL;
	nuevo = (nodo *) malloc( sizeof(nodo) ); // Creamos el nuevo nodo y guardamos su dirección en nuevo
	if( nuevo == NULL )					// Ya no hay memoria - Error de Overflow
	{
		printf("Ya no hay memoria disponible.");
		system("pause");
		return;
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
}

void insertn(char dato, int n)	
{
	nodo *nuevo = NULL;
	nuevo = (nodo *) malloc( sizeof(nodo) ); // Creamos el nuevo nodo y guardamos su dirección en nuevo
	if( nuevo == NULL )					// Ya no hay memoria - Error de Overflow
	{
		printf("Ya no hay memoria disponible.");
		system("pause");
		return;
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
	if(n > 2)						//  Para el resto de los nodos
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
}


void insert1(char dato)	
{
	nodo *nuevo = NULL;
	nuevo = (nodo *) malloc( sizeof(nodo) ); // Creamos el nuevo nodo y guardamos su dirección en nuevo
	if( nuevo == NULL )					// Ya no hay memoria - Error de Overflow
	{
		printf("Ya no hay memoria disponible.");
		system("pause");
		return;
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
}

void imprimeLista()
{
	nodo *recorre = raiz;
	while( recorre != NULL )		//  ¿ultimo No es el último nodo de la lista?
	{								//  Verdadero: Es el ultimo nodo de la lista
		printf("%c, ", recorre->info);
		recorre = recorre -> sig;			//  Avanzo al siguiente nodo de la lista
	}
	putchar('\n');
}

char remueven(int n)
{
	nodo *anterior = NULL;
	nodo *siguiente = NULL;
	nodo *elimina = NULL;
	char dato;
	if(raiz != NULL)			//  Si podemos sacar información de la lista
	{
		if(n == 1)
		{
			elimina = raiz;
			siguiente = elimina->sig;
			raiz = siguiente;
			dato = elimina ->info;
			free(elimina);		// Liberamos memoria reservada por malloc
			return dato;
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
			dato = elimina ->info;
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

char remueve1()
{
	nodo *anterior = NULL;
	nodo *siguiente = NULL;
	nodo *elimina = NULL;
	char dato;
	if(raiz != NULL)			//  Si podemos sacar información de la lista
	{
		elimina = raiz;
		siguiente = elimina->sig;
		raiz = siguiente;
		dato = elimina ->info;
		free(elimina);		// Liberamos memoria reservada por malloc
		return dato;
	}
	else            //No hay nada que sacar - Error deUnderflow!
	{
		printf("No hay nada que sacar de la lista");
		system("pause");
		return;
	}
}

int main(void)
{
	imprimeLista();

	insert('R');
	insert('o');
	insert('b');
	insert('e');
	insert('r');
	insert('t');
	insert('o');

	imprimeLista();

	insert(' ');
	insert('S');
	insert('a');
	insert('l');
	insert('a');
	insert('z');
	insert('a');
	insert('r');

	imprimeLista();

	insertn('m', 25);

	imprimeLista();

	remueve1();
	remueve1();
	remueve1();

	imprimeLista();

	system("pause");
	return 1;
}