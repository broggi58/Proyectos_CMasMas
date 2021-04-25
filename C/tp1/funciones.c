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
    float div=num1/num2;
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
