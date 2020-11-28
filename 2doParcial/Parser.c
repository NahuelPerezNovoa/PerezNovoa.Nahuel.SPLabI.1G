#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "Paises.h"
#include "Controller.h"
#include "Parser.h"

/** \brief Parsea los datos los datos de los autps desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListCars LinkedList*
 * \return int
 *
 */
int parser_PaisesFromText(FILE* pFile, LinkedList* pArrayListPaises)
{
    int error=1;
    char auxPais[5][120];//declaro array bidimensional para guardar cada campo de un auto
    int cant;
    ePais* newPais;

    if(pFile!=NULL && pArrayListPaises!=NULL)//verifico punteros
    {
        //fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n],\n",auxPais[0],auxPais[1],auxPais[2],auxPais[3],auxPais[4]);//leo y guardo cada campo de cada empleado que en el archivo esta separado por comas

        while(!feof(pFile))//itero hasta llegar al final del archivo
        {
            cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n],\n",auxPais[0],auxPais[1],auxPais[2],auxPais[3],auxPais[4]);//leo y guardo cada campo de cada empleado que en el archivo esta separado por comas
            if(cant==5)//verifico que se hayan escrito 4 campos
            {
                newPais=pais_newParametros(auxPais[0],auxPais[1],auxPais[2],auxPais[3],auxPais[4]);//creo un nuevo empleado y le asigno los datos previamente guardados
                if(newPais!=NULL)//verifico puntero
                {
                    ll_add(pArrayListPaises,newPais);//agrego el nuevo empleado a la lista de empelados
                    error=0;
                }
            }
            else
            {
                break;
            }
        }
    }

    return error;
}

