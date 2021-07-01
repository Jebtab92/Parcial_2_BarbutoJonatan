#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca.h"
#include "LinkedList.h"
#include "Libro.h"

/* \brief Parsea los datos de los libros desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int
 */
int parser_LibroFromText(FILE* pFile, LinkedList* pArrayListLibro, int* lastID)
{

    int retorno = 0;
    eLibro* pElement;
    char id[100];
    char titulo[100];
    char autor[100];
    char precio[100];
    char editorial[100];
    int idEditorial;
    int auxLastId = -1;

    if(pFile != NULL && pArrayListLibro != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, id, id, id, id);

        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, autor, precio, editorial);

				if(strcmp(editorial,"Planeta") == 0)
				{
					idEditorial = 1;
				}
				if(strcmp(editorial, "SIGLO XXI EDITORES") == 0)
				{
					idEditorial = 2;
				}
				if(strcmp(editorial, "Pearson") == 0)
				{
					idEditorial = 3;
				}
				if(strcmp(editorial, "Minotauro") == 0)
				{
					idEditorial = 4;
				}
				if(strcmp(editorial, "SALAMANDRA") == 0)
				{
					idEditorial = 5;
				}
				if(strcmp(editorial, "PENGUIN BOOKS") == 0)
				{
					idEditorial = 6;
				}

            pElement = libro_newParametros(id, titulo, autor, precio, idEditorial);

            if(pElement != NULL)
            {
                if(ll_add(pArrayListLibro, pElement) == 0)
                {
                	if(atoi(id) > auxLastId)
                	{
                		auxLastId = atoi(id);
                	}
                    retorno++;
                }
            }
        }
    }
    if(retorno > 0)
    {
    	*lastID = auxLastId;
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los libros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int
 *
 */
/*int parser_LibroFromBinary(FILE* pFile, LinkedList* pArrayListLibro)
{
	int retorno = 0;
    eLibro libro;
    eLibro* pLibro;
    char id[100];
    char precio[100];
    int aux;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            aux = fread(&libro, sizeof(eLibro), 1, pFile);
            if(aux == 1)
            {
                if(feof(pFile))
                {
                    break;
                }
                else
                {
                    sprintf(id,"%d",libro.id);
                    sprintf(precio,"%d",libro.precio);
                    pLibro = libro_newParametros(id, libro.titulo, libro.autor, precio);
                    ll_add(pArrayListLibro, pLibro);
                }
            }
        }
    }
    return retorno;
}*/
