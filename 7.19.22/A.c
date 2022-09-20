#include <stdio.h>
#include <string.h>
#include <time.h>

void rc(char c, int n){
    for(int i=0; i<n; i++){
        printf("%c", c);
    }
}

int main(){
    srand(time(0));
    char arr[11], vowels[]="aeiou", consonants[]="bcdfghjklmnpqrstvwxyz";
    int v=0, c=0;
    for(int i=0; i<10; i++){
        arr[i]=97+rand()%26;
        for(int j=0; j<5; j++){
            if(arr[i]==vowels[j]){
                v++;
            }
        }
        for(int j=0; j<21; j++){
            if(arr[i]==consonants[j]){
                c++;
            }
        }
    }
    printf("| ");
    for(int i=0; i<10; i++){
        printf("%c", arr[i]);
        printf(" | ");
    }

    int in;
    printf("\nDesea ordener por:\n1. Asc\n2. Desc\n>");
    do{
        scanf("%i", &in);
        if(in!=1 && in!=2){
            printf("    *Elija 1 o 2\n");
        }
    }while(in!=1 && in!=2);

    switch(in){
        case 1:
            for(int i=0; i<10; i++){
                for(int j=0; j<10; j++){
                    if(arr[i]<arr[j]){
                        arr[11]=arr[i];
                        arr[i]=arr[j];
                        arr[j]=arr[11];
                    }
                }
            }
            break;
        case 2:
            for(int i=0; i<10; i++){
                for(int j=0; j<10; j++){
                    if(arr[i]>arr[j]){
                        arr[11]=arr[i];
                        arr[i]=arr[j];
                        arr[j]=arr[11];
                    }
                }
            }
            break;
    }
    printf("| ");
    for(int i=0; i<10; i++){
        printf("%c", arr[i]);
        printf(" | ");
    }
    printf("\nConstants: %i | %.0f%%\nVocales:   %i | %.0f%%", c, c/10.0*100, v, v/10.0*100);
    return 0;
}