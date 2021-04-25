#include <stdio.h>
#include <stdlib.h>

int main()
{
        char continuar="si";
       do {printf("desea continuar? Si o No");
       fflush(stdin);
        scanf("%v", continuar);}while( continuar != "si" || continuar != "no" );
        return 0;
}
