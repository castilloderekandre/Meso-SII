#include <stdio.h>
#include <time.h>

int main(){
    srand(time(0));
    int m=1, v=0, c=0, n=0, s=0;
    char in[5][5], vowels[2][5]={"AEIOU", "aeiou"}, consonants[2][21]={"BCDFGHJKLMNPQRSTVWXYZ", "bcdfghjklmnpqrstvwxyz"}, nums[]="0123456789", symbols[]="!@#$\%^&*";
    printf("Elija si los caracteres alfanumeros son mayuscula o miniscula\n1. Mayuscula\n2. Miniscula\n>");
    scanf("%i", &m);
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            //Initializing array with random alphanumeric characters
            switch((rand()%3)+1){
                case 1:
                    in[i][j]=(char)((rand()%26)+(m==1? 65 : 97));
                    break;
                case 2:
                    in[i][j]=(char)((rand()%10)+48);
                    break;
                case 3:
                    in[i][j]=symbols[rand()%8];
                    break;
            }
            //Printing array
            printf("%c", in[i][j]);

            //Count for vowels, consonants & nums
            for(int k=0; k<5; k++){
                if(in[i][j] == vowels[m-1][k]){
                    v++;
                }
            }
            for(int k=0; k<21; k++){
                if(in[i][j] == consonants[m-1][k]){
                    c++;
                }
            }
            for(int k=0; k<10; k++){
                if(in[i][j] == nums[k]){
                    n++;
                }
            }
            for(int k=0; k<8; k++){
                if(in[i][j] == symbols[k]){
                    s++;
                }
            }
        }
        printf("\n");
    }
    printf("Vocales: %i\nConsonantes: %i\nDigitos: %i\nSimbolos: %i", v, c, n, s);
    return 0;
}