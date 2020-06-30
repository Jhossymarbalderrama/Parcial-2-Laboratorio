#include "LinkedList.h"

#ifndef CONTROLLER_BALDERRAMA_H_INCLUDED
#define CONTROLLER_BALDERRAMA_H_INCLUDED



#endif // CONTROLLER_BALDERRAMA_H_INCLUDED

int controller_Balderrama_loadFromText(char* path, LinkedList* pArrayListVuelos);
int controller_Balderrama_ListVuelos(LinkedList* pArrayListVuelos,LinkedList* pArrayListPilotos);

int controller_Balderrama_ListPilotos(LinkedList* pArrayListPilotos);
int controller_Balderrama_saveAsText(char* path, LinkedList* pArrayList);


int controller_Balderrama_loadFromText_Pilotos(char* path, LinkedList* pArrayListPilotos);
int controller_Balderrama_ListVuelosPortugal(LinkedList* pArrayListVuelos,LinkedList* pArrayListPilotos);
