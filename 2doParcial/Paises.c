#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "Paises.h"
#include "Controller.h"
#include "Parser.h"

int mostrarPaisP(ePais* pais)
{
    int error = 0;
    if(pais!=NULL)
    {
        error=1;
        printf("%4d %20s %d k  %d k   %d k",pais->id,pais->nombre,pais->recuperados,pais->infectados,pais->muertos);
        //imprimo los campos de un pais pasado por referencia
    }
    return error;
}

void* asignarCriterios(void* pais)
{
    ePais* auxPais = (ePais*) pais;
    int aleatorio;

    if(auxPais!=NULL)
    {
        aleatorio = rand()%(50 + 1)+50; // esta linea va en la funcion que asigna el tiempo donde a es el maximo y b el minimo
        auxPais->recuperados = aleatorio;
        aleatorio = rand()%(1600 + 1)+400; // esta linea va en la funcion que asigna el tiempo donde a es el maximo y b el minimo
        auxPais->infectados = aleatorio;
        aleatorio = rand()%(49 + 1)+1; // esta linea va en la funcion que asigna el tiempo donde a es el maximo y b el minimo
        auxPais->muertos = aleatorio;

    }
    return pais;
}

int filtrarExitoso(void* pais)
{
    int rta = 0;
    ePais* auxPais = pais;
    if(auxPais!=NULL)
    {
        if(auxPais->muertos<5)
        {
            rta = 1;
        }
    }
    return rta;
}

int filtrarEnElHorno(void* pais)
{
    int rta = 0;
    ePais* auxPais = pais;
    int recuperados = auxPais->recuperados;
    if(auxPais!=NULL)
    {
        if(auxPais->infectados>(recuperados*3))
        {
            rta = 1;
        }
    }
    return rta;
}

int ordenInfectados(void* pais1, void* pais2)
{
    int rta;
    ePais* auxPais1;//declaro puntero tipo ePais para pais1
    ePais* auxPais2;//declaro puntero tipo ePais para pais2

    if(pais1!=NULL && pais2!=NULL)//verifico punteros
    {
        auxPais1 = (ePais*) pais1;//casteo y asigno direcc de memoria al puntero
        auxPais2 = (ePais*) pais2;//casteo y asigno direcc de memoria al puntero
        if(auxPais1->infectados == auxPais2->infectados)
        {
            rta=0;
        }
        else if(auxPais1->infectados > auxPais2->infectados)
        {
            rta=-1;
        }
        else
        {
            rta=1;
        }
    }

    return rta;
}

ePais* pais_new()
{
    return (ePais*) malloc(sizeof(ePais));//retorno puntero a espacio para nuevo auto
}

ePais* pais_newParametros(char* idStr,char* nombre,char* recuperados,char* infectados,char* muertos)
{
    ePais* nuevoPais = pais_new();//pido espacio y direccion para nuevo auto
    if(nuevoPais!=NULL)//verifico puntero
    {
        nuevoPais->id=atoi(idStr);//escribo Id casteado a entero, en el nuevo auto
        strcpy(nuevoPais->nombre,nombre);//escribo modelo en el nuevo auto
        nuevoPais->recuperados=atoi(recuperados);//escribo valor casteado a flotante, en el nuevo auto
        nuevoPais->infectados=atoi(infectados);//escribo anio de fabricacion casteado a entero, en el nuevo auto
        nuevoPais->muertos=atoi(muertos);//escribo cant. de puertas casteado a entero, en el nuevo auto

    }

    return nuevoPais;//devuelvo el puntero a nuevo auto con los parametros cargados
}


