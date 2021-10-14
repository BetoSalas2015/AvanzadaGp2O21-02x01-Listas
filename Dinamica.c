//  Sesión 25 - 13/10/2021

#include <stdio.h>		//  par ala I/O del programa
#include <stdlib.h>		//  para system()
#include <malloc.h>		// "Memory ALLOCation" - Asignacion de memoria -

int main(void)
{
	int *ptra, *ptrb, *ptrc;	// Creamos tre apuntadores a entero

	ptra = (int *) malloc( sizeof( int ) );		//  Administración dinámica de la memoria
	if( ptra == NULL)
	{
		printf("No hay memoria suficiente\n");
		system("pause");
		return 1;
	}
	ptrb = (int *) malloc( sizeof( int ) );
	ptrc = (int *) malloc( sizeof( int ) );

	printf("Dame el valor de a: ");
	scanf("%d", ptra);
	printf("Dame el valor de b: ");
	scanf("%d", ptrb);

	*ptrc = *ptra + *ptrb;

	printf("La suma es: %d \n", *ptrc);

	free(ptra);				// Liberamos la meoria reservada por malloc()
	free(ptrb);
	free(ptrc);

	system("pause");
	return 1;
}