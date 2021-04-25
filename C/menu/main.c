#include <stdio.h>
#include <stdlib.h>
int hacerfactorial (int num1,int num2);
int dividir(int num1,int num2);
int multiplicar(int num1,int num2);
int restar(int num1,int num2);
int sumar(int num1,int num2);
int pedirnuma();
int pedirnumb();
int main()
{
        int menu, A,B,suma,resta,fractb,flag1=0,flag2=0,multi,,fracta;
        float div;
        char salir='n';
        printf(" 1.Ingresar 1er operando (A=x) \n");
        printf("2.Ingresar 2do operando (B=y)\n ");
        printf(" 3.Calcular todas las operaciones\n");
        printf(" a)Calcular la suma (A+B)\n");
        printf(" b)Calcular la resta (A-B)\n");
        printf(" c)Calcular la division (A/B)\n");
        printf(" d)Calcular la multiplicacion (A*B)\n");
        printf(" e)Calcular el factorial (A!)\n");
        printf(" 4.Informar resultados \n");
        printf(" a)“El resultado de A+B es: r” \n");
        printf(" b)“El resultado de A-B es: r” \n");
        printf(" c)“El resultado de A/B es: r” o “No es posible dividir por cero” \n");
        printf(" d)“El resultado de A*B es: r” \n");
        printf(" e)“El factorial de A es: r1 y El factorial de B es: r2” \n");
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
                printf(" 1.Ingresar 1er operando (A=%d) \n",A);
        printf("2.Ingresar 2do operando (B=y)\n ");
        printf(" 3.Calcular todas las operaciones\n");
        printf(" a)Calcular la suma (A+B)\n");
        printf(" b)Calcular la resta (A-B)\n");
        printf(" c)Calcular la division (A/B)\n");
        printf(" d)Calcular la multiplicacion (A*B)\n");
        printf(" e)Calcular el factorial (A!)\n");
        printf(" 4.Informar resultados \n");
        printf(" a)“El resultado de A+B es: r” \n");
        printf(" b)“El resultado de A-B es: r” \n");
        printf(" c)“El resultado de A/B es: r” o “No es posible dividir por cero” \n");
        printf(" d)“El resultado de A*B es: r” \n");
        printf(" e)“El factorial de A es: r1 y El factorial de B es: r2” \n");
        printf(" 5.Salir \n");
        break;
            }
        case 2:
            {
                B=pedirnumb();
                printf(" 1.Ingresar 1er operando (A=%d) \n",A);
        printf("2.Ingresar 2do operando (B=%d)\n ",B);
        printf(" 3.Calcular todas las operaciones\n");
        printf(" a)Calcular la suma (A+B)\n");
        printf(" b)Calcular la resta (A-B)\n");
        printf(" c)Calcular la division (A/B)\n");
        printf(" d)Calcular la multiplicacion (A*B)\n");
        printf(" e)Calcular el factorial (A!)\n");
        printf(" 4.Informar resultados \n");
        printf(" a)“El resultado de A+B es: r” \n");
        printf(" b)“El resultado de A-B es: r” \n");
        printf(" c)“El resultado de A/B es: r” o “No es posible dividir por cero” \n");
        printf(" d)“El resultado de A*B es: r” \n");
        printf(" e)“El factorial de A es: r1 y El factorial de B es: r2” \n");
        printf(" 5.Salir \n");

            break;
            }
        case 3:
            {   suma=sumar (A,B);
                resta=restar(A,B);
                multi=multiplicar(A,B);
                div=dividir(A,B);
                fracta=hacerfactorial(A,flag1);
                fractb=hacerfactorial(B,flag2);
                printf("las operaciones se han realizado");
                break;


        }
        case 4:
            {
                printf(" 1.Ingresar 1er operando (A=%d) \n",A);
        printf("2.Ingresar 2do operando (B=%d)\n ",B);
        printf(" 3.Calcular todas las operaciones\n");
        printf(" a)Calcular la suma (A+B)=%d\n",suma);
        printf(" b)Calcular la resta (A-B)=%d\n",resta);
        printf(" c)Calcular la division (A/B)=%.2f\n",div);
        printf(" d)Calcular la multiplicacion (A*B)=%d\n",multi);
        printf(" e)Calcular el factorial (A!)=%d y %d\n",fracta,fractb);
        printf(" 4.Informar resultados \n");
        printf(" a)“El resultado de A+B es: r” \n");
        printf(" b)“El resultado de A-B es: r” \n");
        printf(" c)“El resultado de A/B es: r” o “No es posible dividir por cero” \n");
        printf(" d)“El resultado de A*B es: r” \n");
        printf(" e)“El factorial de A es: r1 y El factorial de B es: r2” \n");
        printf(" 5.Salir \n");
            break;
            }
        case 5:{
        salir=='s';
        break;
        return 0;
            }
        default:
            {
                printf("Error. ingrese opcion valida");
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
    float div=num1/num2;
    return div;
    }
    else {
        printf("Syntax error");
        return 0;
    }
}

int hacerfactorial (int num1,int num2){

    num2=num1;
    int factorial=1;

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
        printf("Syntax error");
        return -1;
    }

}
