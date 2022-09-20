#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble(char arr[], int *changes){
    char buffer;
    for(int a=0; a<9; a++)
        for(int i=0; i<9; i++)
            if(arr[i]<arr[i+1]){
                *changes+=1;
                buffer=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=buffer;
            }
}

int main(){
    srand(time(0));
    char arr[11]; int changes=0;
    printf("Desordenados\n");
    for(int i=0; i<10; i++){
        arr[i]=97+rand()%26;
        printf(" %c |", arr[i]);
    }
    bubble(arr, &changes);
    printf("\nOrdenados\n");
    for(int i=0; i<10; i++){
        printf(" %c |", arr[i]);
    }
    printf("\nChanges: %i", changes);
    return 0;
}