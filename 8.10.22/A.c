//Programa: Estructuras anidadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int months[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

typedef struct{
    int d, m, y;
} fecha;

typedef struct{
    int ID;
    char nombres[50];
    fecha entrada;
    fecha salida;
    int dias;
} socio;

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

void sort(socio arr[], int aSize, int o){
    socio buffer;
    for(int i=0; i<aSize; i++){
        for(int j=i+1; j<aSize; j++){
            if(o==1){
                if(arr[i].dias>arr[j].dias){
                    buffer=arr[i];
                    arr[i]=arr[j];
                    arr[j]=buffer;
                }
            }else{
                if(arr[i].dias<arr[j].dias){
                    buffer=arr[i];
                    arr[i]=arr[j];
                    arr[j]=buffer;
                }
            }
        }
    }
}

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
    int aSize, mDigits[4], o;
    for(int i=0; i<4; i++){ mDigits[i]=0; } //Filling array with 0s
    printf("Cuantos socios desea: ");
    scanf("%i", &aSize);
    if(aSize < 5){ aSize=5; }
    socio socios[aSize];
    for(int i=0; i<aSize; i++){
        socios[i].ID=i+1; //ID assignment
        strcat(strcat(strcpy(socios[i].nombres, names[rand()%16][0][rand()%2]), " "), names[rand()%16][1][rand()%2]); //Name assignment
        socios[i].entrada.d=1+rand()%months[rand()%12]; socios[i].entrada.m=1+rand()%12; socios[i].entrada.y=2000+rand()%22; //Initial date assignment
        socios[i].salida.d =1+rand()%months[rand()%12]; socios[i].salida.m =1+rand()%12; socios[i].salida.y =1+socios[i].entrada.y+rand()%(2022-socios[i].entrada.y); //Retirement date assignment
        socios[i].dias=days(socios[i].entrada, socios[i].salida);
        //Aesthetic
        if(nL(socios[i].ID)>mDigits[0]){ mDigits[0]=nL(socios[i].ID); }
        if(strlen(socios[i].nombres)>mDigits[1]) {mDigits[1]=strlen(socios[i].nombres); }
        if(nL(socios[i].entrada.d)+nL(socios[i].entrada.m)+nL(socios[i].entrada.y)>mDigits[2]){mDigits[2]=nL(socios[i].entrada.d)+nL(socios[i].entrada.m)+nL(socios[i].entrada.y); }
        if(nL(socios[i].salida.d) +nL(socios[i].salida.m) +nL(socios[i].salida.y) >mDigits[3]){mDigits[3]=nL(socios[i].salida.d) +nL(socios[i].salida.m) +nL(socios[i].salida.y); }
    }
    for(int i=0; i<aSize; i++)
    printf("Codigo: %i%s | Nombres: %s%s | Fecha-Entrada: %i/%i/%i%s | Fecha-Salida: %i/%i/%i%s | Dias: %i\n", 
            socios[i].ID,        rstr(' ', mDigits[0] - nL(socios[i].ID)),
            socios[i].nombres,   rstr(' ', mDigits[1] - strlen(socios[i].nombres)),
            socios[i].entrada.d,
            socios[i].entrada.m,
            socios[i].entrada.y, rstr(' ', mDigits[2] - (nL(socios[i].entrada.d)+nL(socios[i].entrada.m)+nL(socios[i].entrada.y))),
            socios[i].salida.d, 
            socios[i].salida.m,
            socios[i].salida.y,  rstr(' ', mDigits[3] - (nL(socios[i].salida.d)+nL(socios[i].salida.m)+nL(socios[i].salida.y))),
            socios[i].dias);
    printf("    1. Asc\n    2.Desc\n>");
    scanf("%i", &o);
    sort(socios, aSize, o);
    printf("\n  *Ordenado\n");
    for(int i=0; i<aSize; i++)
    printf("Codigo: %i%s | Nombres: %s%s | Fecha-Entrada: %i/%i/%i%s | Fecha-Salida: %i/%i/%i%s | Dias: %i\n", 
            socios[i].ID,        rstr(' ', mDigits[0] - nL(socios[i].ID)),
            socios[i].nombres,   rstr(' ', mDigits[1] - strlen(socios[i].nombres)),
            socios[i].entrada.d,
            socios[i].entrada.m,
            socios[i].entrada.y, rstr(' ', mDigits[2] - (nL(socios[i].entrada.d)+nL(socios[i].entrada.m)+nL(socios[i].entrada.y))),
            socios[i].salida.d, 
            socios[i].salida.m,
            socios[i].salida.y,  rstr(' ', mDigits[3] - (nL(socios[i].salida.d)+nL(socios[i].salida.m)+nL(socios[i].salida.y))),
            socios[i].dias);
    return 0;
}