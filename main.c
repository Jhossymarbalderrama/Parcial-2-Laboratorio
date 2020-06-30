#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#include "LinkedList.h"
#include "Controller_Balderrama.h"
#include "vuelos.h"
#include "Pilotos.h"

int menu();

int main()
{
    char rta = 'n';
    LinkedList* listaVuelos = ll_newLinkedList();
    LinkedList* listaPilotos = ll_newLinkedList();
    //int flag = 0;
    //int id = 1;
    char archivo[20];
    char extension[10] = ".csv";

    if( listaVuelos == NULL)
    {
        printf("No se pudo asignar memoria\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    //hardCode(listaPilotos);
    controller_Balderrama_loadFromText_Pilotos("Pilotos.csv",listaPilotos);
    do
    {
        switch(menu())
        {
        case 1:

            printf("Ingrese nombre del archivo: ");
            fflush(stdin);
            gets(archivo);
            strcat(archivo,extension);

            if(controller_Balderrama_loadFromText(archivo,listaVuelos)){
                 printf("[%d VUELOS CARGADOS CON EXITO.]\n",ll_len(listaVuelos));
            }

            break;
        case 2:
            controller_Balderrama_ListVuelos(listaVuelos,listaPilotos);
            break;
        case 3:
            printf("\n[Cantidad total de Pasajeros %d ]\n",cant_Pasajeros_all(listaVuelos));
            break;
        case 4:
            printf("\n[Cantidad de Pasajeros a Irlanda es : %d ]\n",cant_pasajeros_Irlanda(listaVuelos));
            break;
        case 5:
            archivos_Filtro_by_Duracion_3hs(listaVuelos);
            break;
        case 6:
            controller_Balderrama_ListVuelosPortugal(listaVuelos,listaPilotos);
            archivos_Filtro_Vuelos_to_Portugal(listaVuelos);
            break;
        case 7:
            archivos_Filtro_by_Chofer(listaVuelos);
            break;
        case 8:
            controller_Balderrama_ListPilotos(listaPilotos);
            break;
        case 9:
            filtrar_List_Piloto_By_Name(listaPilotos);
            //filtrar_List_Piloto_By_Name(listaPilotos);
            //sin el nombre
            break;
        case 10:

            break;
        case 15:
            printf("Confirma salir?: (S/N) ");
            fflush(stdin);
            rta = getche();
            printf("\n\n");
            break;
        default:
            printf("[- Opcion Incorrecta - ]\n");
            break;
        }
        if(rta != 's')
        {
            system("pause");
            system("cls");
        }
        else
        {
            ll_deleteLinkedList(listaVuelos);
            free(listaVuelos);
        }

    }
    while(rta == 'n');
    return 0;
}

/** \brief  Menu Principal de Opciones
 * \param
 * \return int Opcion
 */

int menu()
{
    int opcion;

    printf("===========================================================================================\n");
    printf("[                  =======           MENU PRINCIPAL           =======                     ]\n");
    printf("===========================================================================================\n");
    printf("| 1. Cargar Archivo.                                                                      |\n");
    printf("| 2. Imprimir Vuelos.                                                                     |\n");
    printf("| 3. Cantidad de Pasajeros.                                                               |\n");
    printf("| 4. Cantidad de Pasajeros a Irlanda.                                                     |\n");
    printf("| 5. Filtrar Vuelos Cortos.                                                               |\n");
    printf("| 6. Listar Vuelos a Portugal.                                                            |\n");
    printf("| 7. Filtrar a Alex Lifeson.                                                              |\n");
    printf("| 8. Imprimir Lista Pilotos.                                                              |\n");
    printf("| 9. Filtrar la lista de pilotos por nombre.                                              |\n");
  //printf("| 9. Guardar los datos de los empleados en el archivo data.bin (modo binario).            |\n");
    printf("| 15. Salir.                                                                              |\n");
    printf("===========================================================================================\n");

    do
    {
        printf("Ingrese opcion: ");
        scanf("%d",&opcion);
        fflush(stdin);
    }
    while(isdigit(opcion) != 0);

    return opcion;
}
