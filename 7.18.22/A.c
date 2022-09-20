#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <string.h>

int nL(int n){
    int l=1;
    while((int)(n/10.0)>0){
        n=(int)(n/10.0);
        l++;
    }
    return l;
}

void rc(char c, int n){
    for(int i=0; i<n; i++){
        printf("%c", c);
    }
}

int main(){
    int arr[11];
    srand(time(0));
    printf("| ");
    for(int i=0; i<10; i++){
        arr[i]=rand()%101;
        printf("%i", arr[i]);
        rc(' ', nL(arr[9]) - nL(arr[i]));
        printf(" | ");
    }
    printf("\n");
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(arr[i]<arr[j]){
                arr[11]=arr[i];
                arr[i]=arr[j];
                arr[j]=arr[11];
            }
        }
    }
    printf("| ");
    for(int i=0; i<10; i++){
        printf("%i", arr[i]);
        rc(' ', nL(arr[9]) - nL(arr[i]));
        printf(" | ");
    }
    return 0;
}