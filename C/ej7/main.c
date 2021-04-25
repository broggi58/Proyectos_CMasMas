#include <stdio.h>
#include <stdlib.h>

int main()
{
    float radio;
    float circ;
    float area;
    printf("ingrese radio");

    scanf("%f",&radio);
    circ=radio*2*3.14;
    area=radio*radio*3.14;
    printf("el area es %f y la circ es %f",area,circ);

    return 0;
}
