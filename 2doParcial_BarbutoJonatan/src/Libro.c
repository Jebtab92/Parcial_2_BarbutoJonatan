#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libro.h"
#include "Biblioteca.h"
#include "LinkedList.h"

/*
 * \brief Crea el espacio en memoria dinamica con tamanio eLibro
 * \param void
 * \return puntero a eLibro
 */
eLibro* libro_new()
{
    return (eLibro*) malloc(sizeof (eLibro));
}

/*
 * \brief Crea el espacio en memoria dinamica y completa los campos
 * \param *id, *nombre, *horas, *sueldo llama a las funciones setter
 * \return nueva direccion donde se encuentra el employee
 */
eLibro* libro_newParametros(char* idStr, char* tituloStr, char* autorStr, char* precioStr, int idEditorial)
{
    eLibro* aux;
    aux = libro_new();

    if(aux !=  NULL)
    {
        libro_setId(aux , atoi(idStr));
        libro_setTitulo(aux, tituloStr);
        libro_setAutor(aux, autorStr);
        libro_setPrecio(aux, atoi(precioStr));
        libro_setIdEditorial(aux, idEditorial);
    }
    return aux;
}

/*
 * \brief Setea el id del libro
 * \param * a eLibro, id
 * \return 0 si funcion, -1 si hubo un error
 */
int libro_setId(eLibro* this, int id)
{
    int Retorno = -1;

    if(this != NULL && id > 0)
    {
        (*this).id = id;
        Retorno = 0;
    }
    return Retorno;
}

/*
 * \brief Obtiene id del libro
 * \param * a un eLibro, *para escribir el id
 * \return 0 si funciono, -1 si hubo un error
 */
int libro_getId(eLibro* this, int* id)
{
    int Retorno = -1;

    if(this != NULL && id != NULL)
    {
        *id = (*this).id;
        Retorno = 0;
    }
    return Retorno;
}

/*
 * \brief Setea el nombre del libro
 * \param * a eLibro, * a nombre
 * \return 0 si funcion, -1 si hubo un error
 */
int libro_setTitulo(eLibro* this, char* titulo)
{
    int Retorno = -1;

    if(this != NULL)
    {
         strcpy((*this).titulo, titulo);
    }
    return Retorno;
}

/*
 * \brief Obtiene titulo del libro
 * \param * a un eLibro, *para escribir el titulo
 * \return 0 si funciono, -1 si hubo un error
 */
int libro_getTitulo(eLibro* this, char* titulo)
{
    int Retorno = -1;

    if(this != NULL && titulo != NULL)
    {
        strcpy(titulo, (*this).titulo);
        Retorno = 1;
    }
    return Retorno;
}

/*
 * \brief Setea el autor del libro
 * \param * a eLibro, * a autor
 * \return 0 si funcion, -1 si hubo un error
 */
int libro_setAutor(eLibro* this, char* autor)
{
    int Retorno = -1;

    if(this != NULL)
    {
         strcpy((*this).autor, autor);
    }
    return Retorno;
}

/*
 * \brief Obtiene autor del libro
 * \param * a un eLibro, *para escribir el autor
 * \return 0 si funciono, -1 si hubo un error
 */
int libro_getAutor(eLibro* this, char* autor)
{
    int Retorno = -1;

    if(this != NULL && autor != NULL)
    {
        strcpy(autor, (*this).autor);
        Retorno = 1;
    }
    return Retorno;
}

/*
 * \brief Setea precio del libro
 * \param * a eLibro, precio
 * \return 0 si funcion, -1 si hubo un error
 */
int libro_setPrecio(eLibro* this, int precio)
{
    int Retorno = -1;

    if(this != NULL && precio > 0)
    {
        (*this).precio = precio;
        Retorno = 0;
    }
    return Retorno;
}

/*
 * \brief Obtiene precio del libro
 * \param * a un eLibro, *para escribir el precio
 * \return 0 si funciono, -1 si hubo un error
 */
int libro_getPrecio(eLibro* this, int* precio)
{
    int Retorno=-1;

    if(this != NULL && precio != NULL)
    {
        *precio = (*this).precio;
        Retorno = 0;
    }
    return Retorno;
}

/*
 * \brief Setea id de la editorial
 * \param * a eLibro, idEditorial
 * \return 0 si funcion, -1 si hubo un error
 */
int libro_setIdEditorial(eLibro* this, int idEditorial)
{
    int Retorno = -1;

    if(this != NULL && idEditorial > 0)
    {
        (*this).idEditorial = idEditorial;
        Retorno = 0;
    }
    return Retorno;
}

/*
 * \brief Obtiene id de la editorial
 * \param * a un eLibro, *para escribir el idEditorial
 * \return 0 si funciono, -1 si hubo un error
 */
int libro_getIdEditorial(eLibro* this, int* idEditorial)
{
    int Retorno=-1;

    if(this != NULL && idEditorial != NULL)
    {
        *idEditorial = (*this).idEditorial;
        Retorno = 0;
    }
    return Retorno;
}

/*
 * \brief Obtiene id de la editorial
 * \param * a un eLibro, *para escribir el idEditorial
 * \return 0 si funciono, -1 si hubo un error
 */
int libro_buscarEditorial(int idEditorial, char* descripcion)
{
    int retorno =-1;

    if(idEditorial > 0 || idEditorial <= 6)
    {
		if(idEditorial == 1)
		{
			strcpy(descripcion, "PLANETA");
		}
		if(idEditorial == 2)
		{
			strcpy(descripcion, "SIGLO XXI EDITORES");
		}
		if(idEditorial == 3)
		{
			strcpy(descripcion, "PEARSON");
		}
		if(idEditorial == 4)
		{
			strcpy(descripcion, "MINOTAURO");
		}
		if(idEditorial == 5)
		{
			strcpy(descripcion, "SALAMANDRA");
		}
		if(idEditorial == 6)
		{
			strcpy(descripcion, "PENGUIN BOOKS");
		}
		retorno = 1;
    }
    return retorno;
}

/*
 * \brief recibe un puntero al libro y lo cambia a vacio
 * \param * a libro
 * \return void
 */
void libro_delete(eLibro* lista)
{
    if(lista !=  NULL)
    {
        (*lista).id = 0;
        strcpy((*lista).titulo, "");
        strcpy((*lista).autor, "");
        (*lista).precio = 0;
        (*lista).idEditorial = 0;
    }
    free(lista);
}

/*
 * \brief Imprime libro
 * \param * a la lista de libros, index a imprimir
 * \return 0 si funciono, -1 si hubo un error
 */
int libro_printLibro(LinkedList* pArrayListLibro, int index)
{
    eLibro* libroAux;
    int id;
    char titulo[100];
    char autor[100];
    int precio, idEditorial;
    char editorial[100];
    int Retorno = -1;

    if(pArrayListLibro != NULL && index >= 0 && index < ll_len(pArrayListLibro))
    {
        libroAux = (eLibro*)ll_get(pArrayListLibro, index);
        libro_getId(libroAux, &id);
        libro_getTitulo(libroAux, titulo);
        libro_getAutor(libroAux, autor);
        libro_getPrecio(libroAux, &precio);
        libro_getIdEditorial(libroAux, &idEditorial);
        libro_buscarEditorial(idEditorial, editorial);
        printf("|%10d | %50s | %20s | %10d | %20s |\n", id, titulo, autor, precio, editorial);
        Retorno = 0;
    }
    return Retorno;
}

/*
 * \brief Ordenar por ID
 * \param recibe dos punteros a dos elementos
 * \return 1 si el puntero a es mayor al b o -1 si el puntero b es mayor al a, 0 si hubo error
 */
int libro_OrdenarID(void* elementoA, void* elementoB)
{
    int Retorno = 0;
    eLibro* libroA;
    eLibro* libroB;
    libroA = (eLibro*)elementoA;
    libroB = (eLibro*)elementoB;

    if((*libroA).id > (*libroB).id)
    {
        Retorno = 1;
    }
    else if((*libroA).id < (*libroB).id)
    {
        Retorno = -1;
    }
    return Retorno;
}

/*
 * \brief Ordenar por precio
 * \param recibe dos punteros a dos elementos
 * \return 1 si el puntero a es mayor al b o -1 si el puntero b es mayor al a, 0 si hubo error
 */
int libro_OrdenarPrecio(void* elementoA, void* elementoB)
{
    int Retorno = 0;
    eLibro* libroA;
    eLibro* libroB;
    libroA = (eLibro*)elementoA;
    libroB = (eLibro*)elementoB;

    if((*libroA).precio > (*libroB).precio)
    {
        Retorno = 1;
    }
    else if((*libroA).precio < (*libroB).precio)
    {
        Retorno = -1;
    }
    return Retorno;
}

/*
 * \brief Ordenar por titulo
 * \param recibe dos punteros a dos elementos
 * \return 1 si el puntero a es mayor al b o -1 si el puntero b es mayor al a, 0 si hubo error
 */
int libro_OrdenarTitulo(void* elementoA, void* elementoB)
{
    int Retorno = 0;
    eLibro* libroA;
    eLibro* libroB;
    libroA = (eLibro*)elementoA;
    libroB = (eLibro*)elementoB;

    if(strcmp((*libroA).titulo, (*libroB).titulo) < 0)
    {
        Retorno = 1;
    }
    if(strcmp((*libroB).titulo, (*libroA).titulo) > 0)
    {
        Retorno = -1;
    }
    return Retorno;
}

/*
 * \brief Ordenar por autor
 * \param recibe dos punteros a dos elementos
 * \return 1 si el puntero a es mayor al b o -1 si el puntero b es mayor al a, 0 si hubo error
 */
int libro_OrdenarAutor(void* elementoA, void* elementoB)
{
    int Retorno = 0;
    eLibro* libroA;
    eLibro* libroB;
    libroA = (eLibro*)elementoA;
    libroB = (eLibro*)elementoB;

    if(strcmp((*libroA).autor, (*libroB).autor) < 0)
    {
        Retorno = 1;
    }
    if(strcmp((*libroB).autor, (*libroA).autor) > 0)
    {
        Retorno = -1;
    }
    return Retorno;
}

void completarEditoriales(eEditorial* lista, int size)
{
	int i;
	if(lista != NULL && size > 0)
	{
		int id[6] = {1,2,3,4,5,6};
		char nombre[][50] = {"PLANETA", "SIGLO XXI EDITORES", "PEARSON", "MINOTAURO", "SALAMANDRA", "PENGUIN BOOKS"};
		for(i = 0; i < size; i++)
		{
			lista[i].id = id[i];
			strcpy(lista[i].nombreEditorial, nombre[i]);
		}
	}
}

void printEditoriales(eEditorial* lista, int size)
{
	int i;

	for(i=0; i<size;i++)
	{
		printf("%d - %s\n", lista[i].id, lista[i].nombreEditorial);
	}
}

void libro_aplicarDescuento(void* this)
{
	int aPrecio, aId;
	libro_getIdEditorial(this, &aId);
	libro_getPrecio(this, &aPrecio);

	if(aPrecio > 0 && aId > 0)
	{
		switch(aId)
		{
			case 1:
			{
				if(aPrecio>=300)
				{
					aPrecio=aPrecio-(aPrecio*20/100);
					libro_setPrecio(this, aPrecio);
				}
				break;
			}
			case 2:
			{
				if(aPrecio<=200)
				{
					aPrecio=aPrecio-(aPrecio*10/100);
					libro_setPrecio(this, aPrecio);
				}
				break;
			}
			case 3:
			{
				break;
			}

			case 4:
			{
				break;
			}
			case 5:
			{
				break;
			}
			case 6:
			{
				break;
			}
		}
	}
}

int libro_countPrecio(void* libro)
{
	int retorno;
	int auxPrecio;
	eLibro* auxLibro = (eLibro*) libro;

	if(auxLibro != NULL)
	{
		libro_getPrecio(auxLibro, &auxPrecio);

		if(auxPrecio > 100)    // Aca se puede editar el precio
		{
			retorno = 1;
		}
		else
		{
			retorno = 0;
		}
	}
	return retorno;
}

// Falta esta funcion para q funcione

int libro_countEditorial(void* libro)
{
	int retorno;
	int auxIdEditorial;
	eLibro* auxLibro = (eLibro*) libro;
	if(auxLibro != NULL)
	{
		libro_getIdEditorial(auxLibro, &auxIdEditorial);
		switch(auxIdEditorial)
		{
			case 1:
			{
				break;
			}
			case 2:
			{
				break;
			}
			case 3:
			{
				break;
			}

			case 4:
			{
				break;
			}
			case 5:
			{
				break;
			}
			case 6:
			{
				break;
			}
		}
	}
	return retorno;
}











