#include <stdlib.h>
#include <stdio.h>

//Returns factorial
long fi(int n){
    if(n==1){
        return 1;
    }
    return n*fi(n-1);
}

//Returns 'n' to power of 'e'
long p(int n, int e){
    if(e==1){
        return n;
    }
    return n*p(n, e-1);
}

int main(){
    int n, iter;
    printf("Ingrese el valor de X - Sen(X)\n>");
    scanf("%i", &n);
    do{
        printf("Ingrese cantidad de iteraciones (impar)\n>");
        scanf("%i", &iter);
        if(iter%2==0){
            printf("    *Ingrese un numero impar\n");
        }
    }while(iter%2==0);

    float senx=n;
    for(int i=0; i<iter-1; i++){
        senx+= p(n, 3+2*i) / (float)(fi(3+2*i)) * (i%2==0 ? -1 : 1);
    }
    printf("Aproximacion de Sen(X): %.4f", senx);
    return 0;
}