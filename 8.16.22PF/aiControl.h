#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "tank.h"
extern int grid[3][3], dif;

void easy(){
    int aSize=checkTank();
    int coords[aSize][2];
    returnTank(coords);
    int rIndex=rand()%aSize;
    if(grid[coords[rIndex][1]][coords[rIndex][0]]==0)
        grid[coords[rIndex][1]][coords[rIndex][0]]=-1;
    return;
}

void medium(){
    return;
}

void hard(){
    return;
}

void AI(){
    do{
        switch(dif){
            case 1:
                easy();
                return;
            case 2:
                medium();
                return;
            case 3:
                hard();
                return;
        }
    }while(1);
}