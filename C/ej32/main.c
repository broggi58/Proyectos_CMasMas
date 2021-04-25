#include <stdio.h>
#include <stdlib.h>

int main()
{
    int estudios,antiguedad;
    char nacionalidad;
    char nombre[20];

        while (cont<5)
        {
            printf("ingrese nombre");
            fflush(stdin);
            scanf("%s",nombre);
            printf("nacionalidad");

            fflush(stdin);
            scanf("%c",&nacionalidad);
            if (nacionalidad !='A'|| nacionalidad!='E' )
            {
                printf("error. otra vez");
                fflush(stdin);
                scanf("%c",&nacionalidad);
            }
            printf("estudios (1,2 o3)");
            fflush(stdin);
            scanf("%d",&estudios);
            if (estudios <1 || estudios>3)
            {
                printf("error");
                scanf("%d",&estudios);
            }
            printf("aniguedad");
            fflush(stdin);
            scanf("%d",&antiguedad);
            cont++;

        }


        return 0;
}
