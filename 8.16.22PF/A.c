#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include "global.h"
#include "tank.h"
#include "graphic.h"
#include "aiControl.h"

extern int grid[3][3], dif, points=0;
extern jugador list[2];
int P=0, registerCount=0, actual;
char names[2][20], icon[2]={'X', 'O'};

void game(){
    system("cls");
    printf("Nombre de jugador: ");
    scanf("%s", &names[0]);
    strcpy(names[1], "CPU");
    int ContinueGame=0;
    do{
        for(int i=0; i<3; i++) for(int j=0; j<3; j++) grid[i][j]=0;
        do{
            P=0;
            system("cls");
            COORD pCursor, gCursor = {.X=0, .Y=0}, previous;
            nextSpace(1, &gCursor, 0, 1);
            char inp;
            pCursor.X=gCursor.X*4+1; pCursor.Y=gCursor.Y*2+1;
            printf("Jugador actual: %s", names[P]);
            printGrid();
            cursor(pCursor, pCursor, icon[P], 1);
            do{
                inp = getch();
                switch(inp){
                    case KU:
                        nextSpace(-1, &gCursor, 1, 0);
                        break;
                    case KD:
                        nextSpace(1, &gCursor, 1, 0);
                        break;
                    case KL:
                        nextSpace(-1, &gCursor, 0, 0);
                        break;
                    case KR:
                        nextSpace(1, &gCursor, 0, 0);
                        break;
                }
                previous=pCursor;
                pCursor.X=gCursor.X*4+1; pCursor.Y=gCursor.Y*2+1;
                cursor(pCursor, previous, icon[P], 1);
            }while(inp!='\r');
            grid[gCursor.Y][gCursor.X]=P ? -1 : 1;
            if(checkLinear() || checkDiagonal() || checkTank()==0) break;
                                                            else {P=1; AI();}
        }while(!checkLinear() && !checkDiagonal() && checkTank()>0);
        system("cls");
        if(checkLinear() || checkDiagonal()) {printf("Gano %s(%c)", names[P], icon[P]);
                                              points+=(100*P+25*pow(2, dif-1)*(P ? -1 : 1))*(P ? -1 : 1);}
                                              else printf("Empate");
        printGrid();
        Sleep(200); //Key stroke protection
        system("pause");
        int end;
        do{
            system("cls");
            printf("Desea jugar de nuevo?\n 1. Si\n 2. No\n>");
            scanf("%i", &end);
        }while(end!=1 && end!=2);
        if(end==1) ContinueGame=1;
        else ContinueGame=0;
        //... Menu
    }while(ContinueGame);
}

/*
void Register(){
    system("cls");
    if(registerCount==2) return;
    list[registerCount].ID = registerCount+1;
    printf("Codigo: %i\nIngrese su nombre: ", registerCount);
    scanf("%s", list[registerCount].nombre);
}
*/

int main(){
    srand(time(0));
    system("cls");
    load();
    while(1){
        menu();
        game();
    }

    return 0;
}