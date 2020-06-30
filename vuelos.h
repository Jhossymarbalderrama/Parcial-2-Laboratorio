#include "LinkedList.h"
//#include "Controller.h"
#include "Controller_Balderrama.h"

#ifndef VUELOS_H_INCLUDED
#define VUELOS_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int idVuelo;
    int idAvion;
    int idPiloto;

    eFecha fecha;

    char destino[128];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
}eVuelos;

#endif // VUELOS_H_INCLUDED


int mostrarVuelo(eVuelos* e,LinkedList* pArrayListPilotos);
eVuelos* vuelo_new();
eVuelos* vuelo_NewParametros(char* idVuelo,char* idAvion,char* idPiloto,   char* dia,char* mes,char* anio  ,char* destino,char* cantPasajeros,char* horaDespegue,char* horaLlegada);

/**         SETERS              */
int vuelo_setIdVuelo(eVuelos* this,int idVuelo);
int vuelo_setIdAvion(eVuelos* this,int idAvion);
int vuelo_setIdPiloto(eVuelos* this,int idPiloto);
int vuelo_setIdFecha(eVuelos* this,int dia,int mes,int anio);
int vuelo_setDestino(eVuelos* this,char* destino);
int vuelo_setCantPasajeros(eVuelos* this,int cantPasajeros);
int vuelo_setHoraDespegue(eVuelos* this,int hraDespegue);
int vuelo_setHoraLlegada(eVuelos* this,int hraLlegada);

/**         GETERS              */
int vuelo_get_idVuelo(eVuelos* this,int* id_Vuelo);
int vuelo_get_idAvion(eVuelos* this,int* id_Avion);
int vuelo_get_idPiloto(eVuelos* this,int* id_Piloto);
int vuelo_get_fecha(eVuelos* this,int* f_dia,int* f_mes,int* f_anio);
int vuelo_get_destino(eVuelos* this,char* destino);
int vuelo_get_cantPasajeros(eVuelos* this,int* cant_Pasajeros);
int vuelo_get_hraDespegue(eVuelos* this,int* hora_Despegue);
int vuelo_get_hraLlegada(eVuelos* this,int* hora_Llegada);

int get_Nombre_Piloto_byID(char* nombre_Piloto,LinkedList* listaPiloto,int id_Piloto);

int condicion_Cantidad(void* elemento);
int cant_Pasajeros_all(LinkedList* listaVuelos);

int condicion_Cantidad_Irlanda(void* elemento);
int cant_pasajeros_Irlanda(LinkedList* listaVuelos);


int archivos_Filtro_by_Duracion_3hs(LinkedList* listaVuelos);
int filtroDuracion(void* elemento);

int archivos_Filtro_Vuelos_to_Portugal(LinkedList* listaVuelos);
int filtro_Portugal(void* elemento);

int archivos_Filtro_by_Chofer(LinkedList* listaVuelos);
int filtro_chofer(void* elemento);
