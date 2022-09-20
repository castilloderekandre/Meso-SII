#include <stdio.h>
#include <time.h>
#include <array>

void printv(int arr[3][10], int j){
    for(int i=0; i<10; i++){
        printf("[%i] - ", arr[j][i]);
    }
    printf("\n");
}

int main(){
    int arr[3][10], p=0, n=0, pares=0, impares=0;
    srand(time(0));
    for(int i=0; i<10; i++){
        arr[0][i]=1+rand()%10;
        arr[1][i]=20+rand()%11;
        arr[2][i]=arr[1][i]-arr[0][i];
        switch(arr[2][i]%2){
            case 0:
                pares++;
                break;
            case 1:
                impares++;
                break;
        }
        switch(arr[2][i]>=0){
            case 0:
                n++;
                break;
            case 1:
                p++;
                break;
        }
    }
    for(int i=0; i<3; i++){
        printv(arr, i);
    }
    printf("Positivos: %i\nNegativos: %i\nPares: %i\nImpares: %i", p, n, pares, impares);

    return 0;
}