/*
    Programador: Derek Castillo
    Carne: 202208060
    Programa: Ordenamiento por seleccion
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct{
    int id;
    char nombres[2][100];
    float financio[3];
} empleado;

int nL(int n){ //Returns amount of digits in a number
    int d=1;
    while(((int)(n/10.0))>0){
        n=(int)(n/10.0); 
        d++;
    }
    return d;
}

char *rstr(char c, int s){ //Returns a string filled with 'c' of 's' length
    char str[s];
    for(int i=0; i<s; i++){
        str[i]=c;
    }
    str[s]='\0';
    return strdup(str);
}

void charSelection(empleado arr[], int aSize){ //Find mininum n, use current mininum n to find next one
    empleado buffer; int mIndex;
    for(int i=0; i<aSize; i++){ //Name
        mIndex=i;
        for(int j=i+1; j<aSize; j++) //Sub-name
            for(int c=0; c<50; c++){ //Char index for all strings
                if((strlen(arr[mIndex].nombres[0])<c || strlen(arr[j].nombres[0])<c) || (arr[j].nombres[0][c]>arr[mIndex].nombres[0][c])) break;
                if(arr[j].nombres[0][c]<arr[mIndex].nombres[0][c]){ mIndex=j; break; } //Interchange
            }
        if(i != mIndex){ //Redundant if...?
            buffer=arr[i];
            arr[i]=arr[mIndex];
            arr[mIndex]=buffer;
        }
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
    int it=10, maxDigits[6], in; //Main variables
    memset(maxDigits, 0, 6*sizeof(maxDigits[0])); //Fills 'maxDigits' with 0s
    printf("1. Autocrear empleados\n2. Ingresar empleados\n>");
    scanf("%i", &in);
    if(in==2){ //Getting quantity of EEs
        printf("Ingrese cantidad de empleados: ");
        scanf("%i", &it);
    }
    empleado lista[it];
    for(int i=0; i<it; i++){ //Inputting data
        // ID + Financio
        float salario = 3500 + rand() % 1501;
        lista[i].id = i + 1;
        lista[i].financio[0] = salario;
        lista[i].financio[1] = salario * 0.0486;
        lista[i].financio[2] = salario - lista[i].financio[1];
        if (nL(lista[i].id) > maxDigits[0]){
            maxDigits[0] = nL(lista[i].id);
        }
        for (int j = 0; j < 3; j++){
            if (nL(lista[i].financio[j]) > maxDigits[j + 1]){
                maxDigits[j + 1] = nL(lista[i].financio[j]);
            }
        }
        if(in==2){
            printf("Ingrese nombre para EE %i: ", i+1);
            scanf("%s", &lista[i].nombres[0]);
            printf("Ingrese apellido para EE %i: ", i+1);
            scanf("%s", &lista[i].nombres[1]);
        }else{
            // Nombres
            bool genero = rand() % 2;
            strcpy(lista[i].nombres[0], names[rand()%16][0][genero]);
            strcpy(lista[i].nombres[1], strcat(strcat(strcpy(lista[i].nombres[1], names[rand()%16][1][rand()%2]), " "), names[rand()%16][1][rand() % 2]));
        }
        for (int j = 0; j < 2; j++){ //Max length for names
            if (strlen(lista[i].nombres[j]) > maxDigits[j + 4]){
                maxDigits[j + 4] = strlen(lista[i].nombres[j]);
            }
        }
    }
    
    for(int i=0; i<it; i++){ //Print before ordering
        printf("Codigo: %i%s | Nombres: %s%s | Apellidos: %s%s | Salario: %.0f%s | IGSS: %.2f%s | Salario Neto: %.2f\n",
            lista[i].id,          rstr(' ', maxDigits[0]-nL(lista[i].id)),
            lista[i].nombres[0],  rstr(' ', maxDigits[4]-strlen(lista[i].nombres[0])),
            lista[i].nombres[1],  rstr(' ', maxDigits[5]-strlen(lista[i].nombres[1])),
            lista[i].financio[0], rstr(' ', maxDigits[1]-nL(lista[i].financio[0])),
            lista[i].financio[1], rstr(' ', maxDigits[2]-nL(lista[i].financio[1])),
            lista[i].financio[2]);
    }
    printf("%s\n    *Ascendiente por nombre\n", rstr('-', 200)); //Divisor
    charSelection(lista, it); //Order function call
    for(int i=0; i<it; i++){ //Print after ordering
        printf("Codigo: %i%s | Nombres: %s%s | Apellidos: %s%s | Salario: %.0f%s | IGSS: %.2f%s | Salario Neto: %.2f\n",
            lista[i].id,          rstr(' ', maxDigits[0]-nL(lista[i].id)),
            lista[i].nombres[0],  rstr(' ', maxDigits[4]-strlen(lista[i].nombres[0])),
            lista[i].nombres[1],  rstr(' ', maxDigits[5]-strlen(lista[i].nombres[1])),
            lista[i].financio[0], rstr(' ', maxDigits[1]-nL(lista[i].financio[0])),
            lista[i].financio[1], rstr(' ', maxDigits[2]-nL(lista[i].financio[1])),
            lista[i].financio[2]);
    }
    return 0;
}