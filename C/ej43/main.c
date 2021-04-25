#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define t 1

int main()
{ int n1[t];
int n2[t];
int n3[t];
int n4[t];
int n5[t];
int n6[t];
float p[t];
char n[t][50];

for (int i=0;i<=t;i++)
{
    printf("nombre");
    fflush(stdin);
    scanf("%s",n[i]);
    printf("nota");
    fflush(stdin);
    scanf("%d",&n1[i]);
    printf("nota");
    fflush(stdin);
    scanf("%d",&n2[i]);
    printf("nota");
    fflush(stdin);
    scanf("%d",&n3[i]);
    printf("nota");
    fflush(stdin);
    scanf("%d",&n4[i]);
    printf("nota");
    fflush(stdin);
    scanf("%d",&n5[i]);
    printf("nota");
    fflush(stdin);
    scanf("%d",&n6[i]);
    p[i]=(float) (n1[i]+n2[i]+n3[i]+n4[i]+n5[i]+n6[i])/6;
    printf("%s %f",n[i],p[i]);

}
printf("%s %f",n[0],p[0]);
printf("%s %f",n[1],p[1]);





    printf("Hello world!\n");
    return 0;
}
