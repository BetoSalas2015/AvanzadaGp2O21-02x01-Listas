//  Sesi�n 29 - 21/10/2021

#include <stdio.h>		//  par ala I/O del programa
#include <stdlib.h>		//  para system()
#include <malloc.h>		// "Memory ALLOCation" - Asignacion de memoria -

struct Nodo 
{
	char info;
	struct Nodo *sig;
};						//  DEfinimos las caracter�sticas del Nodo

typedef struct Nodo nodo;	//  Definimos el nuevo tipo de dato nodo

nodo *raiz = NULL;			// DEfiendo una lista ligada vac�a

void insert(char dato)	//  dato == 'c'
{
	nodo *nuevo = NULL;
	nuevo = (nodo *) malloc( sizeof(nodo) ); // Creamos el nuevo nodo y guardamos su direcci�n en nuevo
	if( nuevo == NULL )					// Ya no hay memoria - Error de Overflow
	{
		printf("Ya no hay memoria disponible.");
		return;
	}
	nuevo->info = dato;
	nuevo->sig = NULL;
	if( raiz == NULL )			// La lista est� vac�a?
	{							//  Verdadero: la lista est� vac�a
		raiz = nuevo;
	} 
	else						// falso: la lista no est� vac�a
	{
		nodo *ultimo = raiz;
		while( ultimo -> sig != NULL )		//  �ultimo No es el �ltimo nodo de la lista?
		{								//  Verdadero: Es el ultimo nodo de la lista
			ultimo = ultimo -> sig;			//  Avanzo al siguiente nodo de la lista
		}
		ultimo->sig = nuevo;
	}	
}

void imprimeLista()
{
	nodo *recorre = raiz;
	while( recorre != NULL )		//  �ultimo No es el �ltimo nodo de la lista?
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

	system("pause");
	return 1;
}