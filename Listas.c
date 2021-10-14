//  Sesión 26 - 14/10/2021

#include <stdio.h>		//  par ala I/O del programa
#include <stdlib.h>		//  para system()
#include <malloc.h>		// "Memory ALLOCation" - Asignacion de memoria -

struct Nodo 
{
	char info;
	struct Nodo *sig:
};						//  DEfinimos las características del Nodo

typedef struct Nodo nodo;	//  Definimos el nuevo tipo de dato nodo

nodo *raiz = NULL;			// DEfiendo una lista ligada vacía

void insert(char dato)
{
	nodo *nuevo = NULL;
	nuevo = (nodo *) malloc( sizeof(nodo) ); // Creamos el nuevo nodo
}

int main(void)
{
	int edad;
	nodo primero;
	system("pause");
	return 1;
}