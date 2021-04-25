#include "arrayMascotas.h"

int initMascotas(eMascota list[], int len)
{
    int retorno;
    int i;
    retorno=-1;
    if(list!=NULL || len!=10)
    {
        for(i=0;i<len;i++)
        {
            list[i].isEmpty=1;
        }
        retorno=0;
    }
 return retorno;
}


void HardcodearTipos (eTipo tipos[])
{
    int i;
    eTipo buffer[3]= {{"perro",1},{"gato",2},{"raro",3}};

    for(i=0;i<3;i++)
    {
        tipos[i]=buffer[i];
    }
}

void HardcodearMascotas (eMascota mascotas[])
{
    int i;
    eMascota buffer[7]= {{1000,"Felix",'m',3,2,1,12.5,0},{1001,"Claudia",'f',4,1,2,15.4,0},{1002,"Sergio",'m',3,2,3,22.4,0},{1003,"Gabriel",'f',5,1,4,51.4,0},{1004,"Pipa",'f',4,2,3,14.7,0},{1005,"Sergio",'f',4,2,3,14.9,0},{1006,"Sergia",'m',4,2,3,18.7,0}};

    for(i=0;i<7;i++)
    {
        mascotas[i]=buffer[i];
    }
}

int BuscarTipo(eTipo tipos [],int tamTipos, int idTipo)
{
    int indice;
    int i;
    indice=-1;
    for(i=0;i<tamTipos;i++)
    {
        if( tipos[i].idTipo== idTipo)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

void MostrarMascotas(eMascota mascotas[],int tamMascotas, eTipo tipos[],int tamTipos, eRaza razas[],int tamRazas, eTamanio tamanios[],int tamTamanios,ePais paises[],int tamPais)
{
    int r;
    int t;
    int i;
    int p;
    printf("ID       Nombre  Sexo  Edad     Tipo          Raza   Peso   Pais \n");
    for(i=0;i<tamMascotas;i++)
    {
        if(mascotas[i].isEmpty==0)
        {
            r=BuscarRaza(razas,tamRazas,mascotas[i].idRaza);
            t=BuscarTipo(tipos,tamTipos,mascotas[i].idTipo);
            p=BuscarPais(paises,tamPais,razas[r].idPais);
           // printf("%d %10s   %c     %d %10s %15s %3.2f %10s %d \n" ,mascotas[i].id,mascotas[i].nombre,mascotas[i].sexo,mascotas[i].edad,tipos[t].descripcion,razas[r].descripcion,mascotas[i].peso,paises[p].nombreDePais,paises[p].CodigoTelefonico);
            MostrarMascota(mascotas[i].id,mascotas[i].nombre,mascotas[i].sexo,mascotas[i].edad,tipos[t].descripcion,razas[r].descripcion,mascotas[i].peso,paises[p].nombreDePais,paises[p].CodigoTelefonico);
        }

    }
}
void MostrarMascota(int id,char* nombre,char sexo,int edad,char* descripcionTipo,char* descripcionRaza,float peso,char* pais,int codigoTel )
{
    printf("%d %10s   %c     %d %10s %15s %3.2f %10s %d \n" ,id,nombre,sexo,edad,descripcionTipo,descripcionRaza,peso,pais,codigoTel);
}
int BuscarLibre(eMascota mascotas[],int tam)
{
    int i;
    int indice;
    indice=-1;
    for(i=0;i<tam;i++)
    {
        if(mascotas[i].isEmpty==1)
        {
            indice=i;
        }
    }
    return indice;
}

int AgregarMascota(eMascota mascotas[], int tam, int id, char nombre[],char
sexo,int edad,int idTipo,int idRaza,float peso)
{
    int retorno;
    int indice;
    retorno=-1;
    indice= BuscarLibre(mascotas,tam);
    if(indice>=0)
    {
        mascotas[indice].id=id;
        strcpy(mascotas[indice].nombre,nombre);
        mascotas[indice].sexo=sexo;
        mascotas[indice].edad=edad;
        mascotas[indice].idTipo=idTipo;
        mascotas[indice].idRaza=idRaza;
        mascotas[indice].peso=peso;
        mascotas[indice].isEmpty=0;
        retorno=0;
    }

  return retorno;
}
int CrearMascota(eMascota mascotas[],int TAM,int id,eRaza razas[],int tamRazas,eTamanio tamanios[],int tamTamanios,ePais paises[],int tamPaises,eContinente continentes[],int tamContinentes)
{
    int retorno;
    int flagNombre;
    int flagEdad;
    int flagSexo;
    int flagTipo;
    int flagRaza;
    int flagPeso;
    retorno=-1;
    flagNombre=-1;
    flagEdad=-1;
    flagSexo=-1;
    flagTipo=-1;
    flagRaza=-1;
    flagPeso=-1;
    eMascota mascota;
    mascota.id=id;
    MostrarRazas(razas,tamRazas,tamanios,tamTamanios,paises,tamPaises,continentes,tamContinentes);
    flagNombre=utn_getString(mascota.nombre,"Ingrese nombre:\n","Error. Nombre fuera de rango\n",2,20,3);
    if(!flagNombre)
    {
        flagEdad=utn_getInt(&mascota.edad,"Ingrese edad: \n","Error. Edad fuera de rango\n",2,38,3);
    }
    if(!flagEdad)
    {
        flagSexo=utn_getCaracterSexo(&mascota.sexo,"Ingrese sexo (f o m): \n","Error. Sexo invalido.\n",'f','m',3);
    }
    if(!flagSexo)
    {
        flagTipo=utn_getInt(&mascota.idTipo,"Ingrese tipo (1- perro, 2- gato, 3- raro).\n","Error. Tipo ingresado no existe\n",1,3,3);
    }
    if(!flagTipo)
    {
        flagRaza=utn_getInt(&mascota.idRaza,"Ingrese raza .\n","Error. Raza ingresada no existe\n",1,4,3);
    }
    if(!flagRaza)
    {
        flagPeso=utn_getFloat(&mascota.peso,"Ingresar peso: \n","Error. Peso no valido.\n",0.1,999.9,3);

    }
    if(!flagPeso)
    {
        retorno= AgregarMascota(mascotas,TAM,id,mascota.nombre,mascota.sexo,mascota.edad,mascota.idTipo,mascota.idRaza,mascota.peso);
    }

    return retorno;
}


int EncontrarMascotaPorId(eMascota mascota[], int tam,int id)
{
    int retorno;
    int i;
    retorno=-1;
    if(mascota !=NULL && tam ==10)
    {
        for(i=0;i<tam;i++)
      {
        if(mascota[i].id==id && mascota[i].isEmpty==0)
        {
            retorno=i;
            break;
        }
      }
    }


 return retorno;

}

int RemoverMascota(eMascota mascota[], int tam, int id)
{
    int retorno;
    int indice;
    retorno=-1;
    if(mascota!=NULL|| tam!=10)
    {
        indice= EncontrarMascotaPorId(mascota,tam,id);
    }
    if(indice>=0)
    {
        mascota[indice].isEmpty=1;
        retorno=0;
    }
 return retorno;
}
void MostrarOpciones()
{
    printf("1- Alta mascota\n");
    printf("2- Baja mascota\n");
    printf("3- Modificar mascota\n");
    printf("4- Alta Raza\n");
    printf("5- Informar\n");
    printf("6- Baja raza\n");
    printf("7- Salir\n");

}
void MostrarOpcionesParaModificar()
{
    printf("1- Modificar nombre\n");
    printf("2- Modificar edad\n");
    printf("3- Modificar tipo\n");
    printf("4- Modificar raza\n");
    printf("5- Modificar sexo\n");

    printf("6- Modificar peso\n");
    printf("7- Regresar\n");

}
int ModificarMenu()
{
    int opcion;
    system("cls");
    MostrarOpcionesParaModificar();
    utn_getInt(&opcion,"Ingresar atributo a modificar\n","Error. ese atributo no existe\n",1,7,3);
    return opcion;

}

int ModificarMascota(eMascota mascota[],int tam,int id,eRaza razas[],int tamRazas,eTamanio tamanio[],int tamTamanio)
{
    int indice;
    int retorno;
    retorno=-1;
    if(mascota!=NULL || tam!=10)
    {
        indice= EncontrarMascotaPorId(mascota,tam,id);
    }
    if(indice>=0)
    {
        switch(ModificarMenu())
    {
        case 1 :
                 if(utn_getString(mascota[indice].nombre,"Ingrese nuevo nombre:\n","Error. Nombre fuera de rango\n",2,20,3)==0)
                 {
                     printf("Nombre modificado con exito!\n");
                     retorno=0;
                     printf("presione intro para continuar...\n");
            fflush(stdin);
            getchar();
                 }
                 break;
        case 2 :
                if(utn_getInt(&mascota[indice].edad,"Ingrese nueva edad:\n","Error. Edad fuera de rango\n",1,38,3)==0)
                {
                    printf("Edad modificada con exito!\n");
                    retorno=0;
                    printf("presione intro para continuar...\n");
            fflush(stdin);
            getchar();
                }

                break;
        case 3:
                if(utn_getInt(&mascota[indice].idTipo,"Ingrese nuevo tipo (1- perro, 2- gato, 3- raro):\n","Error. Tipo fuera de rango\n",1,3,3)==0)
                {
                    printf("Tipo modificado con exito!\n");
                    retorno=0;
                    printf("presione intro para continuar...\n");
            fflush(stdin);
            getchar();
                }

                break;
        case 4:

                if(utn_getInt(&mascota[indice].idRaza,"Ingrese nueva raza:\n","Error. Raza no existe\n",1,10,3)==0)
                {
                    printf("Raza modificada con exito!\n");
                    retorno=0;
                    printf("presione intro para continuar...\n");
            fflush(stdin);
            getchar();
                }

                break;
        case 5:
                if(utn_getCaracterSexo(&mascota[indice].sexo,"Ingrese nuevo sexo  \n","Error. Sexo ingresado no existe.\n",'f','m',3)==0)
                {
                    printf("Sexo modificado con exito!\n");
                    retorno=0;
                    printf("presione intro para continuar...\n");
            fflush(stdin);
            getchar();
                }
                break;
        case 6:
                if(!utn_getFloat(&mascota[indice].peso,"Ingrese nuevo peso: \n","Error. Ingrese peso valido.\n",0.1,999.9,3))
                {
                    printf("Peso modificado con exito.\n");
                    retorno=0;
                    printf("presione intro para continuar...\n");
            fflush(stdin);
            getchar();
                }
                break;
        case 7:
                break;

    }
    }
    else
    {
        printf("Error. No se encontro mascota con ese id.\n");
        fflush(stdin);
        printf("Pulse intro para continuar...\n");
        getchar();
    }
    return retorno;
}
int menu()
{
    int option;
    system("cls");
    MostrarOpciones();

    utn_getInt(&option,"Introduzca una opcion\n","Error. Introduzca una opcion valida\n",1,7,99);
    return option;
}
void EliminarMascotaPorRaza (eMascota mascotas[],int tamMascota,int idRaza)
{
    int i;
    for(i=0;i<tamMascota;i++)
    {
        if(mascotas[i].idRaza==idRaza)
        {
            mascotas[i].isEmpty=1;
        }
    }
}
