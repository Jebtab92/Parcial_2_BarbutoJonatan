#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Libro.h"
#include "Parser.h"
#include "Biblioteca.h"
#include "Controller.h"

/** \brief Carga los datos de los libros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListLibro, int* lastID)
{
    FILE* f;
    int retorno = -1;
    f = fopen(path, "r");
    if(ll_len(pArrayListLibro) == 0)
    {
		if(f == NULL)
		{
			printf("\n--Error al abrir el archivo de texto, Corrobore si existe--\n");
			system("pause");
		}
		else
		{
			retorno = 0;
			printf("\n--Archivo abierto correctamente--\n");
			retorno = parser_LibroFromText(f, pArrayListLibro, lastID);
			system("pause");
		}
    }
    else
    {
    	printf("\n--El archivo ya fue cargado--\n");
    	system("pause");
    }
    fclose(f);
    return retorno;
}

/** \brief Carga los datos de los libros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int
 *
 */
/*int controller_loadFromBinary(char* path, LinkedList* pArrayListLibro)
{
    FILE* f;
    int retorno = -1;
    f = fopen(path, "rb");
    if(ll_len(pArrayListLibro) == 0)
    {
		if(f == NULL)
		{
			retorno = 0;
			printf("Error al abrir el archivo de Binary, Corrobore si existe.\n");
		}
		else
		{
			retorno = 1;
			retorno = parser_LibroFromBinary(f, pArrayListLibro);
			printf("Archivo de texto abierto\n");
		}
    }
    else
    {
    	printf("El archivo ya fue cargado!.\n\n");
    	system("pause");
    }
    fclose(f);
    return retorno;
}*/

/** \brief Alta de libro
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \param puntero contador ID.
 * \return int
 *
 */
/*int controller_addLibro(LinkedList* pArrayListLibro, int* contadorID)    // Falta dar el alta
{
    eLibro* libroNuevo;
	int retorno = -1;
    int id;
    int precio;

    char idS[100];
    char titulo[100];
    char autor[100];
    char sueldoS[100];
    char horasTrabajadasS[100];

    if(ll_len(pArrayListLibro) != 0)
    {

		Get_OnlyAlphabetStringWithSpaces("\nIngrese Titulo: ", "\nError reingrese: ", titulo, 100, 3);
		Get_OnlyAlphabetStringWithSpaces("\nIngrese Autor: ", "\nError reingrese: ", autor, 100, 3);
		precio = Get_IntPositive("\nIngrese Precio: ", "\nError, reingrese: ", 3);

		sprintf(sueldoS, "%d", precio);
		sprintf(horasTrabajadasS, "%d", horasTrabajadas);
		(*contadorID)++;
		id = *contadorID;
		sprintf(idS, "%d", id);

		libroNuevo = libro_newParametros(idS, nombre, horasTrabajadasS, sueldoS);
		ll_add(pArrayListLibro, libroNuevo);
		retorno = 0;
		printf("\n\ndatos cargados correctamente!\n");
    }
    else
    {
    	printf("\n\nNo es posible dar de alta Nuevos empleados...\n");
    }
	return retorno;
}*/

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int
 *
 */
int controller_editLibro(LinkedList* pArrayListLibro, eEditorial* listaEditorial, int sizeE)
{
    eLibro* libro;
    int id, i, idAuxiliar;
    int flag = 0;
    int menu;
    char titulo[100];
    char autor[100];
    int precio, idEditorial;

    if(ll_len(pArrayListLibro) != 0)
    {
		printf("\n Ingrese el ID del libro a modificar: ");
		scanf("%d", &id);
		for(i = 0; i < ll_len(pArrayListLibro); i++)
		{
			libro = (eLibro*)ll_get(pArrayListLibro, i);
			libro_getId(libro, &idAuxiliar);
			if(libro != NULL && id == idAuxiliar)
			{
		    	printf("\n+--------------------------------------------------------------------------------------------------------------------------+\n");
		    	printf("|%10s  %25s  %15s  %15s  %25s|\n","ID","TITULO","AUTOR","PRECIO","EDITORIAL");
		    	printf("+---------------------------------------------------------------------------------------------------------------------------+\n");
				libro_printLibro(pArrayListLibro, i);
				switch(menu = Get_IntRange("\n\n------------------------------Menu de Modificaciones----------------------------------- \n\n"
							  "1) Titulo\n"
							  "2) Autor\n"
							  "3) Precio\n"
							  "4) Editorial\n"
							  "5) Salir\n"
							  "Opcion: ", "\nError, reingrese: ", 1, 5, 3))
				{
					case 1:
					{
						Get_OnlyAlphabetStringWithSpaces("\nIngrese Titulo: ", "\nError, reingrese: ", titulo, 100, 3);
						libro_setTitulo(libro, titulo);
						printf("\n--Titulo cambiado con exito--\n");
				    	printf("\n+--------------------------------------------------------------------------------------------------------------------------+\n");
				    	printf("|%10s  %25s  %15s  %15s  %25s|\n","ID","TITULO","AUTOR","PRECIO","EDITORIAL");
				    	printf("+---------------------------------------------------------------------------------------------------------------------------+\n");
						libro_printLibro(pArrayListLibro, i);
						system("pause");
						break;
					}
					case 2:
					{
						Get_OnlyAlphabetStringWithSpaces("\nIngrese Autor: ", "\nError, reingrese: ", autor, 100, 3);
						libro_setAutor(libro, autor);
						printf("\n--Autor cambiado con exito--\n");
				    	printf("\n+--------------------------------------------------------------------------------------------------------------------------+\n");
				    	printf("|%10s  %25s  %15s  %15s  %25s|\n","ID","TITULO","AUTOR","PRECIO","EDITORIAL");
				    	printf("+---------------------------------------------------------------------------------------------------------------------------+\n");
						libro_printLibro(pArrayListLibro, i);
						system("pause");
						break;
					}
					case 3:
					{
						precio = Get_IntRange("\nIngrese precio: ", "\nError, reingrese: ", 1, 999999, 3);
						libro_setPrecio(libro, precio);
						printf("\n--Precio cambiado con exito--\n");
				    	printf("\n+--------------------------------------------------------------------------------------------------------------------------+\n");
				    	printf("|%10s  %25s  %15s  %15s  %25s|\n","ID","TITULO","AUTOR","PRECIO","EDITORIAL");
				    	printf("+---------------------------------------------------------------------------------------------------------------------------+\n");
						libro_printLibro(pArrayListLibro, i);
						system("pause");
						break;
					}
					case 4:
					{
						printEditoriales(listaEditorial, sizeE);
						idEditorial = Get_IntRange("\nIngrese id de la editorial: ", "\nError, reingrese: ", 1, 6, 3);
						libro_setIdEditorial(libro, idEditorial);
						printf("\n--Editorial cambiada con exito--\n");
				    	printf("\n+--------------------------------------------------------------------------------------------------------------------------+\n");
				    	printf("|%10s  %25s  %15s  %15s  %25s|\n","ID","TITULO","AUTOR","PRECIO","EDITORIAL");
				    	printf("+---------------------------------------------------------------------------------------------------------------------------+\n");
						libro_printLibro(pArrayListLibro, i);
						system("pause");
						break;
					}
					case 5:
					{
						break;
					}
				}
				flag = 1;
			}
		}
		if(flag == 0)
		{
			printf("\nLibro no encontrado\n");
		}
    }
    else
    {
    	printf("\n--No es posible modificar Libros...Cargue un archivo previamente--\n");
    }
    return 1;
}

/** \brief Baja de libro
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int
 *
 */
int controller_removeLibro(LinkedList* pArrayListLibro)
{
    int libroEliminar;
    int len;
    int i;
    int retorno = -1;
    int encontro = 0;
    eLibro* libro;
    len = ll_len(pArrayListLibro);

    if(ll_len(pArrayListLibro) != 0)
    {
		printf("Ingrese el ID que desea eliminar: ");
		scanf("%d", &libroEliminar);
		for(i = 0; i < len; i++)
		{
			libro = (eLibro*) ll_get(pArrayListLibro, i);
			if((*libro).id == libroEliminar)
			{
		    	printf("+---------------------------------------------------------------------------------------------------------------------------+\n");
		    	printf("|%10s  %25s  %15s  %15s  %25s|\n","ID","TITULO","AUTOR","PRECIO","EDITORIAL");
		    	printf("+---------------------------------------------------------------------------------------------------------------------------+\n");
		    	libro_printLibro(pArrayListLibro, i);

				if(Validate_Exit_SN("Desea continuar con la baja? Si[s] - No[n]: ", "\nError, reingrese: ", 3) == 1)
				{
					ll_remove(pArrayListLibro, i);
					printf("\n--Libro eliminado correctamente--\n");
					retorno = 0;
					encontro = 1;
					break;
				}
				else
				{
					printf("\n--No se pudo eliminar el libro--\n");
					break;
				}
			}
		}
		if(encontro == 0)
		{
			printf("\n--No se encontro ID--\n");
		}
    }
    else
    {
    	printf("\n--No se puede borrar libros...Cargue un archivo previamente--\n");
    }
    system("pause");
    return retorno;
}

/** \brief Listar libros
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int
 *
 */
int controller_ListLibro(LinkedList* pArrayListLibro)
{
    int retorno = -1;
    int i, len;
    len = ll_len(pArrayListLibro);
    if(pArrayListLibro != NULL && len > 0)
    {
    	printf("\n+---------------------------------------------------------------------------------------------------------------------------+\n");
    	printf("|%10s  %50s  %20s  %10s  %25s|\n","ID","TITULO","AUTOR","PRECIO","EDITORIAL");
    	printf("+---------------------------------------------------------------------------------------------------------------------------+\n");
        for(i = 0; i < len; i++)
        {
            libro_printLibro(pArrayListLibro, i);
            printf("+---------------------------------------------------------------------------------------------------------------------------+\n");
            retorno = 0;
        }
    }
    else
    {
    	printf("No hay datos a mostrar.\n");
    }
    return retorno;
}

/** \brief Ordenar libro
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int
 *
 */
int controller_sortLibro(LinkedList* pArrayListLibro)
{
	int menu;
	int len;
	len = ll_len(pArrayListLibro);
	if(pArrayListLibro != NULL && len > 0)
	{
		system("cls");
		switch(menu = Get_IntRange("------------------------------Menu de Ordenamiento-----------------------------------\n"
									"1) ID ascendente\n"
									"2) ID descendente\n"
									"3) Titulo ascendente\n"
									"4) Titulo descendente\n"
									"5) Autor ascendente\n"
									"6) Autor descendente\n"
									"7) Precio ascendente\n"
									"8) Precio descendente\n"
									"9) Salir\n"
									"Opcion: ","\nError, Reintente \n", 1, 9, 3))
		{
			case 1:
				printf("\n--Ordenando espere por favor--\n");
				if(ll_sort(pArrayListLibro, libro_OrdenarID, 1) == 0)
				{
					printf("\n--Ordenado correctamente--\n");
				}
				else
				{
					printf("\n--Hubo un error, reintente--\n");
				}
				break;
			case 2:
				printf("\n--Ordenando espere por favor--\n");
				if(ll_sort(pArrayListLibro, libro_OrdenarID, 0) == 0)
				{
					printf("\n--Ordenado correctamente--\n");
				}
				else
				{
					printf("\n--Hubo un error, reintente--\n");
				}
				break;
			case 3:
				printf("\n--Ordenando espere por favor--\n");
				if(ll_sort(pArrayListLibro, libro_OrdenarTitulo, 1) == 0)
				{
					printf("\n--Ordenado correctamente--\n");
				}
				else
				{
					printf("\n--Hubo un error, reintente--\n");
				}
				break;
			case 4:
				printf("\n--Ordenando espere por favor--\n");
				if(ll_sort(pArrayListLibro, libro_OrdenarTitulo, 0) == 0)
				{
					printf("\n--Ordenado correctamente--\n");
				}
				else
				{
					printf("\n--Hubo un error, reintente--\n");
				}
				break;
			case 5:
				printf("\n--Ordenando espere por favor--\n");
				if(ll_sort(pArrayListLibro, libro_OrdenarAutor, 1) == 0)
				{
					printf("\n--Ordenado correctamente--\n");
				}
				else
				{
					printf("\n--Hubo un error, reintente--\n");
				}
				break;
			case 6:
				printf("\n--Ordenando espere por favor--\n");
				if(ll_sort(pArrayListLibro, libro_OrdenarAutor, 0) == 0)
				{
					printf("\n--Ordenado correctamente--\n");
				}
				else
				{
					printf("\n--Hubo un error, reintente--\n");
				}
				break;
			case 7:
				printf("\n--Ordenando espere por favor--\n");
				if(ll_sort(pArrayListLibro, libro_OrdenarPrecio, 0) == 0)
				{
					printf("\n--Ordenado correctamente--\n");
				}
				else
				{
					printf("\n--Hubo un error, reintente--\n");
				}
				break;
			case 8:
				printf("\n--Ordenando espere por favor--\n");
				if(ll_sort(pArrayListLibro, libro_OrdenarPrecio, 0) == 0)
				{
					printf("\n--Ordenado correctamente--\n");
				}
				else
				{
					printf("\n--Hubo un error, reintente--\n");
				}
				break;
			case 9:
				break;
		}
	}
	else
	{
		printf("\n--No hay datos para ordenar--\n");
		system("pause");
	}
	return 1;
}

/** \brief Guarda los datos de los libros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListLibro)
{
    FILE* f;
    eLibro* libroAux;
    int retorno = -1;
    int i, len, id, precio,idEditorial;
    char titulo[100];
    char autor[100];
    char editorial[100];

    f = fopen(path, "w");
    if(f != NULL && ll_len(pArrayListLibro) > 0)
    {
        len = ll_len(pArrayListLibro);
        fprintf(f, "id,titulo,autor,precio,editorial\n");
        for(i=0; i<len; i++)
        {
            libroAux = (eLibro*)ll_get(pArrayListLibro, i);
            libro_getId(libroAux, &id);
            libro_getTitulo(libroAux, titulo);
            libro_getAutor(libroAux, autor);
            libro_getPrecio(libroAux, &precio);
            libro_getIdEditorial(libroAux, &idEditorial);
            libro_buscarEditorial(idEditorial, editorial);

            fprintf(f,"%d,%s,%s,%d,%s\n", id, titulo, autor, precio, editorial);
        }
        printf("\n--Archivo guardado--\n");
        system("pause");
        retorno = 0;
    }
    else
    {
        printf("\n--No se pudo guardar el archivo--\n");
        system("pause");
    }
    fclose(f);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListLibro)
{
    int i;
    int retorno = -1;
    int len;
    FILE* f;
    eLibro* libro;
    f = fopen(path, "wb");

    if(f != NULL && ll_len(pArrayListLibro))
    {
        len = ll_len(pArrayListLibro);
        for(i = 0; i < len; i++)
        {
            libro = ll_get(pArrayListLibro, i);
            fwrite(libro, sizeof(eLibro), 1, f);
        }
        printf("\n--Archivo binario guardado con exito--\n");
        system("pause");
        retorno = 1;
    }
    else
    {
        printf("\n--No se pudo guardar el archivo--\n");
        system("pause");
    }
    fclose(f);
    return retorno;
}

int controller_applyDis(LinkedList* pArrayListLibro)
{
	int retorno = -1;

	if(pArrayListLibro != NULL)
	{
		void (*pFunc)(void* element);
		pFunc = libro_aplicarDescuento;
		if(ll_map(pArrayListLibro, pFunc) == 0)
		{
			printf("\n--Descuento aplicado correctamente--\n");
			retorno = 0;
		}
		else
		{
			printf("\n--No se pudo aplicar el descuento--\n");
		}
		system("pause");
	}
	return retorno;
}

int controller_contarPorPrecio(LinkedList* pArrayListLibro)
{
	int retorno = -1;
	int len;
	int cantidad;
	len = ll_len(pArrayListLibro);

	if(pArrayListLibro != NULL && len > 0)
	{
		cantidad = ll_count(pArrayListLibro, libro_countPrecio);
		if(cantidad>0){
			printf("+----------------------------------------------+----+\n");
			printf("| Cantidad de Libros con Precio mayor a $500 | %d |\n", cantidad);
			printf("+----------------------------------------------+----+\n");
		}
	}
	return retorno;
}
/*
int controller_contarPorEditorial(LinkedList* pArrayListLibro)
{
	int retorno = -1;
	int len;
	int cantidad[5];
	len = ll_len(pArrayListLibro);

	if(pArrayListLibro != NULL && len > 0)
	{
		cantidad = ll_count(pArrayListLibro, libro_countPrecio);
		if(cantidad>0){
			printf("+----------------------------------------------+----+\n");
			printf("| Cantidad de Libros con Precio mayor a $500 | %d |\n", cantidad);
			printf("+----------------------------------------------+----+\n");
		}
	}
	return retorno;
}
*/
