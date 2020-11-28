#ifndef PAISES_H_INCLUDED
#define PAISES_H_INCLUDED

struct ePais
{
    int id;
    char nombre[20];
    int recuperados;
    int infectados;
    int muertos;
}typedef ePais;


#endif // PAISES_H_INCLUDED



int mostrarPaisP(ePais* pais);
void* asignarCriterios(void* pais);
int filtrarExitoso(void* pais);
int filtrarEnElHorno(void* pais);
int ordenInfectados(void* pais1, void* pais2);
ePais* pais_new();
ePais* pais_newParametros(char* idStr,char* modeloStr,char* valorStr,char* anioStr,char* puertasStr);

