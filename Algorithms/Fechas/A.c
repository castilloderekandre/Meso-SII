#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <string.h>

int months[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

typedef struct{
    int d, m, y;
} fecha;

int days(fecha inicial, fecha final){
    int sum = months[inicial.m-1] - inicial.d + 1,  j = inicial.m,  mLimit = 12;
    for(int i=0; i<=final.y-inicial.y; i++){
        if(inicial.y+i==final.y){
            mLimit=final.m-1;
            sum+=final.d;
        }
        for(; j<mLimit; j++){
            if((((inicial.y+i)%4==0   && (inicial.y+i)%100!=0) || 
               ((inicial.y+i)%100==0 && (inicial.y+i)%400==0)) && 
                 j==1){
                sum++;
            }
            sum+=months[j];
        }
        j=0;
    }
    return sum;
}

int main(){
    srand(time(0));
    fecha inicial;
    inicial.d=1+rand()%months[rand()%12]; inicial.m=1+rand()%12; inicial.y=2000+rand()%22;
    fecha final;
    final.d=1+rand()%months[rand()%12]; final.m=1+rand()%12; final.y=1+inicial.y+rand()%(2022-inicial.y);
    inicial.d=25; inicial.m=6; inicial.y=2007;
    final.d=23; final.m=6; final.y=3000;
    printf("Fecha-Inicial: %i/%i/%i\nFecha-Final: %i/%i/%i\n", inicial.d, inicial.m, inicial.y, final.d, final.m, final.y);
    printf("Dias: %i", days(inicial, final));
    return 0;
}