#include <stdio.h>
#include <stdlib.h>

int main()
{
        int a,cont=0,b,c,cont1=0,cont2=0;
        while(cont<6)
        {
            printf("mete cuanto gana");
            fflush(stdin);
            scanf("%d",&a);
            do{printf("mete sexo 1 o2");
            fflush(stdin);
            scanf("%d",&b);}while (b!=1 && b!=2);
            if (b==1 )
            {
                if(a<400)
                {
                    cont1++;
                }
            }
            if (b==2)
            {
                if(b>500)
                {
                    cont2++;
                }
            }
            cont++;
        }
        return 0;
}
