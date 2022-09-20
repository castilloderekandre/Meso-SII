#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int months[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

typedef struct{
    int d, m, y;
} fecha;

typedef struct{
    int ID, Edicion;
    char ISBN[11], Editorial[20];
    fecha Adq, Con;
} documento;

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

void selection(documento arr[], int it){
    int mIndex;
    documento buffer;
    for(int i=0; i<it; i++){
        mIndex=i;
        for(int j=i+1; j<it; j++){
            if(arr[mIndex].Edicion > arr[j].Edicion){
                mIndex=j;

            }
        }
        if(i != mIndex){
            buffer=arr[i];
            arr[i]=arr[mIndex];
            arr[mIndex]=buffer;
        }
    }
}

int main(){
    srand(time(0));
    int it=2+rand()%9;
    int mDi[it];
    char editoriales[4][20] = {{"Panamericana"}, {"Latam"}, {"Americatext"}, {"Edisi"}};
    documento documentos[it];
    for(int i=0; i<it; i++) mDi[i]=0;

    for(int i=0; i<it; i++){
        documentos[i].ID=i+1;
        strcpy(documentos[i].ISBN, "");
        for(int j=0; j<5; j++){
            char c[2] = {(char)(65+rand()%26)};
            strcpy(documentos[i].ISBN, strcat(documentos[i].ISBN, c));
        }
        for(int j=5; j<10; j++){
            char c[2] = {(char)(48+rand()%9)};
            strcpy(documentos[i].ISBN, strcat(documentos[i].ISBN, c));
        }
        strcpy(documentos[i].Editorial, editoriales[rand()%4]);
        documentos[i].Edicion=1990+rand()%32;
        int mes=rand()%12;
        documentos[i].Adq.d=1+rand()%months[mes];
        documentos[i].Adq.m=mes+1;
        documentos[i].Adq.y=2010+rand()%12;
        int anio=documentos[i].Adq.y+rand()%(2022-documentos[i].Adq.y);
        documentos[i].Con.d=1+rand()%months[mes];
        documentos[i].Con.m=(anio==documentos[i].Adq.y ? documentos[i].Adq.m : 1)+rand()%(anio==documentos[i].Adq.y ? 12-documentos[i].Adq.m : 12);
        documentos[i].Con.y=anio;
        if(mDi[0]<nL(documentos[i].ID))            mDi[0]=nL(documentos[i].ID);
        if(mDi[1]<strlen(documentos[i].ISBN))      mDi[1]=strlen(documentos[i].ISBN);
        if(mDi[2]<strlen(documentos[i].Editorial)) mDi[2]=strlen(documentos[i].Editorial);
        if(mDi[3]<nL(documentos[i].Edicion)) mDi[3]=nL(documentos[i].Edicion);
        if(mDi[4]<nL(documentos[i].Adq.d) + 
                  nL(documentos[i].Adq.m) + 
                  nL(documentos[i].Adq.y) + 2) mDi[4]=nL(documentos[i].Adq.d) + 
                                                      nL(documentos[i].Adq.m) + 
                                                      nL(documentos[i].Adq.y) + 2;
        if(mDi[5]<nL(documentos[i].Adq.d) + 
                  nL(documentos[i].Adq.m) + 
                  nL(documentos[i].Adq.y) + 2) mDi[5]=nL(documentos[i].Adq.d) + 
                                                      nL(documentos[i].Adq.m) + 
                                                      nL(documentos[i].Adq.y) + 2;
    }
    for(int i=0; i<it; i++)
        printf("Codigo: %i%s | ISBN: %s%s | Editorial: %s%s | Edicion: %i%s | Adquisicion: %i/%i/%i%s | Consulta: %i/%i/%i\n",
               documentos[i].ID, rstr(' ', mDi[0] - nL(documentos[i].ID)),
               documentos[i].ISBN, rstr(' ', mDi[1] - strlen(documentos[i].ISBN)),
               documentos[i].Editorial, rstr(' ', mDi[2] - strlen(documentos[i].Editorial)),
               documentos[i].Edicion, rstr(' ', mDi[3] - nL(documentos[i].Edicion)),
               documentos[i].Adq.d, documentos[i].Adq.m, documentos[i].Adq.y,
               rstr(' ', mDi[4] - (nL(documentos[i].Adq.d) + nL(documentos[i].Adq.m) + nL(documentos[i].Adq.y) + 2)),
               documentos[i].Con.d, documentos[i].Con.m, documentos[i].Con.y);
    selection(documentos, it);
    printf("Ordernado\n");
    for(int i=0; i<it; i++)
        printf("Codigo: %i%s | ISBN: %s%s | Editorial: %s%s | Edicion: %i%s | Adquisicion: %i/%i/%i%s | Consulta: %i/%i/%i\n",
               documentos[i].ID, rstr(' ', mDi[0] - nL(documentos[i].ID)),
               documentos[i].ISBN, rstr(' ', mDi[1] - strlen(documentos[i].ISBN)),
               documentos[i].Editorial, rstr(' ', mDi[2] - strlen(documentos[i].Editorial)),
               documentos[i].Edicion, rstr(' ', mDi[3] - nL(documentos[i].Edicion)),
               documentos[i].Adq.d, documentos[i].Adq.m, documentos[i].Adq.y,
               rstr(' ', mDi[3] - (nL(documentos[i].Adq.d) + nL(documentos[i].Adq.m) + nL(documentos[i].Adq.y) + 2)),
               documentos[i].Con.d, documentos[i].Con.m, documentos[i].Con.y);
    return 0;
}