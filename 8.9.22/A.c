#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef struct{
    int enteros[4];
    char nombres[2][50];
    char aprobo;
} estudiante;

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

void integerInsertion(estudiante arr[], int aSize, int c, int o){
    int bubble[aSize+1], variable_index;
    for(int i=0; i<aSize; i++)
        switch(c){
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

    estudiante buffer;
    for(int i=1; i<aSize; i++){ //list
        variable_index=i;
        bubble[aSize]=bubble[i];
        buffer=arr[i];
        while(variable_index>0 && bubble[aSize]<bubble[variable_index-1]){ //Sublist; Moves items up to make space for insertion
            bubble[variable_index]=bubble[variable_index-1];
            arr[variable_index]=arr[variable_index-1];
            variable_index--;
        }
        bubble[variable_index]=bubble[aSize];
        arr[variable_index]=buffer;
    }
}

void charInsertion(estudiante arr[], int aSize, int c, int o){
    char bubble[aSize+1][50]; int variable_index;
    for(int i=0; i<aSize; i++)
        switch(c){
            case 2:
                strcpy(bubble[i], arr[i].nombres[0]);
                break;
            case 3:
                strcpy(bubble[i], arr[i].nombres[1]);
                break;
    }
    estudiante buffer;
    for(int i=1; i<aSize; i++){ //list
        int cIndex=0;
        variable_index=i;
        strcpy(bubble[aSize], bubble[i]);
        buffer=arr[i];
        while(variable_index>0 && bubble[aSize][cIndex++]<bubble[variable_index-1][cIndex]){ //Sublist; Moves items up to make space for insertion
            
        }
        for(;variable_index>0; variable_index--){
            if(bubble[aSize][cIndex]<bubble[variable_index-1][cIndex]){
                strcpy(bubble[variable_index], bubble[variable_index-1]);
                arr[variable_index]=arr[variable_index-1];
            }else{
                break;
            }
        }
        arr[variable_index]=buffer;
    }
}

int main(){
    srand(time(0));
    char names[16][2][2][50] = {{{"Derek", "Alejandra"}, {"Castillo", "Tovar"}},
                                {{"Eric", "Madelyn"}, {"Barrios", "Morales"}},
                                {{"Jonathan", "Kenia"}, {"Benfledt", "Garcia"}},
                                {{"Oliker", "Harelyn"}, {"Gonzalez", "Gramajo"}},
                                {{"Julio", "Sharito"}, {"Cano", "Cifuentes"}},
                                {{"Javier", "Liza"}, {"Perez", "Castro"}},
                                {{"Alejandro", "Rosita"}, {"Mendez", "Santos"}},
                                {{"Alex", "Maryory"}, {"Duque", "Gomez"}},
                                {{"Andre", "Arleth"}, {"Avila", "Mazariegos"}},
                                {{"Isaac", "Sofia"}, {"Durini", "Monterroso"}},
                                {{"Manfredo", "Leyli"}, {"Rodriguez", "Sanchez"}},
                                {{"Andres", "Delia"}, {"Ramirez", "Rivera"}},
                                {{"Pablo", "Renee"}, {"Diaz", "Cruz"}},
                                {{"Elias", "Emilia"}, {"Tol", "Reyes"}},
                                {{"Pabel", "Katherine"}, {"Guiterrez", "Mendoza"}},
                                {{"Estuardo", "Ayleen"}, {"Ruiz", "Jimenez"}}};
    estudiante estudiantes[10];
    int in, o, maxDigits[6];
    for(int i=0; i<6; i++){
        maxDigits[i]=0;
    }
    for(int i=0; i<10; i++){
        bool genero=rand()%2;
        //Random names
        strcpy(estudiantes[i].nombres[0], names[rand()%16][0][genero]);
        strcpy(estudiantes[i].nombres[1], names[rand()%16][1][rand()%2]);
        estudiantes[i].enteros[0]=20220000+rand()%10000; //Carne
        estudiantes[i].enteros[1]=rand()%61; //Zona
        estudiantes[i].enteros[2]=rand()%41; //Exam
        estudiantes[i].enteros[3]=estudiantes[i].enteros[1]+estudiantes[i].enteros[2]; //Zona completa
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
        for(int j=0; j<2; j++){
            if(maxDigits[j+4]<strlen(estudiantes[i].nombres[j])){
                maxDigits[j+4]=strlen(estudiantes[i].nombres[j]);
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
        integerInsertion(estudiantes, 10, in, o);
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