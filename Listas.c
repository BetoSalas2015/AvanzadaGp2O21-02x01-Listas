//  Sesi�n 27 - 18/10/2021

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

void insert(char dato)
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
	}
	
}

int main(void)
{
	int edad;
	nodo primero;
	system("pause");
	return 1;
}