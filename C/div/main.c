#include <stdio.h>
#include <stdlib.h>
int dividir(int num1,int num2);
int main()

{
    int num1,num2;
    float resultado=dividir(20,0);
    return resultado;

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
