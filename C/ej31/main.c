#include <stdio.h>
#include <stdlib.h>

int main()
{
        int valhora, antiguedad,canthoras,total,bonus,resultado;
        char nombre[10];

        printf("ingrese valor hora");
        fflush(stdin);
        scanf("%d",&valhora);
        printf("ingrese antiguedad");
        fflush(stdin);
        scanf("%d",&antiguedad);
        printf("ingrese cant de horas");
        fflush(stdin);
        scanf("%d",&canthoras);
        printf("ingrese nombre");
        fflush(stdin);
        scanf("%s",nombre);


        total=valhora*canthoras;
        bonus=antiguedad*30;
        resultado= (float) total+bonus-( (float)(total+bonus)*0.13 );

        printf("%d",resultado);




        return 0;
}
