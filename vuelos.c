#include <stdio.h>
#include <stdlib.h>
#include "vuelos.h"
#include "string.h"
#include "Pilotos.h"


/** \brief
 *
 * \param e eVuelos*
 * \param pArrayListPilotos LinkedList*
 * \return int
 *
 */
int mostrarVuelo(eVuelos* e,LinkedList* pArrayListPilotos)
{
    int todoOk = 0;

    int id_Vuelo;
    int id_Avion;
    int id_Piloto;

    int f_dia;
    int f_mes;
    int f_anio;

    char destino[128];
    int cant_Pasajeros;
    int hora_Despegue;
    int hora_Llegada;

    char nombre_Piloto[41];

    vuelo_get_idVuelo(e,&id_Vuelo);
    vuelo_get_idAvion(e,&id_Avion);
    vuelo_get_idPiloto(e,&id_Piloto);
    vuelo_get_fecha(e,&f_dia,&f_mes,&f_anio);
    vuelo_get_destino(e,destino);
    vuelo_get_cantPasajeros(e,&cant_Pasajeros);
    vuelo_get_hraDespegue(e,&hora_Despegue);
    vuelo_get_hraLlegada(e,&hora_Llegada);

    get_Nombre_Piloto_byID(nombre_Piloto,pArrayListPilotos,id_Piloto);

    if( e != NULL)
    {
        //printf("    %3d          %4d           %4d         [%2d/%2d/%4d]     %10s            %3d                 %2d                %2d\n",id_Vuelo,id_Avion,id_Piloto,f_dia,f_mes,f_anio,destino,cant_Pasajeros,hora_Despegue,hora_Llegada);
        printf("    %3d          %4d      %16s         [%2d/%2d/%4d]     %10s            %3d                 %2d                %2d\n",id_Vuelo,id_Avion,nombre_Piloto,f_dia,f_mes,f_anio,destino,cant_Pasajeros,hora_Despegue,hora_Llegada);
        todoOk = 1;
    }
    return todoOk;
}

/** \brief
 *
 * \return eVuelos*
 *
 */
eVuelos* vuelo_new()
{
    eVuelos* nuevo = (eVuelos*) malloc( sizeof(eVuelos));
    if(nuevo != NULL)
    {
        nuevo->idVuelo = 0;
        nuevo->idAvion = 0;
        nuevo->idPiloto = 0;

        nuevo->fecha.dia = 0;
        nuevo->fecha.mes = 0;
        nuevo->fecha.anio = 0;

        strcpy(nuevo->destino," ");
        nuevo->cantPasajeros = 0;
        nuevo->horaDespegue = 0;
        nuevo->horaLlegada = 0;
    }
    return nuevo;
}


/** \brief
 *
 * \param idVuelo char*
 * \param idAvion char*
 * \param idPiloto char*
 * \param dia char*
 * \param mes char*
 * \param anio char*
 * \param destino char*
 * \param cantPasajeros char*
 * \param horaDespegue char*
 * \param horaLlegada char*
 * \return eVuelos*
 *
 */
eVuelos* vuelo_NewParametros(char* idVuelo,char* idAvion,char* idPiloto,   char* dia,char* mes,char* anio  ,char* destino,char* cantPasajeros,char* horaDespegue,char* horaLlegada)
{
    eVuelos* nuevo = vuelo_new();
    int id_Vuelo;
    int id_Avion;
    int id_Piloto;

    int f_dia;
    int f_mes;
    int f_anio;

    int cant_Pasajeros;
    int hora_Despegue;
    int hora_Llegada;

    id_Vuelo = atoi(idVuelo);
    id_Avion = atoi(idAvion);
    id_Piloto = atoi(idPiloto);

    f_dia = atoi(dia);
    f_mes = atoi(mes);
    f_anio = atoi(anio);

    cant_Pasajeros = atoi(cantPasajeros);
    hora_Despegue = atoi(horaDespegue);
    hora_Llegada = atoi(horaLlegada);

    if( nuevo != NULL)
    {
        if(vuelo_setIdVuelo(nuevo,id_Vuelo) &&
           vuelo_setIdAvion(nuevo,id_Avion) &&
           vuelo_setIdPiloto(nuevo,id_Piloto) &&
           vuelo_setIdFecha(nuevo,f_dia,f_mes,f_anio) &&
           vuelo_setDestino(nuevo,destino)&&
           vuelo_setCantPasajeros(nuevo,cant_Pasajeros) &&
           vuelo_setHoraDespegue(nuevo,hora_Despegue) &&
           vuelo_setHoraLlegada(nuevo,hora_Llegada))
        {
            // printf("Empleado creado correctamente\n");
        }
        else
        {
            nuevo = NULL;
        }
    }

    return nuevo;
}


/**                       SETERS                        */

/** \brief
 *
 * \param this eVuelos*
 * \param idVuelo int
 * \return int
 *
 */
int vuelo_setIdVuelo(eVuelos* this,int idVuelo){
    int todoOk = 0;
    if(this != NULL && idVuelo >= 0)
    {
        this->idVuelo = idVuelo;
        todoOk = 1;
    }
    return todoOk;
}

/** \brief
 *
 * \param this eVuelos*
 * \param idAvion int
 * \return int
 *
 */
int vuelo_setIdAvion(eVuelos* this,int idAvion){
    int todoOk = 0;
    if(this != NULL && idAvion >= 0)
    {
        this->idAvion = idAvion;
        todoOk = 1;
    }
    return todoOk;
}

/** \brief
 *
 * \param this eVuelos*
 * \param idPiloto int
 * \return int
 *
 */
int vuelo_setIdPiloto(eVuelos* this,int idPiloto){
    int todoOk = 0;
    if(this != NULL && idPiloto >= 0)
    {
        this->idPiloto = idPiloto;
        todoOk = 1;
    }
    return todoOk;
}

/** \brief
 *
 * \param this eVuelos*
 * \param dia int
 * \param mes int
 * \param anio int
 * \return int
 *
 */
int vuelo_setIdFecha(eVuelos* this,int dia,int mes,int anio){
    int todoOk = 0;
    eFecha aux ;
    if(this != NULL && dia >= 0 && dia <= 31 && mes >= 0 && mes<=12 && anio > 2000)
    {
        aux.dia = dia;
        aux.mes = mes;
        aux.anio = anio;

        this->fecha = aux;

        todoOk = 1;
    }
    return todoOk;
}


/** \brief
 *
 * \param this eVuelos*
 * \param destino char*
 * \return int
 *
 */
int vuelo_setDestino(eVuelos* this,char* destino){
    int todoOk = 0;
    if(this != NULL && destino != NULL && strlen(destino) < 128)
    {
        strcpy(this->destino, destino);
        todoOk = 1;
    }
    return todoOk;
}

/** \brief
 *
 * \param this eVuelos*
 * \param cantPasajeros int
 * \return int
 *
 */
int vuelo_setCantPasajeros(eVuelos* this,int cantPasajeros){
    int todoOk = 0;
    if(this != NULL && cantPasajeros >= 0)
    {
        this->cantPasajeros = cantPasajeros;
        todoOk = 1;
    }
    return todoOk;
}

/** \brief
 *
 * \param this eVuelos*
 * \param hraDespegue int
 * \return int
 *
 */
int vuelo_setHoraDespegue(eVuelos* this,int hraDespegue){
    int todoOk = 0;
    if(this != NULL && hraDespegue >= 0 && hraDespegue <= 24)
    {
        this->horaDespegue = hraDespegue;
        todoOk = 1;
    }
    return todoOk;
}

/** \brief
 *
 * \param this eVuelos*
 * \param hraLlegada int
 * \return int
 *
 */
int vuelo_setHoraLlegada(eVuelos* this,int hraLlegada){
    int todoOk = 0;
    if(this != NULL && hraLlegada >= 0 && hraLlegada <= 24)
    {
        this->horaLlegada = hraLlegada;
        todoOk = 1;
    }
    return todoOk;
}

/**                       GETERS                        */

/** \brief
 *
 * \param this eVuelos*
 * \param id_Vuelo int*
 * \return int
 *
 */
int vuelo_get_idVuelo(eVuelos* this,int* id_Vuelo){
    int todoOk = 0;

    if( this != NULL && id_Vuelo != NULL)
    {
        *id_Vuelo = this->idVuelo;
        todoOk = 1;
    }
    return todoOk;
}

/** \brief
 *
 * \param this eVuelos*
 * \param id_Avion int*
 * \return int
 *
 */
int vuelo_get_idAvion(eVuelos* this,int* id_Avion){
    int todoOk = 0;

    if( this != NULL && id_Avion != NULL)
    {
        *id_Avion = this->idAvion;
        todoOk = 1;
    }
    return todoOk;
}

/** \brief
 *
 * \param this eVuelos*
 * \param id_Piloto int*
 * \return int
 *
 */
int vuelo_get_idPiloto(eVuelos* this,int* id_Piloto){
    int todoOk = 0;

    if( this != NULL && id_Piloto != NULL)
    {
        *id_Piloto = this->idPiloto;
        todoOk = 1;
    }
    return todoOk;
}

/** \brief
 *
 * \param this eVuelos*
 * \param f_dia int*
 * \param f_mes int*
 * \param f_anio int*
 * \return int
 *
 */
int vuelo_get_fecha(eVuelos* this,int* f_dia,int* f_mes,int* f_anio){
    int todoOk = 0;
   // eFecha aux;

    if( this != NULL && f_dia != NULL && f_mes != NULL && f_anio != NULL)
    {
        *f_dia = this->fecha.dia;
        *f_mes = this->fecha.mes;
        *f_anio = this->fecha.anio;
        todoOk = 1;
    }
    return todoOk;
}

/** \brief
 *
 * \param this eVuelos*
 * \param destino char*
 * \return int
 *
 */
int vuelo_get_destino(eVuelos* this,char* destino){
    int todoOk = 0;

    if( this != NULL && destino != NULL)
    {
        strcpy(destino, this->destino);
        todoOk = 1;
    }
    return todoOk;
}

/** \brief
 *
 * \param this eVuelos*
 * \param cant_Pasajeros int*
 * \return int
 *
 */
int vuelo_get_cantPasajeros(eVuelos* this,int* cant_Pasajeros){
    int todoOk = 0;

    if( this != NULL && cant_Pasajeros != NULL)
    {
        *cant_Pasajeros = this->cantPasajeros;
        todoOk = 1;
    }
    return todoOk;
}

/** \brief
 *
 * \param this eVuelos*
 * \param hora_Despegue int*
 * \return int
 *
 */
int vuelo_get_hraDespegue(eVuelos* this,int* hora_Despegue){
    int todoOk = 0;

    if( this != NULL && hora_Despegue != NULL)
    {
        *hora_Despegue = this->horaDespegue;
        todoOk = 1;
    }
    return todoOk;
}

/** \brief
 *
 * \param this eVuelos*
 * \param hora_Llegada int*
 * \return int
 *
 */
int vuelo_get_hraLlegada(eVuelos* this,int* hora_Llegada){
    int todoOk = 0;

    if( this != NULL && hora_Llegada != NULL)
    {
        *hora_Llegada = this->horaLlegada;
        todoOk = 1;
    }
    return todoOk;
}

/** \brief
 *
 * \param nombre_Piloto char*
 * \param listaPiloto LinkedList*
 * \param id_Piloto int
 * \return int
 *
 */
int get_Nombre_Piloto_byID(char* nombre_Piloto,LinkedList* listaPiloto,int id_Piloto){
    int allOk = -1;
    ePiloto* aux = NULL;

    if(listaPiloto != NULL){
        for(int i = 0 ; i < ll_len(listaPiloto);i++){
            aux = ll_get(listaPiloto,i);
            if(aux->idPiloto == id_Piloto){
                strcpy(nombre_Piloto,aux->nombrePiloto);
                allOk = 0;
                break;
            }
        }
    }

    return allOk;
}

/** \brief
 *
 * \param elemento void*
 * \return int
 *
 */
int condicion_Cantidad(void* elemento){
    int retorno = 0;
    eVuelos* aux;
    aux = (eVuelos*) elemento;

    if(aux->idVuelo != 0){
        retorno = aux->cantPasajeros;
    }

    return retorno;
}

/** \brief
 *
 * \param listaVuelos LinkedList*
 * \return int
 *
 */
int cant_Pasajeros_all(LinkedList* listaVuelos){

    /**Con la funcion COUNT*/
    int retorno;


    retorno = ll_count(listaVuelos,condicion_Cantidad);

    return retorno;



    /**Sin La funcion COUNT*/
    /*
    int acumulador = 0;
    eVuelos* auxiliar;

    if(listaVuelos != NULL){
        for(int i = 0; i <ll_len(listaVuelos);i++){
            auxiliar = ll_get(listaVuelos,i);
            acumulador = acumulador + auxiliar->cantPasajeros;
        }
    }

    return acumulador;
    */
}

/** \brief
 *
 * \param elemento void*
 * \return int
 *
 */
int condicion_Cantidad_Irlanda(void* elemento){
    int retorno = 0;
    eVuelos* aux;
    aux = (eVuelos*) elemento;

    if(strcmp(aux->destino,"Irlanda") == 0){
        retorno = aux->cantPasajeros;
    }

    return retorno;
}

/** \brief
 *
 * \param listaVuelos LinkedList*
 * \return int
 *
 */
int cant_pasajeros_Irlanda(LinkedList* listaVuelos){

    int retorno;


    retorno = ll_count(listaVuelos,condicion_Cantidad_Irlanda);

    return retorno;


/*
    int acumulador = 0;
    eVuelos* auxiliar;

    if(listaVuelos != NULL){
        for(int i = 0; i <ll_len(listaVuelos);i++){
            auxiliar = ll_get(listaVuelos,i);
            if(strcmp(auxiliar->destino,"Irlanda") == 0){
                acumulador = acumulador + auxiliar->cantPasajeros;
            }
        }
    }

    return acumulador;
*/
}

/**Filtrar vuelos cortos: Generar un archivo de iguales características que el original, con los datos de
los vuelos cuya duración sea inferior a 3 horas.*/

/** \brief
 *
 * \param elemento void*
 * \return int
 *
 */
int filtroDuracion(void* elemento){

    int todoOk = 0;
    eVuelos* aux;
    aux = (eVuelos*) elemento;
    int duracion = 3;
    int tiempo = aux->horaLlegada - aux->horaDespegue;

    if(tiempo < duracion && tiempo >= 0){
        todoOk = 1;
    }

    return todoOk;
}


/** \brief
 *
 * \param listaVuelos LinkedList*
 * \return int
 *
 */
int archivos_Filtro_by_Duracion_3hs(LinkedList* listaVuelos){

    int todoOk = 0;

    LinkedList* lista2 = ll_newLinkedList();

    lista2 = ll_filter(listaVuelos,filtroDuracion);

    if(controller_saveAsText("FiltroXduracion3hs.csv",lista2)){
        printf("\n[ - Filtro Vuelos de 3 horas - Archivo Creado. - ]\n");
        todoOk = 1;
    }

    return todoOk;
}

/** \brief
 *
 * \param elemento void*
 * \return int
 *
 */
int filtro_Portugal(void* elemento){

    int todoOk = 0;
    eVuelos* aux;
    aux = (eVuelos*) elemento;
    char lugar[128] = "Portugal";
    char destino[128];

    strcpy(destino,aux->destino);

    if(strcmp(destino,lugar) == 0){
        todoOk = 1;
    }

    return todoOk;
}

/** \brief
 *
 * \param listaVuelos LinkedList*
 * \return int
 *
 */
int archivos_Filtro_Vuelos_to_Portugal(LinkedList* listaVuelos){
    int todoOk = 0;

    LinkedList* lista2 = ll_newLinkedList();

    lista2 = ll_filter(listaVuelos,filtro_Portugal);

    if(controller_saveAsText("FiltroXvuelosPortugal.csv",lista2)){
        printf("\n[ - Se ha creado un Archivo con este Listado. - ]\n");
        todoOk = 1;
    }

    return todoOk;
}

/** \brief
 *
 * \param elemento void*
 * \return int
 *
 */
int filtro_chofer(void* elemento){
    int todoOk = 0;
    eVuelos* aux;
    aux = (eVuelos*) elemento;
    int chofer = 1;

    if(chofer != aux->idPiloto){
        todoOk = 1;
    }

    return todoOk;
}

/** \brief
 *
 * \param listaVuelos LinkedList*
 * \return int
 *
 */
int archivos_Filtro_by_Chofer(LinkedList* listaVuelos){
    int todoOk = 0;

    LinkedList* lista2 = ll_newLinkedList();

    lista2 = ll_filter(listaVuelos,filtro_chofer);

    if(controller_saveAsText("ListadoSinAlexLifeson.csv",lista2)){
        printf("[ - Archivo Creado sin el Piloto Alex Lifeson. - ]\n");
        todoOk = 1;
    }

    return todoOk;
}


