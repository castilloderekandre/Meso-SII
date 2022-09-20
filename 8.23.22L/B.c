#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include "..\Alg.h"

int months[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

typedef struct{
    int d, m, y;
}fecha;

typedef struct{
    int Id, pg;
    char t[41];
    fecha in;
}doc;

/*
char* getDate(fecha source){
    char* r[nL(source.d) + nL(source.m) + nL(source.y) + 3];
    char buffer[5];
    strcpy(r, strdup(itoa(source.d)));
    strcat(r, strdup("/"));
    strcpy(r, strdup(atoi(source.m)));
    strcat(r, strdup("/"));
    strcpy(r, strdup(atoi(source.y)));
    return strdup(r);
}

int getDateLength(fecha source){
    return nL(source.d) + nL(source.m) + nL(source.y) + 2;
}
*/

char *rstr(char c, int s){
    char str[s];
    for(int i=0; i<s; i++){
        str[i]=c;
    }
    str[s]='\0';
    return strdup(str);
}

int nL(int n){
    int d=1;
    while(((int)(n/10.0))>0){
        n=(int)(n/10.0); 
        d++;
    }
    return d;
}

void intOrder(doc source[]){
    doc buffer;
    for(int i=0; i<5; i++)
        for(int j=i+1; j<5; j++){
            if(source[i].pg<source[j].pg){
                buffer=source[i];
                source[i]=source[j];
                source[j]=buffer;
            }
        }
}

void charOrder(doc source[]){
    doc buffer;
    for(int i=0; i<5; i++)
        for(int j=i+1; j<5; j++){
            for(int k=0; k<40; k++){
                if(k==strlen(source[i].t)-1 || k==strlen(source[j].t)-1 || source[i].t[k]>source[j].t[k]) break;
                if(source[i].t[k]<source[j].t[k]){
                    buffer=source[i];
                    source[i]=source[j];
                    source[j]=buffer;
                    break;
                }
            }
        }
}

int main(){
    srand(time(0));
    char names[5][30]={"Inventario RFID", "Diseniador Circuitos Mixtos", "Inventario Informes", "IDE Interactivo", "Ayudante Nomenclatura"};
    doc informes[5];
    int mDi[3]={0, 0, 0}, autoC;
    printf("Autocrear titulos, paginas y fechas?\n 1. Si\n 2. No\n>");
    scanf("%i", &autoC);
    autoC--; autoC=!autoC;
    for(int i=0; i<5; i++){
        informes[i].Id=202208060+i;
        if(autoC){
            strcpy(informes[i].t, names[rand()%5]);
            informes[i].pg=5+rand()%95;
            informes[i].in.m=1+rand()%12;
            informes[i].in.d=1+rand()%months[informes[i].in.m-1];
            informes[i].in.y=2022;
        }else{
            printf("%i-Titulo: ", informes[i].Id);
            scanf("%40s", &informes[i].t);
            printf("%i-Paginas: ", informes[i].Id);
            scanf("%i", &informes[i].pg);
            printf("%i-Fecha-Dia: ", informes[i].Id);
            scanf("%i", &informes[i].in.d);
            printf("%i-Fecha-Mes: ", informes[i].Id);
            scanf("%i", &informes[i].in.m);
            printf("%i-Fecha-Anio: ", informes[i].Id);
            scanf("%i", &informes[i].in.y);
        }
        if(mDi[0]<nL(informes[i].Id))    mDi[0]=nL(informes[i].Id);
        if(mDi[1]<strlen(informes[i].t)) mDi[1]=strlen(informes[i].t);
        if(mDi[2]<nL(informes[i].pg))    mDi[2]=nL(informes[i].pg);
    }
    for(int i=0; i<5; i++)
        printf("Codgio: %i%s | Titluo: %s%s | Numero de paginas: %i%s | Fecha del informe: %i/%i/%i\n",
                informes[i].Id, rstr(' ', mDi[0] - nL(informes[i].Id)),
                informes[i].t,  rstr(' ', mDi[1] - strlen(informes[i].t)),
                informes[i].pg, rstr(' ', mDi[2] - nL(informes[i].pg)),
                informes[i].in.d, informes[i].in.m, informes[i].in.y);
    printf("Ordenar por:\n 1. Titulo\n 2. Numero de paginas\n>");
    int inp;
    scanf("%i", &inp);
    if(inp==1)
        charOrder(informes);
    else
        intOrder(informes);
    for(int i=0; i<5; i++)
        printf("Codgio: %i%s | Titluo: %s%s | Numero de paginas: %i%s | Fecha del informe: %i/%i/%i\n",
                informes[i].Id, rstr(' ', mDi[0] - nL(informes[i].Id)),
                informes[i].t,  rstr(' ', mDi[1] - strlen(informes[i].t)),
                informes[i].pg, rstr(' ', mDi[2] - nL(informes[i].pg)),
                informes[i].in.d, informes[i].in.m, informes[i].in.y);
    return 0;
}