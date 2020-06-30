#include "Pilotos.h"

/** \brief mostrar Piloto
 *
 * \param e ePiloto*
 * \return int
 *
 */
int mostrarPiloto(ePiloto* e){
    int todoOk = 0;

    int id_Piloto;
    char nombre_Piloto[41];
    int isEmpty;


    piloto_get_idPiloto(e,&id_Piloto);
    piloto_get_nombre_Piloto(e,nombre_Piloto);
    piloto_get_isEmpty(e,&isEmpty);


    if( e != NULL)
    {
        printf("    %2d      %14s \n",id_Piloto,nombre_Piloto);
        todoOk = 1;
    }
    return todoOk;

}

/** \brief hardCode  ePiloto
 *
 * \param listaPilotos LinkedList*
 * \return void
 *
 */
void hardCode(LinkedList* listaPilotos)
{
    ePiloto* Piloto;
    int idPilotos[5] = {1,2,3,4,5};
    char nombrePilotos[5][41] = {{"Alex Lifeson"},
                                {"Richard Bach"},
                                {"John Kerry"},
                                {"Erwin Rommel"},
                                {"Stephen Coonts"}};

    if(listaPilotos != NULL){
        for(int i = 0;i<5;i++){
            Piloto = (ePiloto*) malloc(sizeof(ePiloto));
            if(Piloto != NULL){
                Piloto->idPiloto = idPilotos[i];
                strcpy(Piloto->nombrePiloto,nombrePilotos[i]);
                Piloto->isEmpty = 0;
                if(ll_add(listaPilotos,Piloto) != 0){
                    printf("[ERROR. No se pudo Completar el Harcodeo de Pilotos]\n");
                }

            }
        }
    }

}

/** \brief piloto_get_idPiloto
 *
 * \param this ePiloto*
 * \param id_Piloto int*
 * \return int
 *
 */
int piloto_get_idPiloto(ePiloto* this,int* id_Piloto){
    int todoOk = 0;

    if( this != NULL && id_Piloto != NULL)
    {
        *id_Piloto = this->idPiloto;
        todoOk = 1;
    }
    return todoOk;
}

/** \brief piloto_get_nombre_Piloto
 *
 * \param this ePiloto*
 * \param nombre_Piloto char*
 * \return int
 *
 */
int piloto_get_nombre_Piloto(ePiloto* this,char* nombre_Piloto){
    int todoOk = 0;

    if( this != NULL && nombre_Piloto != NULL)
    {
        strcpy(nombre_Piloto, this->nombrePiloto);
        todoOk = 1;
    }
    return todoOk;
}

/** \brief piloto_get_isEmpty
 *
 * \param this ePiloto*
 * \param isEmpty int*
 * \return int
 *
 */
int piloto_get_isEmpty(ePiloto* this,int* isEmpty){
    int todoOk = 0;

    if( this != NULL && isEmpty != NULL)
    {
        *isEmpty = this->isEmpty;
        todoOk = 1;
    }
    return todoOk;
}

/** \brief piloto_Balderrama_new constructor
 *
 * \return ePiloto*
 *
 */
ePiloto* piloto_Balderrama_new()
{
    ePiloto* nuevo = (ePiloto*) malloc( sizeof(ePiloto));
    if(nuevo != NULL)
    {
        nuevo->idPiloto= 0;
        strcpy(nuevo->nombrePiloto," ");
        nuevo->isEmpty = 0;
    }
    return nuevo;
}

/** \brief piloto_Balderrama_NewParametros Constructor param
 *
 * \param idPiloto char*
 * \param nombrePiloto char*
 * \return ePiloto*
 *
 */
ePiloto* piloto_Balderrama_NewParametros(char* idPiloto,char* nombrePiloto)
{
    ePiloto* nuevo = piloto_Balderrama_new();
    int id_Piloto;

    id_Piloto = atoi(idPiloto);


    if( nuevo != NULL)
    {
        if(piloto_balderrama_setIdPiloto(nuevo,id_Piloto) &&
           piloto_balderrama_setNombrePiloto(nuevo,nombrePiloto))
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

/** \brief setIdPiloto
 *
 * \param this ePiloto*
 * \param idPiloto int
 * \return int
 *
 */
int piloto_balderrama_setIdPiloto(ePiloto* this,int idPiloto){
    int todoOk = 0;
    if(this != NULL && idPiloto >= 0)
    {
        this->idPiloto = idPiloto;
        todoOk = 1;
    }
    return todoOk;
}

/** \brief setNombrePiloto
 *
 * \param this ePiloto*
 * \param nombrePiloto char*
 * \return int
 *
 */
int piloto_balderrama_setNombrePiloto(ePiloto* this,char* nombrePiloto){
    int todoOk = 0;
    if(this != NULL && nombrePiloto != NULL && strlen(nombrePiloto) < 128)
    {
        strcpy(this->nombrePiloto, nombrePiloto);
        todoOk = 1;
    }
    return todoOk;
}

int filtrar_List_Piloto_By_Name(LinkedList* listaPilotos){

    int allOk = -1;
    char name_Piloto[128];

    if(listaPilotos != NULL){
        controller_Balderrama_ListPilotos(listaPilotos);

        printf("Ingrese Nombre del Piloto a Filtrar: ");
        fflush(stdin);
        gets(name_Piloto);


       listar_Pilotos_by_Nombre(listaPilotos,name_Piloto);

        allOk = 0;
    }


    return allOk;
}

/*
int filtro_name_piloto(void* elemento,char* name){
    int allOk = -1;

    ePiloto* aux;
    aux = (ePiloto*) elemento;

    if(strcmp(aux->nombrePiloto,name) == 0){
        allOk = 0;
    }

    return allOk;
}
*/

int listar_Pilotos_by_Nombre(LinkedList* listaPilotos,char* name){

    int todoOk = 0;
    ePiloto* aux;
    int flag = 0;
    if(listaPilotos != NULL)
    {
        printf("\n[   ID       Nombre_Piloto ]\n\n");
        for( int i=0; i < ll_len(listaPilotos); i++)
        {
            aux = (ePiloto*) ll_get(listaPilotos,i);
            if(strcmpi(aux->nombrePiloto,name) == 0){
                mostrarPiloto(aux);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("No hay Vuelos cargados para mostrar\n");
        }

        todoOk = 1;
    }

    return todoOk;

}


/**ll_count == Funciona como un acumulador o Contador su retorno es el valor*/
/**ll_Filter == Crea una lista paralela a la primera con diferencia al criterio q le pido*/
