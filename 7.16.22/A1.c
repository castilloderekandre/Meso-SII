#include <stdio.h>

long fi(int n){
    if(n==1){
        return 1;
    }
    return n*fi(n-1);
}

int main(){
    int n;
    float e=1;
    printf("Ingrese cantidad de terminos\n>");
    scanf("%i", &n);
    for(int i=1; i<n; i++){
        e+=1/(float)(fi(i));
    }
    printf("%f", e);
    return 0;
}