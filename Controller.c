#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#include "Controller.h"
#include "LinkedList.h"
#include "vuelos.h"
#include "Pilotos.h"


/** \brief
 *
 * \param path char*
 * \param pArrayListVuelos LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListVuelos)
{
    int todoOk = 0;
    FILE* f;
    char buffer[10][100];
    int cant;

    eVuelos* aux = NULL;

    if(path != NULL && pArrayListVuelos != NULL)
    {
        f = fopen(path, "r");

        if( f == NULL)
        {
            printf("No se pudo abrir el archivo\n");
            return todoOk;
        }
        fscanf(f,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2],buffer[3],buffer[4],buffer[5],buffer[6],buffer[7]);
        while(!feof(f))
        {
            cant = fscanf(f,"%[^,],%[^,],%[^,],   %[^/]/%[^/]/%[^,]   ,%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2],buffer[3],buffer[4],buffer[5],buffer[6],buffer[7],buffer[8],buffer[9]);
            if( cant == 10)
            {
                aux = vuelo_NewParametros(buffer[0], buffer[1], buffer[2],   buffer[3],buffer[4],buffer[5]   ,buffer[6],buffer[7],buffer[8],buffer[9]);
                if( aux != NULL)
                {
                    ll_add(pArrayListVuelos,aux);
                }
            }
            else
            {
                break;
            }
        }

        todoOk = 1;
    }

    return todoOk;
}

/** \brief  Lista los Vuelos
 *
 * \param pArrayListVuelos LinkedList*
 * \param pArrayListPilotos LinkedList*
 * \return int
 *
 */
int controller_ListVuelos(LinkedList* pArrayListVuelos,LinkedList* pArrayListPilotos)
{
    int todoOk = 0;
    eVuelos* aux;
    int flag = 0;
    if(pArrayListVuelos != NULL)
    {
        printf("\n[  idVuelo       idAvion            Piloto             Fecha            Destino       cantPasajeros       HraDespegue      HraLlegada ]\n\n");
        for( int i=0; i < ll_len(pArrayListVuelos); i++)
        {
            aux = (eVuelos*) ll_get(pArrayListVuelos,i);
            mostrarVuelo(aux,pArrayListPilotos);
            flag = 1;
        }
        if(flag == 0)
        {
            printf("No hay Vuelos cargados para mostrar\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

/** \brief Lista los Pilotos
 *
 * \param pArrayListPilotos LinkedList*
 * \return int
 *
 */
int controller_ListPilotos(LinkedList* pArrayListPilotos){
    int todoOk = 0;
    ePiloto* aux;
    int flag = 0;
    if(pArrayListPilotos != NULL)
    {
        printf("\n[   ID       Nombre_Piloto ]\n\n");
        for( int i=0; i < ll_len(pArrayListPilotos); i++)
        {
            aux = (ePiloto*) ll_get(pArrayListPilotos,i);
            mostrarPiloto(aux);
            flag = 1;
        }
        if(flag == 0)
        {
            printf("No hay Vuelos cargados para mostrar\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

/** \brief Guarda la Lista de Vuelos en CSV
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayList)
{

    int todoOk = 0;
    int cant;
    FILE* f;
    eVuelos* aux = NULL;

    if(pArrayList!= NULL && path != NULL )
    {

        f = fopen(path,"w");
        if(f == NULL)
        {
            return todoOk;
        }
        fprintf(f,"idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada\n");
        for(int i = 0; i < ll_len(pArrayList); i++)
        {
            aux = ll_get(pArrayList,i);
            cant = fprintf(f,"%d,%d,%d,%d/%d/%d,%s,%d,%d,%d\n",aux->idVuelo,aux->idAvion,aux->idPiloto,aux->fecha.dia,aux->fecha.mes,aux->fecha.anio,aux->destino,aux->cantPasajeros,aux->horaDespegue,aux->horaLlegada);
            if(cant < 1)
            {
                return todoOk;
            }
        }
        fclose(f);
        todoOk = 1;
    }
    return todoOk;
}

