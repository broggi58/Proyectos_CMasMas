#include <stdio.h>
#include <stdlib.h>
int hacerfactorial (int num1,int num2);
int main()
{
    int num1,num2;
    int resultado= hacerfactorial(5,9);

        return resultado;
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
