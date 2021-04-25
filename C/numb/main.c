#include <stdio.h>
#include <stdlib.h>
int pedirnum();
int main()
{       int b= pedirnum();

        return 0;
}

int pedirnum(){
int num;
printf("ingresar 1er operando B=x /n");
        scanf("%d",&num);
        printf("ingresar 2do operando B=%d",num);
        return num;
        }
