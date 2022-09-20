#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef struct{
    int enteros[4];
    char nombres[2][100];
    char aprobo;
} estudiante;

void integerBubble(estudiante arr[], int n, int o){
    int bubble[11];
    estudiante buffer;
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

    for(int i=0; i<10; i++){
        for(int j=i; j<10; j++){
            if(0==1){
                if(bubble[i]<bubble[j]){
                    bubble[10]=bubble[i];
                    bubble[i]=bubble[j];
                    bubble[j]=bubble[10];
                    buffer=arr[i];
                    arr[i]=arr[j];
                    arr[j]=buffer;
                }
            }else{
                if(bubble[i]>bubble[j]){
                    bubble[10]=bubble[i];
                    bubble[i]=bubble[j];
                    bubble[j]=bubble[10];
                    buffer=arr[i];
                    arr[i]=arr[j];
                    arr[j]=buffer;
                }
            }
        }
    }
    return;
}

void charBubble(estudiante arr[], int n, int o){
    char bubble[11][100];
    estudiante buffer;
    for(int i=0; i<10; i++)
        switch(n){
            case 2:
                strcpy(bubble[i], arr[i].nombres[0]);
                break;
            case 3:
                strcpy(bubble[i], arr[i].nombres[1]);
                break;
            case 7:
                bubble[i][0]=arr[i].aprobo;
                break;
        }

    for(int i=0; i<10; i++){
        for(int j=i; j<10; j++){
            for(int k=0; k<100; k++){
                if(strlen(bubble[i])<k || strlen(bubble[j])<k)
                    break;
                if(o==1){
                    if(bubble[i][k]<bubble[j][k])
                        break;
                    if(bubble[i][k]>bubble[j][k]){
                        strcpy(bubble[10], bubble[i]);
                        strcpy(bubble[i], bubble[j]);
                        strcpy(bubble[j], bubble[10]);
                        buffer=arr[i];
                        arr[i]=arr[j];
                        arr[j]=buffer;
                        break;
                    }
                }else{
                    if(bubble[i][k]>bubble[j][k])
                        break;
                    if(bubble[i][k]<bubble[j][k]){
                        strcpy(bubble[10], bubble[i]);
                        strcpy(bubble[i], bubble[j]);
                        strcpy(bubble[j], bubble[10]);
                        buffer=arr[i];
                        arr[i]=arr[j];
                        arr[j]=buffer;
                        break;
                    }
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
                                {{"Jonathan", "Isaac"}, {"Benfledt", "Garcia"}},
                                {{"Oliker", "Manfredo"}, {"Castillo", "Gramajo"}},
                                {{"Julio", "Andres"}, {"Cano", "Cifuentes"}},
                                {{"Javier", "Elias"}, {"Cifuentes", "Castro"}},
                                {{"Alejandro", "Pabel"}, {"Mendez", "Santos"}},
                                {{"Alex", "Pablo"}, {"Duque", "Gomez"}},
                                {{"Kenia", "Liza"}, {"Avila", "Mazariegos"}},
                                {{"Paula", "Delia"}, {"Durini", "Monterroso"}}};
    estudiante estudiantes[10];
    int in, o, maxDigits[6];

    for(int i=0; i<10; i++){
        int row=rand()%10; bool column=rand()%2;
        char buffer[100];
        //Random names
        strcpy(buffer, names[row][0][column]); strcat(buffer, " "); 
        row=rand()%10; column=rand()%2;
        strcat(buffer, names[row][0][column]);
        strcpy(estudiantes[i].nombres[0], buffer);
        row=rand()%10; column=rand()%2;
        strcpy(buffer, names[row][1][column]); strcat(buffer, " ");
        row=rand()%10; column=rand()%2;
        strcat(buffer, names[row][1][!column]);
        strcpy(estudiantes[i].nombres[1], buffer);
        estudiantes[i].enteros[0]=20220000+rand()%10000;
        estudiantes[i].enteros[1]=rand()%61;
        estudiantes[i].enteros[2]=rand()%41;
        estudiantes[i].enteros[3]=estudiantes[i].enteros[1]+estudiantes[i].enteros[2];
        if(estudiantes[i].enteros[3]>=61){
            estudiantes[i].aprobo=65;
        }else{
            estudiantes[i].aprobo=82;
        }

        //Getting max length for each column (Integer)
        for(int j=0; j<4; j++){
            if(maxDigits[j]<nL(estudiantes[i].enteros[j])){
                maxDigits[j]=nL(estudiantes[i].enteros[j]);
            }
        }
        //Getting max length for each column (String)
        for(int j=4; j<6; j++){
            if(maxDigits[j]<strlen(estudiantes[i].nombres[j-4])){
                maxDigits[j]=strlen(estudiantes[i].nombres[j-4]);
            }
        }
    }

    for(int i=0; i<10; i++){
        printf("Carne: %i%s | Nombres: %s%s | Apellidos: %s%s | Zona: %i%s | Examen: %i%s | Total %i%s | Aprobo: %c\n",
        estudiantes[i].enteros[0], rstr(' ', maxDigits[0] - nL(estudiantes[i].enteros[0])),
        estudiantes[i].nombres[0], rstr(' ', maxDigits[4] - strlen(estudiantes[i].nombres[0])),
        estudiantes[i].nombres[1], rstr(' ', maxDigits[5] - strlen(estudiantes[i].nombres[1])),
        estudiantes[i].enteros[1], rstr(' ', maxDigits[1] - nL(estudiantes[i].enteros[1])),
        estudiantes[i].enteros[2], rstr(' ', maxDigits[2] - nL(estudiantes[i].enteros[2])),
        estudiantes[i].enteros[3], rstr(' ', maxDigits[3] - nL(estudiantes[i].enteros[3])),
        estudiantes[i].aprobo);
    }
    while (true){
        printf("Seleccione por que columna desea ordenar\n>");
        scanf("%i", &in);
        printf("Ascendente o Descendente\n\t1. Asc\n\t2. Desc\n>");
        scanf("%i", &o);
        if(in != 2 && in != 3 && in != 7){
            integerBubble(estudiantes, 10, o);
        }else{
            charBubble(estudiantes, 10, o);
        }

        for (int i = 0; i < 10; i++)
        {
            printf("Carne: %i%s | Nombres: %s%s | Apellidos: %s%s | Zona: %i%s | Examen: %i%s | Total %i%s | Aprobo: %c\n",
                   estudiantes[i].enteros[0], rstr(' ', maxDigits[0] - nL(estudiantes[i].enteros[0])),
                   estudiantes[i].nombres[0], rstr(' ', maxDigits[4] - strlen(estudiantes[i].nombres[0])),
                   estudiantes[i].nombres[1], rstr(' ', maxDigits[5] - strlen(estudiantes[i].nombres[1])),
                   estudiantes[i].enteros[1], rstr(' ', maxDigits[1] - nL(estudiantes[i].enteros[1])),
                   estudiantes[i].enteros[2], rstr(' ', maxDigits[2] - nL(estudiantes[i].enteros[2])),
                   estudiantes[i].enteros[3], rstr(' ', maxDigits[3] - nL(estudiantes[i].enteros[3])),
                   estudiantes[i].aprobo);
        }
    }
    return 0;
}