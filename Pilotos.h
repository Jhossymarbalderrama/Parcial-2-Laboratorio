#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller_Balderrama.h"

#ifndef PILOTOS_H_INCLUDED
#define PILOTOS_H_INCLUDED

typedef struct{
    int idPiloto;
    char nombrePiloto[128];
    int isEmpty;
}ePiloto;

#endif // PILOTOS_H_INCLUDED

void hardCode(LinkedList* listaPilotos);
int mostrarPiloto(ePiloto* e);

int piloto_get_idPiloto(ePiloto* this,int* id_Piloto);
int piloto_get_nombre_Piloto(ePiloto* this,char* nombre_Piloto);
int piloto_get_isEmpty(ePiloto* this,int* isEmpty);

ePiloto* piloto_Balderrama_new();
ePiloto* piloto_Balderrama_NewParametros(char* idPiloto,char* nombrePiloto);
int piloto_balderrama_setIdPiloto(ePiloto* this,int idPiloto);
int piloto_balderrama_setNombrePiloto(ePiloto* this,char* nombrePiloto);

int filtrar_List_Piloto_By_Name(LinkedList* listaPilotos);


int listar_Pilotos_by_Nombre(LinkedList* listaPilotos,char* name);

int filtro_name_piloto(void* elemento,char* name);
