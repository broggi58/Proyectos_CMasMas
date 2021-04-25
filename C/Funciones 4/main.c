#include <stdio.h>
#include <stdlib.h>
/*
    Se carga un vector con 20 numeros reales, se pide un numero al usuario y mediante una funcion se cuenta cuantas
    veces se repite.
*/

int buscar(float num);
int main()
{
    float bus;
    int cont;
    printf("Mete num para buska\n");
    fflush(stdin);
    scanf("%f",&bus);
    cont=buscar(bus);

    printf("El numero aparece %d veces\n",cont);
    return 0;
}

int buscar(float num)
{
    float numeros[19];
    int cont=0;
    for (int i=0;i<=19;i++)
    {
        printf("Meter numero perreke\n");
        fflush(stdin);
        scanf("%f",&numeros[i]);
        if(num==numeros[i])
        {
            cont++;
        }
    }
    return cont;
}
