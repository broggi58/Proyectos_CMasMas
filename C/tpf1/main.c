#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 10
char menu()
{
    char opcion;
    fflush(stdin);
    scanf("%c",&opcion);
    opcion= toupper(opcion);
    return opcion;
}
char* convertirFloatAString(float num,char aux[],int tam)
{
    gcvt(num,6,aux);
    return aux;
}
int encontrarPunto(char aux[],int tam)
{
    int i;
    for( i=0;i<tam;i++)
    {
        if(aux[i]=='.')
            break;
    }
    return i;
}
char* eliminarCeros(char aux[],int indice)
{
    int limite=strlen(aux);
    for(int i=limite;i>indice;i--)
    {
        if(aux[i]=='0')
            aux[i]='\0';
        else
            break;
    }
    return aux;
}
void mostrarNumA(int existeA,char num[])
{
    if(existeA)
    {
        printf("A- El operando A es %s",num);
    }
    else
    {
        printf("A- Mete el numerito bbto \n");
    }
}
void mostrarNumB(int existeB,char num[])
{
    if(existeB)
    {
        printf("B- El operando B es %s",num);
    }
    else
    {
        printf("B- Mete el numerito bbto \n");
    }
}
void mostrarSuma(int existeSuma,char num[])
{
    if(existeSuma)
    {
        printf("C- La sume es : %s",num);
    }
    else
    {
        printf("C- Hace la suma rey \n");
    }
}
void mostrarResta(int existeResta,char num[])
{
    if(existeResta)
    {
        printf("D- La resta es : %s",num);
    }
    else
    {
        printf("D- Hace la resta rey \n");
    }
}
void mostrarMulti(int existeMulti,char num[])
{
    if(existeMulti)
    {
        printf("E- La multi es : %s",num);
    }
    else
    {
        printf("E- Hace la multi rey \n");
    }
}
void mostrarDiv(int existeDiv,char num[])
{
    if(existeDiv)
    {
        printf("F- La div es : %s",num);
    }
    else
    {
        printf("F- Hace la div rey \n");
    }
}
void mostrarFact(int existeFact,int rdoFactA,int rdoFactB)
{
    if(existeFact)
    {
        printf("G- el fact de A  es : %d y el de B es %d",rdoFactA,rdoFactB);
    }
    else
    {
        printf("G- Hace el fact rey rey \n");
    }
}

void mostrarOpciones(int existeA,int existeB,int existeC,int existeD,int existeE,int existeF,int existeG,char num[],int rdoFactA,int rdoFactB)
{
    system("cls");
    printf("CALCULADORA SUPER POWER 3000 DEAAAA\n");
    mostrarNumA(existeA,num);
    mostrarNumB(existeB,num);
    mostrarSuma(existeC,num);
    mostrarResta(existeD,num);
    mostrarMulti(existeE,num);
    mostrarDiv(existeF,num);
    mostrarFact(existeG,rdoFactA,rdoFactB);
    printf("I- Tomarse el palo titanic\n");
}
float pedirNum()
{   float retorno=0;
    fflush(stdin);
    scanf("%f",&retorno);
    return retorno;
}
float suma(float numA, float numB)
{
    return numA+numB;
}
float resta(float numA, float numB)
{
    return numA-numB;
}
float multi(float numA, float numB)
{
    return numA*numB;
}
int validarDivision(float num)
{
    int retorno=1;
    if(num==0)
    {
        printf("No se puede divir x 0 anumal, never pony\n");
        retorno=0;
    }
    return retorno;
}
float dividir(float numA,float numB)
{
    return numA/numB;
}
int validarFactorial(float num)
{
    int aux=(int) num;
    int retorno=1;
    if(aux<0)
    {
        printf("No se puede sacar el fractil de un numero negativo pedazo de gato");
        retorno=0;
    }
    return retorno;
}
int factorial(float num)
{
    int retorno=(int) num;
    if(retorno==0)
        retorno=1;
    for(int i=num;i>1;i--)
    {
        retorno*=retorno;
    }
    return retorno;
}

int main()
{
    const int true=1;
    const int false=0;
    int existeA=false;
    int existeB=false;
    int existeSuma=false;
    int existeResta=false;
    int existeMulti=false;
    int existeDiv=false;
    int existeFrac=false;
    int indice;
    float numA,numB,rdoSuma,rdoResta,rdoMulti,rdoDiv;
    int rdoFracA,rdoFracB;
    char num[TAM];
    do{
            mostrarOpciones(existeA,existeB,existeSuma,existeResta,existeMulti,existeDiv,existeFrac,num,rdoFracA,rdoFracB);
    switch(menu())
    {
        case 'A':
                    numA=pedirNum();
                    existeA=true;
                    convertirFloatAString(numA,num,TAM);
                    indice=encontrarPunto(num,TAM);
                    eliminarCeros(num,indice);
                    break;
        case 'B':
                    numB=pedirNum();
                    existeB=true;
                    convertirFloatAString(numB,num,TAM);
                    indice=encontrarPunto(num,TAM);
                    eliminarCeros(num,indice);
                    break;
        case 'C':
                    if(existeA && existeB)
                       {
                        rdoSuma=suma(numA,numB);
                        existeSuma=true;
                        convertirFloatAString(rdoSuma,num,TAM);
                        indice=encontrarPunto(num,TAM);
                        eliminarCeros(num,indice);
                       }
                    else
                        printf("Mete los numeros antes de sumar la puta q te pario\n");
                    break;
        case 'D':
                    if(existeA && existeB)
                    {
                        rdoResta=resta(numA,numB);
                        existeResta=true;
                        convertirFloatAString(rdoResta,num,TAM);
                        indice=encontrarPunto(num,TAM);
                        eliminarCeros(num,indice);
                    }
                    else
                        printf("Mete los numeros antes de restar la puta q te pario\n");
                    break;
        case 'E':
            if(existeA && existeB)
                {
                        rdoMulti=multi(numA,numB);
                        existeMulti=true;
                        convertirFloatAString(rdoMulti,num,TAM);
                        indice=encontrarPunto(num,TAM);
                        eliminarCeros(num,indice);
                }
                    else
                        printf("Mete los numeros antes de multiplicar la puta q te pario\n");
                    break;
        case 'F':
            if((existeA && existeB)&&validarDivision(numB))
                {
                        rdoDiv=dividir(numA,numB);
                        existeDiv=true;
                        convertirFloatAString(rdoDiv,num,TAM);
                        indice=encontrarPunto(num,TAM);
                        eliminarCeros(num,indice);
                }
                    else if(!(existeA&&existeB))
                        printf("Mete los numeros antes de dividir la puta q te pario\n");
                    break;
        case 'G':
            if((existeA && existeB))
            {
                        if(validarFactorial(numA))
                        {
                            rdoFracA=factorial(numA);
                            existeFrac=true;
                        }
                        if  (validarFactorial(numB))
                        {
                            rdoFracB=factorial(numB);
                        }
        case 'H':
                printf("No vemo rey \n");
                break;
        default: printf("Mete una letra q valga salchicha\n");
            }
    }
    }while(menu()!='H');
        return 0;
}

