#include <stdio.h>
#include <stdlib.h>
#define loop for(int i=0;i<size;i++)
void initChart(char chart[],int size)
{
    loop
    {
        chart[i]='-';
    }
}
void initFlags(int arrayFlags[],int size)
{
    loop
    {
        arrayFlags[i]=0;
    }
}
void printChart(char chart[])
{
    system("cls");
    printf("Asi va la cosa bros.\n");
    printf(" %c        %c        %c \n %c        %c        %c \n %c        %c        %c \n",chart[0],chart[1],chart[2],chart[3],chart[4],chart[5],chart[6],chart[7],chart[8]);
}
void play(char chart[],int* pTurn,int arrayFlags[])
{
    int aux,flag=0;
    if(*pTurn%2!=0)
    {
        printf("Jugador 1 mandale mechaaaa. En donde la queres poner(del 1 al 9)\n");
    }
    else
    {
        printf("Jugador 2 mandale mechaaaa. En donde la queres poner(del 1 al 9)\n");
    }
       do{
       do{
        fflush(stdin);
        scanf("%d",&aux);
        if(aux<1 || aux>9)
            printf("Mete bien el casillero la concha de hermana\n");
       }while((aux<1 || aux>9));
       if(!arrayFlags[aux-1]&& aux%2!=0)
       {
           chart[aux-1]='X';
           arrayFlags[aux-1]=1;
           *pTurn++;
           flag=1;
       }
       else if(!arrayFlags[aux-1]&& aux%2==0)
       {
           chart[aux-1]='O';
           arrayFlags[aux-1]=1;
           *pTurn++;
           flag=1;
       }
       else
       {
           printf("Ese lugar ya esta ocupado mamaguevo\n");
       }
       }while(!flag);

}
int checkVictory(char chart[])
{
   int retorno=0;
   if((chart[0]=='X'&&chart[1]=='X'&&chart[2]=='X')||(chart[3]=='X'&&chart[4]=='X'&&chart[5]=='X')||
      (chart[6]=='X'&&chart[7]=='X'&&chart[8]=='X')||(chart[0]=='X'&&chart[3]=='X'&&chart[6]=='X')||
      (chart[1]=='X'&&chart[4]=='X'&&chart[7]=='X')||(chart[2]=='X'&&chart[5]=='X'&&chart[8]=='X')||
      (chart[0]=='X'&&chart[4]=='X'&&chart[8]=='X')||(chart[2]=='X'&&chart[4]=='X'&&chart[6]=='X'))
   {
       retorno=1;
   }
   else if((chart[0]=='O'&&chart[1]=='O'&&chart[2]=='O')||(chart[3]=='O'&&chart[4]=='O'&&chart[5]=='O')||
      (chart[6]=='O'&&chart[7]=='O'&&chart[8]=='O')||(chart[0]=='O'&&chart[3]=='O'&&chart[6]=='O')||
      (chart[1]=='O'&&chart[4]=='O'&&chart[7]=='O')||(chart[2]=='O'&&chart[5]=='O'&&chart[8]=='O')||
      (chart[0]=='O'&&chart[4]=='O'&&chart[8]=='O')||(chart[2]=='O'&&chart[4]=='O'&&chart[6]=='O'))
      {
          retorno=2;
      }
      return retorno;
}
int checkDraw(char chart[],int size,int check)
{
    int retorno=0;
    loop
    {
        if(chart[i]=='-'&& !check)
        {
            retorno=1;
            break;
        }
    }
    return retorno;
}
void printWinner(int check)
{
    if(check==1)
    {
        printf("Wena player 1 le rompist ek culi culi\n");
    }
    else if(check==2)
    {
        printf("Eaaaa so re vo player 2 lo hiciste cagar pa dentro \n");
    }
}
int main()
{
    int arrayFlags[9];
    char chart[9];
    int turn=1;
    int* pTurn=&turn;
    int gameOn=1;
    int check=0;
    int draw;
    do{
        initChart(chart,9);
        initFlags(arrayFlags,9);
        do{
            printChart(chart);
            play(chart,pTurn,arrayFlags);
            check=checkVictory(chart);
            draw=checkDraw(chart,9,check);
            printWinner(check);
            if(draw)
                printf("Empataron man\n");
        }while(!check);
        printf(" Eeaaaa alta partida bros. Le quieren dar de nuevo? Mandale un num q no sea 0 para seguir. Sino tomatela.Me importa un carajo tomatela te dije.Atiendo boludos, no te das cuenta que ateindo boludos?\n");
        fflush(stdin);
        scanf("%d",&gameOn);
    }while(gameOn);
    printf("No vemo reina, pasa x casa cuando quieras\n");
    return 0;
}
