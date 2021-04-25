#include <stdio.h>
#include <stdlib.h>
#include "conio.h"

/*
    Se introducen 2 valores (base y altura) y se calcula la superficie de un rectangulo con ellos
    pasandoselos a una funcion. Se siguen introduciendo valores hasta que en ambas se introduce 0.
*/
float superficie(float base,float altura);

int main()
{
    float base,altura,valsuperficie;

   do {
        system("cls");
        printf("introduzca base\n");
        scanf("%f",&base);

        printf("introduzca altura\n");
        scanf("%f",&altura);
        valsuperficie= superficie(base,altura);
        printf("La superficie es %.2f",valsuperficie);
        getche();
                            }while (base!=0 && altura!=0);






    return 0;
}

float superficie(float base,float altura){

return base*altura;

}

