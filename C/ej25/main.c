#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1,num2,num3,venta1,venta2,venta3,prom1,prom2,prom3;
    printf("ingrese nº de venderor");
    scanf("%d",&num1);
    printf("ingrese monto de ventas");
    fflush(stdin);
    scanf("%d",&venta1);
    printf("ingrese nº de venderor");
    scanf("%d",&num2);
    printf("ingrese monto de ventas");
    fflush(stdin);
    scanf("%d",&venta2);
    printf("ingrese nº de venderor");
    scanf("%d",&num3);
    printf("ingrese monto de ventas");
    fflush(stdin);
    scanf("%d",&venta3);

    prom1= (float) venta1- venta1* 0.95;
    prom2= (float) venta2- venta2* 0.95;
    prom3= (float) venta3- venta3* 0.95;
    printf("%d %d %d",prom1,prom2,prom3);



    return 0;
}
