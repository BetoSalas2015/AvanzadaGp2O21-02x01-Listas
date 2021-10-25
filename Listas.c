//  Sesión 30 - 25/10/2021

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
		while(cont != n - 1)		// El error fue que era diferente de en lugar de igual a
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

	insertn('m', 5);

	imprimeLista();

	system("pause");
	return 1;
}