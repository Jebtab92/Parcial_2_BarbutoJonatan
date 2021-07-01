/*
 * Libro.h
 *
 *  Created on: Jun 29, 2021
 *      Author: jonat
 */

#ifndef LIBRO_H_
#define LIBRO_H_
#include "LinkedList.h"
typedef struct
{
	int id;
	char titulo[100];
	char autor[100];
	int precio;
	int idEditorial;
}eLibro;

typedef struct
{
	int id;
	char nombreEditorial[100];
}eEditorial;


eLibro* libro_new();
eLibro* libro_newParametros(char* idStr, char* tituloStr, char* autorStr, char* precioStr, int idEditorial);
void libro_delete(eLibro* lista);
int libro_setId(eLibro* this, int id);
int libro_getId(eLibro* this, int* id);
int libro_setTitulo(eLibro* this, char* titulo);
int libro_getTitulo(eLibro* this, char* titulo);
int libro_setAutor(eLibro* this, char* autor);
int libro_getAutor(eLibro* this, char* autor);
int libro_setPrecio(eLibro* this, int precio);
int libro_getPrecio(eLibro* this, int* precio);
int libro_printLibro(LinkedList* pArrayListLibro, int index);
int libro_OrdenarID(void* elementoA, void* elementoB);
int libro_OrdenarPrecio(void* elementoA, void* elementoB);
int libro_OrdenarTitulo(void* elementoA, void* elementoB);
int libro_OrdenarAutor(void* elementoA, void* elementoB);
int libro_getIdEditorial(eLibro* this, int* idEditorial);
void completarEditoriales(eEditorial* lista, int size);
void printEditoriales(eEditorial* lista, int size);
int libro_countPrecio(void* libro);
int libro_setIdEditorial(eLibro* this, int idEditorial);

void libro_aplicarDescuento(void* this);
int libro_buscarEditorial(int idEditorial, char* descripcion);

#endif /* LIBRO_H_ */
