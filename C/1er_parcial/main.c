#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "utn.h"
#include "arrayMascotas.h"
#include "arrayRazas.h"
#include "Informes.h"
#include "pais.h"



int main()
{
    int idMascota;
    int idMascotaParaBuscar;
    int salir;
    int idRaza;
    int idRazaParaBuscar;
    int confirmarSalir;
    const int TAM =10;
    const int tamTipos=3;
    const int tamTamanios=3;
    const int tamRaza=10;
    const int tamPaises=5;
    const int tamContinentes=5;
    idRaza=5;
    idMascota=1005;
    eMascota mascotas[TAM];
    eTipo tipos[tamTipos];
    eTamanio tamanios[tamTamanios];
    eRaza razas[tamRaza];
    ePais paises[tamPaises];
    eContinente contienentes[tamContinentes];
    initMascotas(mascotas,TAM);
    initRazas(razas,tamRaza);
    HardcodearTipos(tipos);
    HardcodearTamanios(tamanios);
    HardcodearRazas(razas);
    HardcodearMascotas(mascotas);
    HardcodearPaises(paises,tamPaises);
    HardcodearContinentes(contienentes,tamContinentes);


    do{
        switch(menu())
        {

            case 1:
                if(CrearMascota(mascotas,TAM,idMascota,razas,tamRaza,tamanios,tamTamanios,paises,tamPaises,contienentes,tamContinentes)==0)
                {
                    idMascota++;

                    printf("Alta exitosa!\n");
                    fflush(stdin);
                    printf("Pulse enter para continuar...\n");
                    getchar();
                }
                break;
            case 2:

                        utn_getInt(&idMascotaParaBuscar,"Ingresar id de la mascota a buscar:\n","Error. Id invalido.\n",1000,100000,3);
                       if(RemoverMascota(mascotas,TAM,idMascotaParaBuscar)==0)
                       {
                           printf("Mascota eliminada con exito!\n");

                       }

                    fflush(stdin);
                    printf("Pulse enter para continuar...\n");
                    getchar();
                    break;
            case 3:

                    utn_getInt(&idMascotaParaBuscar,"Ingresar id de la mascota a buscar:\n","Error. Id invalido.\n",1000,100000,3);

                       ModificarMascota(mascotas,TAM,idMascotaParaBuscar,razas,tamRaza,tamanios,tamTamanios);

                    fflush(stdin);
                    printf("Pulse enter para continuar...\n");
                    getchar();

                    break;
            case 4:

                        if(CrearRaza(razas,tamRaza,idRaza,paises,tamPaises,contienentes,tamContinentes)==0)
                    {
                        idRaza++;

                        printf("Alta exitosa!\n");
                        fflush(stdin);
                        printf("Pulse enter para continuar...\n");
                        getchar();
                    }
                    break;
            case 5:
                    Informes(mascotas,TAM,tamanios,tamTamanios,tipos,tamTipos,razas,tamRaza,paises,tamPaises,contienentes,tamContinentes);
                    break;

            case 6:
                    MostrarRazas(razas,tamRaza,tamanios,tamTamanios,paises,tamPaises,contienentes,tamContinentes);

                    if(utn_getInt(&idRazaParaBuscar,"Ingrese id de raza a eliminar\n","Error. Raza invalida.\n",0,tamRaza,3)==0)
                    {
                        if(razas[idRazaParaBuscar].isEmpty==1)
                        {
                            printf("Error. Raza  no existe.\n");
                        }
                        else
                        {
                            if(!RemoverRaza(razas,tamRaza,idRazaParaBuscar))
                            {
                                EliminarMascotaPorRaza(mascotas,TAM,idRazaParaBuscar);
                                printf("Raza y mascotas de esa raza eliminados!\n");
                            }
                        }
                    }
                    printf("Ingrese intro para continuar...\n");
                    fflush(stdin);
                    getchar();
                    break;
            case 7:

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
