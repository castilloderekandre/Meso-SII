#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "global.h"

extern int grid[3][3], points, dif;
extern jugador list[2];
void load();
void difMenu();
void statisticsMenu();
void menu();

void order(jugador arr[], int o){
    //...
}

void cursor(COORD actual, COORD previous, char c, int inclusive){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), previous);
    printf(" ");
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), actual);
    printf("%c", c);
    if(inclusive)
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), actual);
}

void printGrid(){
    printf("\n");
    for(int i=0; i<3; i++){
        printf(" %c | %c | %c \n", grid[i][0]==0 ? 32 : grid[i][0]==1 ? 88 : 79,
                                   grid[i][1]==0 ? 32 : grid[i][1]==1 ? 88 : 79,
                                   grid[i][2]==0 ? 32 : grid[i][2]==1 ? 88 : 79);
        if(i+1<3) printf("-----------\n");
    }
}

void load(){
    char animation[]={'\\', '|', '/', '-'};
    printf("Loading... ");
    COORD c = {.X=strlen("Loading... ")-1, .Y=0};
    for(int i=0; i<4; i++){
        cursor(c, c, animation[i%4], 1);
        Sleep(200);
    }
}

void difMenu(){
    char inp; short int choice=1;
    COORD A = {.X=0, .Y=choice}, B;
    system("cls");
    printf("Elija dificultad\n 1. Principiante\n 2. Medio\n 3. Experto\n 4. Regresar a menu principal");
    cursor(A, A, '>', 0);
    do{
        B=A;
        inp=getch();
        switch(inp){
            case KU:
                if(choice==1) break;
                A.Y=--choice;
                break;
            case KD:
                if(choice==4) break;
                A.Y=++choice;
            default:
                break;
        }
    cursor(A, B, '>', 0);
    }while(inp!='\r');
    if(choice==4) menu();
    dif=choice;
}

void statsticsMenu(){
    system("cls");
    printf("Points: %i\n", points);
    for(int i=0; i<2; i++)
        printf("Codigo: %i%s | Nickname: %s%s | Fecha de registro: %i/%i/%i%s | Partidas-Principiante: %i%s | Partidas-Medio: %i%s | Partidas-Experto: %i%s | Partiadas-Total: %i%s | Puntos: %i\n",
                list[i].Id,
                list[i].nombre, 
                list[i].Ingreso.d, list[i].Ingreso.m, list[i].Ingreso.y, 
                list[i].partidas[0], 
                list[i].partidas[1], 
                list[i].partidas[2], 
                list[i].partidas[3]);
}

void menu(){
    system("cls");
    char inp; int choice=1;
    COORD A = {.X=0, .Y=choice}, B;
    do{
        system("cls");
        printf("¡Bienvenido a Totito!\n 1. Nueva partida\n 2. Ver estadisticas\n 3. Salir");
        do{
            B=A;
            cursor(A, B, '>', 0);
            inp=getch();
            switch(inp){
                case KU:
                    if(choice==1) break;
                    A.Y=--choice;
                    break;
                case KD:
                    if(choice==3) break;
                    A.Y=++choice;
                default:
                    break;
            }
        cursor(A, B, '>', 0);
        }while(inp!='\r');
        switch (choice){
        case 1:
            difMenu();
            return;
        case 2:
            statsticsMenu();
            system("pause");
            break;
        case 3:
            exit(0);
            break;
        }
    }while(1);
}