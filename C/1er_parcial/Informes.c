#include "Informes.h"

void MostrarOpcionesInformes()
{
    printf("1- Mostrar listado de mascotas con raza y pais de origen\n");
    printf("2- Mostrar listado de razas con mascotas que pertenecen a cada raza\n");
    printf("3- Mostrar listado de mascotas ordenadas por peso\n");
    printf("4- Mostrar pais de origen con mas mascotas en la veterinaria\n");
    printf("5- Mostrar razas\n");
    printf("6- Mostrar listado de mascotas ordenadas por codigo telefonico del pais \n");
    printf("7- Mostrar peso por tipo\n");
    printf("8- Mostrar por tamanio y peso\n");
    printf("9- Ordenar por tipo y tamanio\n");
    printf("10- Salir\n");
}
int InformesMenu()
{
    int opcion;
    system("cls");
    MostrarOpcionesInformes();
    utn_getInt(&opcion,"Ingrese opcion:\n","Error. Opcion invalida.",1,10,3);
    return opcion;
}



void MostrarRazasConMascotas(eMascota mascotas[],int tamMascota,eRaza razas[],int tamRaza,eTamanio tamanios[],int tamTamanio,eTipo tipos[],int tamTipo)
{
    int i;
    int t;
    int m;
    for(i=0;i<tamRaza;i++)
    {
        t=BuscarTamanio(tamanios,tamTamanio,razas[i].idTam);
        if(razas[i].isEmpty==0)
        {
            printf("%10s  %10s \n",razas[i].descripcion,tamanios[t].descripcion);

        }

        for(m=0;m<tamMascota;m++)
        {
            if(mascotas[m].idRaza==razas[i].idRaza)
            {
                if(mascotas[m].isEmpty==0)
                {
                     printf("Nombre:%10s  Edad:%d  Sexo:%c\n\n",mascotas[m].nombre,mascotas[m].edad,mascotas[m].sexo);
                }

            }
        }
    }
}

void OrdenarPorPeso(eMascota mascotas[],int tamMascota,int sentido)
{
    eMascota buffer;
    int i;
    int j;
    ;
    if(sentido==1)
    {
        for(i=0;i<tamMascota-1;i++)
    {

        for(j=i;j<tamMascota;j++)
        {

            if(mascotas[i].peso>mascotas[j].peso )
            {
                buffer=mascotas[i];
                mascotas[i]=mascotas[j];
                mascotas[j]=buffer;
            }

        }
    }
    }
    if(sentido==2)
    {
        for(i=0;i<tamMascota-1;i++)
    {

        for(j=i;j<tamMascota;j++)
        {

            if(mascotas[i].peso<mascotas[j].peso )
            {
                buffer=mascotas[i];
                mascotas[i]=mascotas[j];
                mascotas[j]=buffer;
            }

        }
    }
    }

}

int ObtenerRazaMasComun(eRaza razas[],int contRaza,eMascota mascotas[],int tamMascota)
{
    int i;
    int j;
    int cont;
    int contMax;
    int idMax;
    cont=0;
    contMax=0;
    for(i=0;i<contRaza;i++)
    {
        for(j=0;j<tamMascota;j++)
        {
            if(razas[i].idRaza==mascotas[j].idRaza)
            {
                cont++;
            }
        }
        if(cont>contMax)
        {
            contMax=cont;
            idMax=razas[i].idRaza;
        }
        cont=0;
    }
    return idMax;
}

void MostrarPaisMasComun(ePais paises[],int tamPais,int id)
{
    int i;

    for(i=0;i<tamPais;i++)
    {
        if(id==paises[i].idPais)
        {
            break;
        }
    }
    printf("El pais con mas mascotas es %10s\n",paises[i].nombreDePais);
}

void Informes (eMascota mascotas[],int tam,eTamanio tamanios[],int tamTamanios,eTipo tipos[],int tamTipos,eRaza razas[],int tamRazas,ePais paises[],int tamPaises,eContinente continentes[],int tamContinentes)
{
    int sentido;
    int indice;
    int idTamParaBuscar;
    int CantidadMascotasPorTipo[tamTipos];
    float PesoTotalPorTipo[tamTipos];
    float PromedioPesoPorTipo[tamTipos];
    float PesoTotalPorTamanio;
    switch(InformesMenu())
    {
        case 1:
            MostrarMascotas(mascotas,tam,tipos,tamTipos,razas,tamRazas,tamanios,tamTamanios,paises,tamPaises);
            printf("presione intro para continuar...\n");
            fflush(stdin);
            getchar();
            break;
        case 2:
            MostrarRazasConMascotas(mascotas,tam,razas,tamRazas,tamanios,tamTamanios,tipos,tamTipos);
            printf("presione intro para continuar...\n");
            fflush(stdin);
            getchar();
            break;
        case 3:
            if(!utn_getInt(&sentido,"Ingresar sentido(1- Ascendente o 2- Descendente): \n","Error. Sentido no valido\n",1,2,3))
            {
               OrdenarPorPeso(mascotas,tam,sentido);
                MostrarMascotas(mascotas,tam,tipos,tamTipos,razas,tamRazas,tamanios,tamTamanios,paises,tamPaises);
            }
            printf("presione intro para continuar...\n");
            fflush(stdin);
            getchar();
            break;
        case 4:
                indice= ObtenerRazaMasComun(razas,tamRazas,mascotas,tam);
                MostrarPaisMasComun(paises,tamRazas,indice);
                printf("presione intro para continuar...\n");
                fflush(stdin);
                getchar();
                break;
        case 5:
                MostrarRazas(razas,tamRazas,tamanios,tamTamanios,paises,tamPaises,continentes,tamContinentes);
                printf("presione intro para continuar...\n");
                fflush(stdin);
                getchar();
                break;
        case 6:
                OrdenarPorCodigoTelefonico(mascotas,tam,razas,tamRazas,paises,tamPaises);
                MostrarMascotas(mascotas,tam,tipos,tamTipos,razas,tamRazas,tamanios,tamTamanios,paises,tamPaises);
                printf("presione intro para continuar...\n");
                fflush(stdin);
                getchar();
                break;
        case 7:
                CalcularPesoTotalPorTipo(mascotas,tam,tipos,tamTipos,PesoTotalPorTipo);
                CalcularCantidadDeMascotasPorTipo(mascotas,tam,tipos,tamTipos,CantidadMascotasPorTipo);
                CalcularPromedioPesoPorTipo(PesoTotalPorTipo,CantidadMascotasPorTipo,PromedioPesoPorTipo,tamTipos);
                MostrarPesoPorTipo(PesoTotalPorTipo,CantidadMascotasPorTipo,PromedioPesoPorTipo,tipos,tamTipos);
                printf("\nPresione intro para continuar...\n");
                fflush(stdin);
                getchar();
                break;
        case 8:
                MostrarTamanios(tamanios,tamTamanios);
                if(!utn_getInt(&idTamParaBuscar,"Ingrese ID de tamanio a buscar:\n","Error. Tamanio invalido.\n",1,3,3))
                {
                    MostrarMascotasPorTamanio(mascotas,tam,razas,tamRazas,idTamParaBuscar,tipos,tamTipos,paises,tamPaises);
                    PesoTotalPorTamanio= ObtenerPesoTotalPorTamanio(mascotas,tam,razas,tamRazas,idTamParaBuscar);
                    printf("El peso total de todas las mascotas de ese tamanio es:  %.2f",PesoTotalPorTamanio);
                }
                printf("\nPresione intro para continuar...\n");
                fflush(stdin);
                getchar();
                break;
        case 9: if(!utn_getInt(&sentido,"Ingresar sentido(1- Ascendente o 2- Descendente): \n","Error. Sentido no valido\n",1,2,3))
                {
                    OrdenarPorTipoyPeso(mascotas,tam,sentido);
                    //MostrarMascotas(mascotas,tam,tipos,tamTipos,razas,tamRazas,tamanios,tamTamanios,paises,tamPaises);
                    printf("Mascotas ordenadas por tipo y peso con exito!\n");
                }
                printf("Presione intro para continuar...\n");
                fflush(stdin);
                getchar();
                break;
        case 10:
                break;
    }
}
int ObtenerPaisMasComun(eRaza razas[],int contRaza,eMascota mascotas[],int tamMascota,ePais paises[],int tamPaises)
{
    int i;
    int j;
    int r1;

    int cont;
    int contMax;
    int idMax;
    cont=0;
    contMax=0;
    for(i=0;i<tamPaises;i++)
    {
        for(j=0;j<tamMascota;j++)
        {
            r1=BuscarRaza(razas,contRaza,mascotas[j].idRaza);
            if(paises[i].idPais== razas[r1].idPais && razas[r1].isEmpty==0)
            {
                cont++;
            }
        }
        if(cont>contMax)
        {
            contMax=cont;
            idMax=paises[i].idPais;
        }
        cont=0;
    }
    return idMax;
}

void OrdenarPorCodigoTelefonico (eMascota mascotas[],int tamMascotas,eRaza razas[],int tamRazas,ePais paises[],int tamPaises)
{
    int i;
    int j;
    int r1;
    int r2;
    int p1;
    int p2;
    eMascota buffer;
    for(i=0;i<tamMascotas-1;i++)
    {
        r1=BuscarRaza(razas,tamRazas,mascotas[i].idRaza);
        p1=BuscarPais(paises,tamPaises,razas[r1].idPais);
        for(j=i;j<tamMascotas;j++)
        {
            r2=BuscarRaza(razas,tamRazas,mascotas[j].idRaza);
            p2=BuscarPais(paises,tamPaises,razas[r2].idPais);
            if(paises[p1].CodigoTelefonico<paises[p2].CodigoTelefonico)
            {
                buffer=mascotas[i];
                mascotas[i]=mascotas[j];
                mascotas[j]=buffer;
            }
        }
    }
}

void CalcularPesoTotalPorTipo (eMascota mascotas[],int tamMascota,eTipo tipos[],int tamTipos,float PesosTotalesPorTipo[])
{
    float total;
    int i;
    int j;

    for(i=0;i<tamTipos;i++)
    {
        total=0;
        for(j=0;j<tamMascota;j++)
        {
            if(tipos[i].idTipo==mascotas[j].idTipo)
            {
                total+=mascotas[j].peso;
            }
        }
        PesosTotalesPorTipo[i]=total;
    }

}

void CalcularCantidadDeMascotasPorTipo (eMascota mascotas[],int tamMascota,eTipo tipos[],int tamTipos,int CantidadMascotasPorTipo[])
{
    int contador;
    int i;
    int j;

    for(i=0;i<tamTipos;i++)
    {
        contador=0;
        for(j=0;j<tamMascota;j++)
        {
            if(tipos[i].idTipo==mascotas[j].idTipo)
            {
                contador++;
            }
        }
        CantidadMascotasPorTipo[i]=contador;
    }

}

void CalcularPromedioPesoPorTipo (float PesoTotalPorTipo[],int CantidadMascotasPorTipo[],float PromedioPesoPorTipo[],int tamTipos)
{
    int i;

    for(i=0;i<tamTipos;i++)
    {
        if(CantidadMascotasPorTipo[i]!=0)
        {
            PromedioPesoPorTipo[i]= PesoTotalPorTipo[i]/CantidadMascotasPorTipo[i];
        }
    }

}
void MostrarTipos (eTipo tipos[], int tamTipos)
{
    int i;
    printf("Tipo:  ");

    for(i=0;i<tamTipos;i++)
    {
        printf("        %s",tipos[i].descripcion);
    }
}
void MostrarPesoTotal (float PesoTotalPorTipo[],int tamTipos)
{
    int i;
     printf("\nPeso total:");
    for(i=0;i<tamTipos;i++)
    {
        printf("    %.2f   ",PesoTotalPorTipo[i]);
    }
}
void MostrarCantidadDeMascotasPorTipo(int cantidadMascotasPorTipo[],int tamTipos)
{
    int i;
     printf("\nCantidad:");
    for(i=0;i<tamTipos;i++)
    {
        printf("        %d   ",cantidadMascotasPorTipo[i]);
    }
}
void MostrarPesoPromedio (float PromedioPesoPorTipo[],int cantidadMascotasPorTipo[],int tamTipos)
{
    int i;
    printf("\nPeso promedio:");
    for(i=0;i<tamTipos;i++)
    {
        if(cantidadMascotasPorTipo[i]==0)
        {
            printf("   0");
        }
        else
        {
            printf(" %.2f      ",PromedioPesoPorTipo[i]);
        }
    }
}
void MostrarPesoPorTipo (float PesoTotalPorTipo[],int CantidadMascotasPorTipo[],float PromedioPesoPorTipo[],eTipo tipos[],int tamTipos)
{
    MostrarTipos(tipos,tamTipos);
    MostrarPesoTotal(PesoTotalPorTipo,tamTipos);
    MostrarCantidadDeMascotasPorTipo(CantidadMascotasPorTipo,tamTipos);
    MostrarPesoPromedio(PromedioPesoPorTipo,CantidadMascotasPorTipo,tamTipos);

}

void MostrarMascotasPorTamanio(eMascota mascotas[],int tamMascota,eRaza razas[],int tamRazas,int idTam,eTipo tipos[],int tamTipos,ePais paises[],int tamPaises)
{
    int i;
    int j;
    int t;
    int p;
    for(i=0;i<tamRazas;i++)
    {
        if(razas[i].idTam==idTam && razas[i].isEmpty==0)
        {
            for(j=0;j<tamMascota;j++)
            {
                if(razas[i].idRaza==mascotas[j].idRaza && mascotas[j].isEmpty==0)
                {
                    t=BuscarTipo(tipos,tamTipos,mascotas[j].idTipo);
                    p=BuscarPais(paises,tamPaises,razas[i].idPais);
                    MostrarMascota(mascotas[j].id,mascotas[j].nombre,mascotas[j].sexo,mascotas[j].edad,tipos[t].descripcion,razas[i].descripcion,mascotas[j].peso,paises[p].nombreDePais,paises[p].CodigoTelefonico);
                }
            }
        }
    }
}

float ObtenerPesoTotalPorTamanio(eMascota mascotas[],int tamMascota,eRaza razas[],int tamRazas,int idTam)
{
    int i;
    int j;
    float total;
    total=0;
    for(i=0;i<tamRazas;i++)
    {
        if(razas[i].idTam==idTam && razas[i].isEmpty==0)
        {
            for(j=0;j<tamMascota;j++)
            {
                if(razas[i].idRaza==mascotas[j].idRaza && mascotas[j].isEmpty==0)
                {
                    total+=mascotas[j].peso;
                }
            }
        }
    }
    return total;
}

void OrdenarPorTipoyPeso(eMascota mascotas[],int tamMascota,int sentido)
{
    eMascota buffer;
    int i;
    int j;
    ;
    if(sentido==1)
    {
        for(i=0;i<tamMascota-1;i++)
    {

        for(j=i;j<tamMascota;j++)
        {

            if(mascotas[i].idTipo>mascotas[j].idTipo )
            {
                buffer=mascotas[i];
                mascotas[i]=mascotas[j];
                mascotas[j]=buffer;
            }
            else if(mascotas[i].idTipo==mascotas[j].idTipo && mascotas[i].peso>mascotas[j].peso)
            {
                buffer=mascotas[i];
                mascotas[i]=mascotas[j];
                mascotas[j]=buffer;
            }

        }
    }
    }
    if(sentido==2)
    {
        for(i=0;i<tamMascota-1;i++)
    {

        for(j=i;j<tamMascota;j++)
        {

            if(mascotas[i].idTipo<mascotas[j].idTipo )
            {
                buffer=mascotas[i];
                mascotas[i]=mascotas[j];
                mascotas[j]=buffer;
            }
            else if(mascotas[i].idTipo==mascotas[j].idTipo && mascotas[i].peso<mascotas[j].peso)
            {
                buffer=mascotas[i];
                mascotas[i]=mascotas[j];
                mascotas[j]=buffer;
            }

        }
    }
    }

}
