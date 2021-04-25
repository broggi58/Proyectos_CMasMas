#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define loop for(int i=0;i<tam;i++)


typedef struct
{
    int idColor;
    int idModelo;
    int isEmpty;
}Auto;
typedef struct
{
    int id;
    char color[20];
}Color;
typedef struct
{
    int id;
    char modelo[20];
}Modelo;
/** \brief initAutos
 *         Inicializa el campo isEmpty del array de autos, para indicar que se encuentran todos vacios,antes de que el usuario
           cargue alguno.
 * \param Un array de tipo escructura Autos.
 * \param El tamaño de dicho array.
 * \return No retorna nada
 *
 */

void initAutos(Auto autos[],int tam)
{
    loop
    {
        autos[i].isEmpty=1;
    }
}
/** \brief cargarDescColor
 *          Se encarga de cargar la descripcion del id del color que esta dentro de una variable de la estructura auto,
            para que se muestre el texto perteneciente al imprimirla.
 * \param el id del color a cargar
 * \param el vector de colores
 * \param el tamaño del vector
 * \param una cadena de caracteres donde se va a cargar la descripcion.
 * \return retorna 0 si no se pudo cargar o la id es invalida. devuelve 1 su fue exitosa.
 *
 */


int cargarDescColor(int id,Color Colores[],int tam,char desc[])
{
    int retorno=0;
    loop
    {
        if(id==Colores[i].id)
        {
            strcpy(desc,Colores[i].color);
            retorno=1;
            break;
        }
    }
    return retorno;
}
/** \brief cargarDescModelo
 *          Se encarga de cargar la descripcion del id del modelo q metio el pancho del usuario, para q desp salga el
            nombre del modelo cuando se imprimma.
 * \param un id del modelo a cargar
 * \param un vector de modelos
 * \param el tamaño del vector
 * \param un string para guardar la descripcion bien piola
 * \return retorna 0 si no se pudo cargar y/o la id no existe, y retorna 1 si se cargo con exito
 *
 */

int cargarDescModelo(int id,Modelo modelos[],int tam,char desc[])
{
    int retorno=0;
    loop
    {
        if(id==modelos[i].id)
        {
            strcpy(desc,modelos[i].modelo);
            retorno=1;
            break;
        }
    }
    return retorno;
}
/** \brief mostrarColores
        Muestra al usuario la lista de colores con su respectivo id para darle al usuario la informacion y q meta el
        q quiera don
 *
 * \param un vector de colores
 * \param el tamaño del vector
 * \return no retorna nada
 *
 */

void mostrarColores(Color colores[],int tam)
{
    printf("   ID      COLOR\n");
    loop
    {
        printf("%d :  %s\n",colores[i].id,colores[i].color);
    }
}
/** \brief mostrarModelo
 *          Le muestra al usuario una lista de modelos con su respectivo id para que el usuario meta el q quiera vio,
 * \param un vector de tipo Modelo
 * \param el tamaño del vector
 * \return no retorna nada
 *
 */

void mostrarModelo(Modelo modelos[],int tam)
{
    printf("   ID      MODELO\n");
    loop
    {
        printf("%d   ;   %s\n",modelos[i].id,modelos[i].modelo);

    }
}
/** \brief validarColor
 *          Comprueba si el id ingresado forma parte de la lista de colores
 * \param un id de referencia
 * \param un vector de colores
 * \param el tamaño de ese vector
 * \return retorna 0 si no encontro el id, y 1 si lo encontro
 *
 */

int validarColor(int id,Color colores[],int tam)
{
    int retorno=0;
    loop
    {
        if(id==colores[i].id)
        {
            retorno=1;
            break;
        }
    }
    return retorno;
}
/** \brief validarModelo
        Comprueba si un modelo en cuestion forma parte de la lista o no.
 * \param un id del modelo de referencia
 * \param un array de modelos
 * \param tamaño del array
 * \return retorna 0 si el id no se encontro, y retorna 1 si fue encontrado con exito.
 *
 */

int validarModelo(int id, Modelo modelos[],int tam)
{
    int retorno=0;
    loop
    {
        if(id==modelos[i].id)
        {
            retorno=1;
            break;
        }
    }
    return retorno;
}
/** \brief mostrarAuto
 *         muestra por pantalla un auto, con sus descripciones de modelo y de color cargadas, si es posible cargarlas.
           caso con trario, no se muestra nada.
 * \param un indice de la pocision del array donde esta el auto a mostrar.
 * \param un vector de autos que contiene el auto mostrar en algun indice
 * \param tamaño del vector de arriba(en este caso, el tamaño de los 3 es el mismo, x eso solo hay un tamaño)
 * \param vector de colores
 * \param vector de modelos
 * \return retorna 0 si no se pudieron cargar las descripciones(y no muestra ningun otro dato x pantalla), y retorna 1
            si es exitosa.
 *
 */

int mostrarAuto(int indice,Auto autos[],int tam,Color colores[],Modelo modelos[])
{
    char descColor[20];
    char descModelo[20];
    if(!validarColor(autos[indice].idColor,colores,tam))
       {
           printf("error. No se pudo cargar un color con esa id\n");return 0;
       }

    else
        cargarDescColor(autos[indice].idColor,colores,tam,descColor);
    if(!validarModelo(autos[indice].idModelo,modelos,tam))
        {
            printf("error. No se pudo cargar un modelo con esa id\n");return 0;
        }
    else
        cargarDescModelo(autos[indice].idModelo,modelos,tam,descModelo);
    printf("%s            %s     \n",descColor,descModelo);
    return 1;
}
/** \brief mostrarAutos
 *          Mediante un bucle, llama a la funcion anterior por cada elemento del array
 * \param indice para señalarle a la funcion anterior que elemento imprimir
 * \param un vector de autos
 * \param tamaño de los vectores
 * \param un array de colores
 * \param un array de modelos
 * \return n retorna nada
 *
 */

void mostrarAutos(int indice,Auto autos[],int tam,Color colores[],Modelo modelos[])
{
    loop
    {
        if(mostrarAuto(indice,autos,tam,colores,modelos));
    }
}
/** \brief buscarLibre
 *          Se encarga de buscar un indice libre para que el usuario realice una nueva entrada
 * \param un veector de autos para recorrer
 * \param tamaño del vector
 * \return retorna -1 si todos los espacios estan llenos, y retorna el indice de la primer posicion libre que encontro si hay
            alguno.
 *
 */

int buscarLibre(Auto autos[],int tam)
{
    int retorno=-1;
    loop
    {
        if(autos[i].isEmpty)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
/** \brief nuevoAuto
 *         Se encarga de dar de alta a un nuevo auto, en un indice encontrado por la fuuncion de buscar libre, si es que hay
            alguno.
 * \param un vectr de tipo autos
 * \param tamaño de dicho vector
 * \return retorna el indice donde se guardo el nuevo elemento, o -1 si no hay lugar para agregar uno nuevo.
 *
 */

int nuevoAuto(Auto autos[],int tam)
{

    int indice=buscarLibre(autos,tam);
    if(indice==-1)
        printf("No hay lugar libre titan deaaaa\n");
    else
    {
        printf("Mete el id del color mastodnote\n");
        fflush(stdin);
        scanf("%d",&autos[indice].idColor);
        printf("Ahora mete el id del modelo maquinola \n00");
        scanf("%d",&autos[indice].idModelo);
        autos[indice].isEmpty=0;
    }
    return indice;
}

int main()
{
    const int tam=3;

    printf("Hello world!%d\n",tam);
    return 0;
}
