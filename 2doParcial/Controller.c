#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "Paises.h"
#include "Controller.h"
#include "Parser.h"

/** \brief Carga los datos de los autos desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPaises LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListPaises)
{
    int error=1;
    FILE* f;//declaro puntero a archivo

    if(path!=NULL && pArrayListPaises!=NULL)//verifico punteros
    {
        f=fopen(path,"r");//abro archivo de texto en modo lectura
        if(f!=NULL)//verifico puntero
        {
            if(!parser_PaisesFromText(f,pArrayListPaises))//parseo el archivo a la lista de empleados
            {
                error=0;
            }
            fclose(f);//cierro el archivo
        }
    }

    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListPaises)
{
    FILE* f;
    ePais* auxPais;
    int error=0;
    int len;
    int id;
    char nombre[20];
    int recuperados;
    int infectados;
    int muertos;
    int flag=0;

    if(path!=NULL && pArrayListPaises!=NULL)//verifico punteros
    {
        len=ll_len(pArrayListPaises);//guardo el tamaño de la lista
        f=fopen(path,"w");//abro el archivo en modo escritura
        if(f!=NULL )//verifico puntero
        {
            for(int i=0; i<len; i++)//recorro la lista de empleados
            {
                auxPais=(ePais*)ll_get(pArrayListPaises,i);//tomo el empleado de la lista en el indice i
                id = auxPais->id;//tomo los datos del empleado en el indice i
                strcpy(nombre,auxPais->nombre);
                recuperados = auxPais->recuperados;
                infectados = auxPais->infectados;
                muertos = auxPais->muertos;
                if(!flag)
                {
                    fprintf(f,"id,nombre,recuperados,infectados,muertos");
                    flag=1;
                }
                else
                {
                    fprintf(f,"%d,%s,%d,%d,%d\n",id,nombre,recuperados,infectados,muertos);//escribo el empleado en el archivo
                }
            }
            fclose(f);//cierro el archivo
            error=1;

        }
    }
    return error;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListPaises(LinkedList* pArrayListPaises)
{
    int error=0;
    int tam;
    int flag=0;
    ePais* auxPais;

    if(pArrayListPaises!=NULL)//verifico puntero
    {
        error=1;
        printf("Id            Nombre         Recuperados  Infectados  Muertos\n");//imprimo encabezado
        printf("-------------------------------------------------------------\n");
        tam = ll_len(pArrayListPaises);
        for(int i=1; i<tam; i++)//recorro la lista salteando el encabezado del archivo
        {
            auxPais = (ePais*)ll_get(pArrayListPaises,i);//tomo el empleado de la lista en el indice i
            if(auxPais != NULL)//verifico puntero
            {
                mostrarPaisP(auxPais);
                printf("\n");//muestro dicho empleado
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("No hay paises\n\n");//informo que no hay empleados
        }
        printf("\n\n");
    }
    return error;
}

void* findMasCastigado(LinkedList* pArrayListPaises)
{
    int masCastigado;
    int flag=0;
    int len = ll_len(pArrayListPaises);
    ePais* auxPais;
    ePais* auxPais2;
    if(pArrayListPaises!=NULL)
    {
        for(int i=0; i<len; i++)
        {
            auxPais = (ePais*)ll_get(pArrayListPaises,i);
            if(!flag)
            {
                masCastigado = auxPais->muertos;
                auxPais2 = auxPais;
            }
            else
            {
                if(auxPais->muertos > masCastigado)
                {
                    masCastigado = auxPais->muertos;
                    auxPais2 = auxPais;
                }
            }
        }
    }
    return auxPais2;
}
