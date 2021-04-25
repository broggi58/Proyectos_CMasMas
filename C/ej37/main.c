#include <stdio.h>
#include <stdlib.h>

int main()
{
        int a,b,c;
        do{printf("meter hora");
        fflush(stdin);
        scanf("%d",&a);}while(a <0 || a>24);
      do {

       printf("meter min");
        fflush(stdin);
        scanf("%d",&b);}while (b>60 || b<0);
        printf("%d:%d",a,b);

        printf("\ncambiar?");
        fflush(stdin);
        scanf("%d",&c);
        if(c==1)
        {
            do{printf("meter hora");
        fflush(stdin);
        scanf("%d",&a);}while(a <0 || a>24);
      do {

       printf("meter min");
        fflush(stdin);
        scanf("%d",&b);}while (b>60 || b<0);
        printf("%d:%d",a,b);
        }
        else {
            exit(0);
        }

        return 0;
}
