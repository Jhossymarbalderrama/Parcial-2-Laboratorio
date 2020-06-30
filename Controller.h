#include "LinkedList.h"

int controller_loadFromText(char* path, LinkedList* pArrayListVuelos);
int controller_ListVuelos(LinkedList* pArrayListVuelos,LinkedList* pArrayListPilotos);

int controller_ListPilotos(LinkedList* pArrayListPilotos);
int controller_saveAsText(char* path, LinkedList* pArrayList);
