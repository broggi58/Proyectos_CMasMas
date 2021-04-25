#include <stdio.h>
#include <stdlib.h>
#include "string.h"
int hacerfactorial (int num1,int num2);
int dividir(int num1,int num2);
int multiplicar(int num1,int num2);
int restar(int num1,int num2);
int sumar(int num1,int num2);
int pedirnuma();
int pedirnumb();
int main()
{
        int menu, A,B,suma,resta,fractb,flag1=0,flag2=0,multi,fracta,banderadiv=0,banderafracta=0,banderafractb=0;
        float div;
        char salir='n';
        printf(" 1.Ingresar 1er operando (A=x) \n");
        printf(" 2.Ingresar 2do operando (B=y)\n ");
        printf(" 3.Calcular todas las operaciones\n");
        printf("  Calcular la suma (A+B)\n");
        printf("  Calcular la resta (A-B)\n");
        printf("  Calcular la division (A/B)\n");
        printf("  Calcular la multiplicacion (A*B)\n");
        printf("  Calcular el factorial (A!)\n");
        printf(" 4.Informar resultados \n");
        printf(" 5.Salir \n");

        while(salir =='n')
        {

            scanf("%d",&menu);
            fflush(stdin);

        switch(menu)
        {
        case 1:
            {
                A=pedirnuma();

        printf("2.Ingresar 2do operando (B=y)\n ");
        printf(" 3.Calcular todas las operaciones\n");
        printf(" Calcular la suma (A+B)\n");
        printf(" Calcular la resta (A-B)\n");
        printf(" Calcular la division (A/B)\n");
        printf(" Calcular la multiplicacion (A*B)\n");
        printf(" Calcular el factorial (A!)\n");
        printf(" 4.Informar resultados \n");

        printf(" 5.Salir \n");
        if (A<0)
        {
            banderafracta==1;
        }
        break;
            }
        case 2:
            {
                system("cls");
                B=pedirnumb();
                printf(" 1.Ingresar 1er operando (A=%d) \n",A);
        printf(" 2.Ingresar 2do operando (B=%d)\n ",B);
        printf(" 3.Calcular todas las operaciones\n");
        printf(" Calcular la suma (A+B)\n");
        printf(" Calcular la resta (A-B)\n");
        printf(" Calcular la division (A/B)\n");
        printf(" Calcular la multiplicacion (A*B)\n");
        printf(" Calcular el factorial (A!)\n");
        printf(" 4.Informar resultados \n");
        printf(" 5.Salir \n");
        if (B<0)
        {
            banderafractb==1;
        }
        if (B==0)
        {
            banderadiv=1;
        }
            break;
            }
        case 3:
            {   suma=sumar (A,B);
                resta=restar(A,B);
                multi=multiplicar(A,B);
                div=dividir(A,B);
                fracta=hacerfactorial(A,flag1);
                fractb=hacerfactorial(B,flag2);
                printf("las operaciones se han realizado\n");
                break;
        }
        case 4:
            {
                system("cls");
                printf(" 1.Ingresar 1er operando (A=%d) \n",A);
                printf("2.Ingresar 2do operando (B=%d)\n ",B);
                printf(" 3.Calcular todas las operaciones\n");
                printf(" Calcular la suma (A+B)=%d\n",suma);
                printf(" Calcular la resta (A-B)=%d\n",resta);
                printf(" Calcular la multiplicacion (A*B)=%d\n",multi);

        if (banderadiv==0)
        {
            printf(" Calcular la division (A/B)=%.2f\n",div);
        }
        else if(banderadiv==1)
        {
            printf(" no se puede dividir por cero\n");
        }

         if(banderafracta==0)
        {
            printf("el fractil de A es %d\n",fracta);
        }
        else if (banderafracta=1)
        {
            printf(" no se puede sacar el fractil de un negativo\n");
        }

         if(banderafractb==0)
        {
            printf("el fractil de B es %d\n",fractb);
        }
        else if(banderafractb=1)
        {
            printf(" no se puede sacar el fractil de un negativo\n");
        }

        printf(" 5.Salir \n");
            break;
            }
        case 5:{
        salir='s';
        EXIT_SUCCESS;
        break;
        return 0;
            }
        default:
            {
                printf("Error. ingrese opcion valida\n");
                fflush(stdin);
                scanf("%d",&menu);
            }
        }


        }
        system("pause");
        return 0;
}


int pedirnuma(){
                int num;
        printf("ingresar 1er operando A=x /n");
        scanf("%d",&num);
        printf("ingresar 1er operando A=%d",num);
        return num;
        }
int pedirnumb(){
    int num;
        printf("ingresar 2do operando B=x /n");
        scanf("%d",&num);
        printf("ingresar 2do operando B=%d",num);
        return num;
        }
int sumar (int num1,int num2){
int suma=num1+num2;
return suma;
}
int restar (int num1,int num2){
int resta=num1-num2;
return resta;
}
int multiplicar (int num1,int num2){
int multi=num1*num2;
return multi;
}
int dividir (int num1,int num2){

if(num2!=0)
   {
    int bandera=0;
    float div= (float) num1/num2;
    return div;
    }
    else {

        return 0;
    }
}

int hacerfactorial (int num1,int num2){

    num2=num1;
    int factorial=1,bandera=0;


    for (num2 = num1; num2 > 1; num2--)
    {
    factorial = factorial * num2;
    }

    return factorial;
    if (num1==0){
        factorial==1;
        return 1;

    }
    else {
        bandera =1;
        return -1;
    }

}
