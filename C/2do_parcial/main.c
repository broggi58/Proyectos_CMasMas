#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "LinkedList.h"
#include "utn.h"
#include "Controller.h"
#include "Concursantes.h"





int main()
{
   // int idConcursante;
    //int idConcursanteParaBuscar;
    int salir;
    int confirmarSalir;
    int flagHayConcursantes;
    int flagSegundaFase;
    char path[100]="\0";
    //path=newString(100);
    flagHayConcursantes=0;
    LinkedList* listaConcursantes=ll_newLinkedList();


    do{
        switch(menu())
        {

        case 1:
                    controller_loadFromText(listaConcursantes,&flagHayConcursantes,path);


                break;
            case 2:


                    controller_listElements(listaConcursantes,&flagHayConcursantes);
                    break;
            case 3:
                    controller_evaluarParticipantesSegundaFase(listaConcursantes,&flagHayConcursantes,path,&flagSegundaFase);
                break;
            case 4:
                    controller_informar(listaConcursantes,&flagHayConcursantes,&flagSegundaFase);
                break;
            case 5:
                    controller_guardarDatos(listaConcursantes,&flagHayConcursantes,&flagSegundaFase);
                    break;
            case 6:
                    controller_elegirFinalistas(listaConcursantes,&flagHayConcursantes,&flagSegundaFase);
                    break;
            case 7:
                    controller_controller_evaluarParticipantesEtapaTres(listaConcursantes,&flagHayConcursantes,path,&flagSegundaFase);
                break;
            case 8:

                    utn_getInt(&confirmarSalir,"Confirmar salida? Introducir 1 para confirmar o 2 para continuar.\n","Error. Opcion invalida.\n",1,2,22);
                    if(confirmarSalir==1)
                    {
                        salir=1;
                    }

                    break;
    }
    }while(salir!=1);


    return 0;
}
