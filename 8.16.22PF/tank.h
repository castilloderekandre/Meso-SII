#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include "global.h"

#ifndef TANK_H_
#define TANK_H_

extern int grid[3][3];

int checkTank(){
    int sum=0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            sum+=abs(grid[i][j]);
        }
    }
    return 9-sum;
}

void returnTank(int coords[][2]){
    int k=0;
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(grid[i][j]==0){
                coords[k][0]=j;
                coords[k++][1]=i;
            }
}

int checkLinear(){
    int vertical=0, i, j, *A, *B;
    do{
        if(vertical) {A=&j; B=&i;} //Sets A to rows and B to columns
                else {A=&i; B=&j;} //Sets A to columns and B to rows
        for(i=0; i<3; i++){
            int sum=0; //Score tracker for current column/row.
            for(j=0; j<3; j++){
                sum+=grid[*A][*B]; //P1 = 1 -- P2 = -1
            }
            if(abs(sum)==3) return 1;
        }
        vertical = !vertical; 
    }while(vertical);
    return 0;
}

int checkDiagonal(){
    int lDiagonal=1, i;
    do{
        int sum=0, A;
        for(i=0; i<3; i++){
            if(lDiagonal){A=i;}
                    else {A=2-i;}
            sum+=grid[i][A];
        }
        if(abs(sum)==3) return 1;
        lDiagonal = !lDiagonal;
    }while(!lDiagonal);
    return 0;
}

void nextSpace(int n, COORD *pivot, int YAxis, int inclusive){
    int i=pivot->Y, j=pivot->X, *A, *B, buffer;
    if(YAxis) {A=&j; B=&i; buffer=i; i=j; j=buffer;}
        else  {A=&i; B=&j;}
    j+=(inclusive ? 0 : n);
    for(; i<3 && i>-1; i+=n){
        for(; j<3 && j>-1; j+=n){
            if(grid[*A][*B]==0){
                pivot->X=*B; pivot->Y=*A;
                return;
            }
        }
        if(n>0){j=0;} else {j=2;}
    }
}
#endif