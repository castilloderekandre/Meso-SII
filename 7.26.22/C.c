#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct{
    int enteros[2];
    char nombres[2][30];
} estudiante;

void integerBubble(estudiante arr[], int n){
    int bubble[11];
    for(int i=0; i<10; i++)
        switch(n){
            case 1:
                bubble[i]=arr[i].enteros[0];
                break;
            case 4:
                bubble[i]=arr[i].enteros[1];
                break;
    }

    char buffer[30];
    for(int i=0; i<10; i++){
        for(int j=i; j<10; j++){
            if(bubble[i]>bubble[j]){
                bubble[10]=bubble[i];
                bubble[i]=bubble[j];
                bubble[j]=bubble[10];
                for(int l=0; l<2; l++){
                    bubble[10]=arr[i].enteros[l];
                    arr[i].enteros[l]=arr[j].enteros[l];
                    arr[j].enteros[l]=bubble[10];
                }
                for(int l=0; l<2; l++){
                    strcpy(buffer, arr[i].nombres[l]);
                    strcpy(arr[i].nombres[l], arr[j].nombres[l]);
                    strcpy(arr[j].nombres[l], buffer);
                }
            }
        }
    }
    return;
}

void integerBubbleDesc(estudiante arr[], int n){
    int bubble[11];
    for(int i=0; i<10; i++)
        switch(n){
            case 1:
                bubble[i]=arr[i].enteros[0];
                break;
            case 4:
                bubble[i]=arr[i].enteros[1];
                break;
            case 5:
                bubble[i]=arr[i].enteros[2];
                break;
            case 6:
                bubble[i]=arr[i].enteros[3];
                break;
    }

    char buffer[30];
    for(int i=0; i<10; i++){
        for(int j=i; j<10; j++){
            if(bubble[i]<bubble[j]){
                bubble[10]=bubble[i];
                bubble[i]=bubble[j];
                bubble[j]=bubble[10];
                for(int l=0; l<2; l++){
                    bubble[10]=arr[i].enteros[l];
                    arr[i].enteros[l]=arr[j].enteros[l];
                    arr[j].enteros[l]=bubble[10];
                }
                for(int l=0; l<2; l++){
                    strcpy(buffer, arr[i].nombres[l]);
                    strcpy(arr[i].nombres[l], arr[j].nombres[l]);
                    strcpy(arr[j].nombres[l], buffer);
                }
            }
        }
    }
    return;
}

void charBubble(estudiante arr[], int n){
    char bubble[11][100];
    for(int i=0; i<10; i++)
        switch(n){
            case 2:
                strcpy(bubble[i], arr[i].nombres[0]);
                break;
            case 3:
                strcpy(bubble[i], arr[i].nombres[1]);
                break;
    }

    int buffer;
    for(int i=0; i<10; i++){
        for(int j=i; j<10; j++){
            for(int k=0; k<100; k++){
                if(strlen(bubble[i])<k || strlen(bubble[j])<k)
                    break;
                if(bubble[i][k]<bubble[j][k])
                    break;
                if(bubble[i][k]>bubble[j][k]){
                    strcpy(bubble[10], bubble[i]);
                    strcpy(bubble[i], bubble[j]);
                    strcpy(bubble[j], bubble[10]);
                    for(int l=0; l<2; l++){
                        buffer=arr[i].enteros[l];
                        arr[i].enteros[l]=arr[j].enteros[l];
                        arr[j].enteros[l]=buffer;
                    }
                    for(int l=0; l<2; l++){
                        strcpy(bubble[10], arr[i].nombres[l]);
                        strcpy(arr[i].nombres[l], arr[j].nombres[l]);
                        strcpy(arr[j].nombres[l], bubble[10]);
                    }
                    break;
                }
            }
        }
    }
    return;
}

void charBubbleDesc(estudiante arr[], int n){
    char bubble[11][100];
    for(int i=0; i<10; i++)
        switch(n){
            case 2:
                strcpy(bubble[i], arr[i].nombres[0]);
                break;
            case 3:
                strcpy(bubble[i], arr[i].nombres[1]);
                break;
    }

    int buffer;
    for(int i=0; i<10; i++){
        for(int j=i; j<10; j++){
            for(int k=0; k<100; k++){
                if(strlen(bubble[i])<k || strlen(bubble[j])<k)
                    break;
                if(bubble[i][k]>bubble[j][k])
                    break;
                if(bubble[i][k]<bubble[j][k]){
                    strcpy(bubble[10], bubble[i]);
                    strcpy(bubble[i], bubble[j]);
                    strcpy(bubble[j], bubble[10]);
                    for(int l=0; l<2; l++){
                        buffer=arr[i].enteros[l];
                        arr[i].enteros[l]=arr[j].enteros[l];
                        arr[j].enteros[l]=buffer;
                    }
                    for(int l=0; l<2; l++){
                        strcpy(bubble[10], arr[i].nombres[l]);
                        strcpy(arr[i].nombres[l], arr[j].nombres[l]);
                        strcpy(arr[j].nombres[l], bubble[10]);
                    }
                    break;
                }
            }
        }
    }
    return;
}

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

int main(){
    srand(time(0));
    char names[10][2][2][100]= {{{"Derek", "Andre"}, {"Castillo", "Tovar"}},
                                {{"Eric", "Estuardo"}, {"Barrios", "Morales"}},
                                {{"Jonathan", "Juan"}, {"Benefeldt", "Garcia"}},
                                {{"Oliker", "Manfredo"}, {"Castillo", "Gramajo"}},
                                {{"Julio", "Andres"}, {"Cano", "Cifuentes"}},
                                {{"Javier", "Elias"}, {"Cifuentes", "Castro"}},
                                {{"Alejandro", "Pabel"}, {"Mendez", "Santos"}},
                                {{"Alex", "Pablo"}, {"Duque", "Gomez"}},
                                {{"Kenia", "Liza"}, {"Avila", "Mazariegos"}},
                                {{"Paula", "Delia"}, {"Durini", "Monterroso"}}};
    estudiante estudiantes[10];
    int in, o, maxDigits[4];
    for(int i=0; i<4; i++){
        maxDigits[i]=0;
    }
    for(int i=0; i<10; i++){
        int row=rand()%10; bool column=rand()%2;
        char buffer[30];
        strcpy(buffer, names[row][0][column]); strcat(buffer, " "); strcat(buffer, names[row][0][!column]);
        strcpy(estudiantes[i].nombres[0], buffer);
        row=rand()%10; column=rand()%2;
        strcpy(buffer, names[row][1][column]); strcat(buffer, " ");
        row=rand()%10; column=rand()%2;
        strcat(buffer, names[row][1][!column]);
        strcpy(estudiantes[i].nombres[1], buffer);

        estudiantes[i].enteros[0]=20220000+rand()%10000;
        estudiantes[i].enteros[1]=rand()%101;
        //Getting max length for each column (Integer)
        for(int j=0; j<2; j++){
            if(maxDigits[j]<nL(estudiantes[i].enteros[j])){
                maxDigits[j]=nL(estudiantes[i].enteros[j]);
            }
        }
        //Getting max length for each column (String)
        for(int j=2; j<4; j++){
            if(maxDigits[j]<strlen(estudiantes[i].nombres[j-2])){
                maxDigits[j]=strlen(estudiantes[i].nombres[j-2]);
            }
        }
    }

    for(int i=0; i<10; i++){
        printf("Carne: %i%s - Nombres: %s%s - Apellidos: %s%s - Final %i\n",
        estudiantes[i].enteros[0], rstr(' ', maxDigits[0] - nL(estudiantes[i].enteros[0])),
        estudiantes[i].nombres[0], rstr(' ', maxDigits[2] - strlen(estudiantes[i].nombres[0])),
        estudiantes[i].nombres[1], rstr(' ', maxDigits[3] - strlen(estudiantes[i].nombres[1])),
        estudiantes[i].enteros[1], rstr(' ', maxDigits[1] - nL(estudiantes[i].enteros[1])));
    }
    printf("Ascendente o Descendente\n\t1. Asc\n\t2. Desc\n>");
    scanf("%i", &o);
    if(o==1)
        integerBubble(estudiantes, 4);
    else
        integerBubbleDesc(estudiantes, 4);

    for(int i=0; i<10; i++){
        printf("Carne: %i%s - Nombres: %s%s - Apellidos: %s%s - Final %i\n",
        estudiantes[i].enteros[0], rstr(' ', maxDigits[0] - nL(estudiantes[i].enteros[0])),
        estudiantes[i].nombres[0], rstr(' ', maxDigits[2] - strlen(estudiantes[i].nombres[0])),
        estudiantes[i].nombres[1], rstr(' ', maxDigits[3] - strlen(estudiantes[i].nombres[1])),
        estudiantes[i].enteros[1], rstr(' ', maxDigits[1] - nL(estudiantes[i].enteros[1])));
    }
    return 0;
}