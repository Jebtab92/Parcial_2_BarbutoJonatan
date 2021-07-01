/*
 ============================================================================
 Name        : 2doParcial_BarbutoJonatan.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Libro.h"
#include "Biblioteca.h"

int main(void)
{
	setbuf(stdout, NULL);
	int menu;
	int contadorID = 0;
	int flagDesc = 0;
	char ruta[50];
	LinkedList* listaLibros = ll_newLinkedList();
	eEditorial editoriales[6];

	completarEditoriales(editoriales, 6);

	do
	{
		system("cls");
		switch(menu = Get_IntRange("------------------------------Menu Principal----------------------------------- \n\n"
				  "1) Cargar los datos de los libros desde un archivo (Archivo sugerido Datos.csv)\n"
				  "2) Ordenar libros \n"
				  "3) Imprimir por pantalla \n"
				  "4) Aplicar descuentos \n"
				  "5) Guardar los datos de los libros en un archivo\n"
				  "6) Mostrar libros mayores a $500\n"
				  "7) Eliminar libro\n"
				  "8) Editar libro\n"
				  "9) Salir\n"
				  "--------------------------------------------------------------------------------\n\n"
				  "Opcion: ", "\nError, reingrese: ", 1, 9, 3))
		{
			case 1:
			{
				Get_String("\nPor favor ingrese nombre del archivo: ", "\Error, reingrese: ", ruta, 50, 3);
				controller_loadFromText(ruta, listaLibros, &contadorID);
				break;
			}
			case 2:
			{
				controller_sortLibro(listaLibros);
				break;
			}
			case 3:
			{
				controller_ListLibro(listaLibros);
				break;
			}
			case 4:
			{
				if(flagDesc == 0)
				{
					controller_applyDis(listaLibros);
				}
				else
				{
					printf("\nDescuento ya aplicado");
					system("pause");
				}
				break;
			}
			case 5:
			{
				controller_saveAsText("Mapeado.csv", listaLibros);
				break;
			}
			case 6:
			{
				controller_contarPorPrecio(listaLibros);
				break;
			}
			case 7:
			{
				controller_removeLibro(listaLibros);
				break;
			}
			case 8:
			{
				controller_editLibro(listaLibros, editoriales, 6);
				break;
			}
			case 9:
			{
				break;
			}
		}
	}while(menu != 9);
	return 0;
}
