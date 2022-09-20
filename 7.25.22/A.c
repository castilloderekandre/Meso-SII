#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <string.h>
#define fields 5
//Aesthetic
int nL(int n){
    int d=1;
    while(((int)(n/10.0))>0){
        n=(int)(n/10.0); 
        d++;
    }
    return d;
}

typedef struct{
    int id;
    char name[50];
    int buy;
    int sell;
    int q;
} producto;

void integerBubble(producto arr[], int c, int s){
    int bubble[s+1], order[s+1];
    for(int i=0; i<s; i++){
        order[i]=i;
        switch(c){
            case 1:
                bubble[i]=arr[i].id;
                break;
            case 3:
                bubble[i]=arr[i].buy;
                break;
            case 4:
                bubble[i]=arr[i].sell;
                break;
            case 5:
                bubble[i]=arr[i].q;
                break;
        }
    }
    int bufi; //Integer buffer
    char bufs[50]; //String buffer
    for(int i=0; i<s; i++){
        for(int j=i; j<s; j++){
            if(bubble[i]<bubble[j]){
                bubble[s+1] = bubble[i];
                bubble[i]   = bubble[j];
                bubble[j]   = bubble[s+1];

                bufi      = arr[i].id;        //Almacenamiento de valor inicial
                arr[i].id = arr[j].id; //Cambio de valor inicial con final
                arr[j].id = bufi;             //Cambio de final con inicial

                strcpy(bufs,        arr[i].name);
                strcpy(arr[i].name, arr[j].name);
                strcpy(arr[j].name, bufs);

                bufi       = arr[i].buy;
                arr[i].buy = arr[j].buy;
                arr[j].buy = bufi;

                bufi        = arr[i].sell;
                arr[i].sell = arr[j].sell;
                arr[j].sell = bufi;

                bufi     = arr[i].q;
                arr[i].q = arr[j].q;
                arr[j].q = bufi;
            }
        }
    }
    return;
}

void strBubble(producto arr[], int c, int s){
    char bubble[s+1][50];
    int order[s+1];
    for(int i=0; i<s; i++){
        order[i]=i;
        strcpy(bubble[i], arr[i].name);
    }
    int bufi; //Integer buffer
    char bufs[50]; //String buffer
    for(int i=0; i<s; i++){
        for(int j=i; j<s; j++){
            for(int k=0; k<50; k++){
                if(strlen(bubble[i])<k+1 || strlen(bubble[j])<k+1)
                    break;
                if(bubble[i][k]<bubble[j][k]){
                    strcpy(bubble[s+1], bubble[i]);
                    strcpy(bubble[i], bubble[j]);
                    strcpy(bubble[j], bubble[s+1]);

                    bufi=arr[i].id;
                    arr[i].id=arr[j].id;
                    arr[j].id=bufi;

                    strcpy(bufs, arr[i].name);
                    strcpy(arr[i].name, arr[j].name);
                    strcpy(arr[j].name, bufs);

                    bufi=arr[i].buy;
                    arr[i].buy=arr[j].buy;
                    arr[j].buy=bufi;

                    bufi=arr[i].sell;
                    arr[i].sell=arr[j].sell;
                    arr[j].sell=bufi;

                    bufi=arr[i].q;
                    arr[i].q=arr[j].q;
                    arr[j].q=bufi;
                }
            }
        }
    }
    return;
}


void r(char c, int s){
    for(int i=0; i<s; i++){
        printf("%c", c);
    }
}

/*
char *rstr(char c, int s){
    char str[s+1];
    for(int i=0; i<s; i++){
        str[i]=c;
    }
    return strdup(str);
}
*/

int main(){
    srand(time(0));
    int in, vardigits[fields];
    producto arr[5];
    for(int i=0; i<fields; i++)
        vardigits[i]=0;

    for(int i=0; i<fields; i++){
        printf("Codigo: %i - Nombre: ", i+1);
        arr[i].id=i+1;
        scanf("%s", &arr[i].name);
        arr[i].buy=1+rand()%150;
        arr[i].sell=arr[i].buy+arr[i].buy*0.02;
        arr[i].q=1+rand()%100;

        //Gets max digit/length of a variable
        /*
        if(vardigits[0]<nL(arr[i].id))
            vardigits[0]=nL(arr[i].id);
        if(vardigits[1]<strlen(arr[i].name))
            vardigits[1]=strlen(arr[i].name);
        if(vardigits[2]<nL(arr[i].buy))
            vardigits[2]=nL(arr[i].buy);
        if(vardigits[3]<nL(arr[i].sell))
            vardigits[3]=nL(arr[i].sell);
            */
    }
    r('-', strlen("Codigo:  - Nombre: ") + vardigits[0] + vardigits[1]);
    printf("\n");
    for(int i=0; i<fields; i++){
        printf("Codigo: %i - Nombre: %s - Precio Costo: %i - Precio Venta: %i - Cantidad Disponible: %i\n", 
            arr[i].id,
            arr[i].name,
            arr[i].buy,
            arr[i].sell,
            arr[i].q);
    }
    printf("Seleccione por que columna quiere ordenar\n>");
    scanf("%i", &in);

    if(in!=2){
        integerBubble(arr, in, fields);
    }else{
        strBubble(arr, in, fields);
    }

    printf("Ordenados por columna %i\n", in);
    for(int i=0; i<fields; i++){
        printf("Codigo: %i - Nombre: %s - Precio Costo: %i - Precio Venta: %i - Cantidad Disponible: %i\n", 
            arr[i].id,
            arr[i].name,
            arr[i].buy,
            arr[i].sell,
            arr[i].q);
    }
    return 0;
}