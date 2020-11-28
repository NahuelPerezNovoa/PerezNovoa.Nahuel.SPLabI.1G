#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "Paises.h"
#include "Controller.h"
#include "Parser.h"


int main()
{
    int salida=0;
    int flagArchivo=0;
    int flagEstadisticas=0;
    char path[20];
    int opcion;
    LinkedList* listaPaises = ll_newLinkedList();//Creo el linkedList
    LinkedList* listaExitosos = ll_newLinkedList();
    LinkedList* listaEnElHorno = ll_newLinkedList();
    srand (time(NULL));



    do
    {
        printf("MENU\n\n");
        printf("1.Cargar Archivo\n");
        printf("2.Imprimir lista\n");
        printf("3.Asignar estadisticas\n");
        printf("4.Filtrar por paises exitosos\n");
        printf("5.Filtrar por paises en el horno\n");
        printf("6.Ordenar por nivel de infeccion\n");
        printf("7.Mostrar mas Castigado\n");
        printf("8.Salir\n\n");
        printf("Ingrese opcion: ");

        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1://CARGA ARCHIVO
            printf("Ingrese el nombre del archivo: ");
            fflush(stdin);
            gets(path);
            if(!controller_loadFromText(path,listaPaises))
            {
                printf("Carga exitosa\n");
                flagArchivo=1;
            }
            else
            {
                printf("No se pudo cargar el archivo\n");
            }
            break;
        case 2: //IMPRIME LISTA
            if(flagArchivo)
            {
                controller_ListPaises(listaPaises);
            }
            else
            {
                printf("Aún no se cargó el archivo\n");
            }
            break;
        case 3: //ASIGNAR ESTADISTICAS
            if(flagArchivo)
            {
                listaPaises = ll_map(listaPaises,asignarCriterios);
                if(listaPaises)
                {
                    printf("Estadisticas asignadas\n\n");
                    controller_ListPaises(listaPaises);
                    controller_saveAsText("PaisesConEstadisticas.csv",listaPaises);
                    flagEstadisticas=1;
                }
                else
                {
                    printf("Error al asignar estadisticas\n");
                }
            }
            else
            {
                printf("Aún no se cargó el archivo\n");
            }

            break;
        case 4://FILTRAR PAISES EXITOSOS
            if(flagArchivo && flagEstadisticas)
            {
                listaExitosos = ll_filter(listaPaises,filtrarExitoso);
                if(listaExitosos)
                {
                    printf("Lista de paises exitosos creada con exito\n\n");
                    controller_ListPaises(listaExitosos);
                    controller_saveAsText("PaisesExitosos.csv",listaExitosos);

                }
            }
            else
            {
                printf("Falta cargar el archivo, o asignar las estadisticas\n");
            }
            break;
        case 5://FILTRAR PAISES EN EL HORNO
            if(flagArchivo && flagEstadisticas)
            {
                listaEnElHorno = ll_filter(listaPaises,filtrarEnElHorno);
                if(listaEnElHorno)
                {
                    printf("Lista de paises en el horno creada con exito\n\n");
                    controller_ListPaises(listaEnElHorno);
                    controller_saveAsText("PaisesEnElHorno.csv",listaEnElHorno);

                }
            }
            else
            {
                printf("Falta cargar el archivo, o asignar las estadisticas\n");
            }
            break;
        case 6://ORDENAR POR NIVEL DE INFECCION
            if(flagArchivo && flagEstadisticas)
            {
                if(!ll_sort(listaPaises,ordenInfectados,1))
                {
                    printf("Ordenamiento exitoso\n");
                    controller_ListPaises(listaPaises);
                    controller_saveAsText("PaisesConEstadisticasOrdenado.csv",listaPaises);

                }
                else
                {
                    printf("Error al ordenar\n");
                }
            }
            else
            {
                printf("Falta cargar el archivo, o asignar las estadisticas\n");
            }

            break;
        case 7://MOSTRAR MAS CASTIGADO
            if(flagArchivo && flagEstadisticas)
            {
                mostrarPaisP((ePais*)findMasCastigado(listaPaises));
            }
            else
            {
                printf("Falta cargar el archivo, o asignar las estadisticas\n");
            }
            break;
        case 8://SALIDA
            printf("Adios\n\n");
            salida=1;
            break;
        default:
            printf("Opcion Invalida");


        }

        system ("pause");
        system ("cls");
    }
    while(salida==0);






    return 0;
}
