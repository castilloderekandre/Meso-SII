#include <stdio.h>
#include <time.h>

char UPPER(char c){
    return c-(97-65);
}

int main(){
    srand(time(0));
    int v=0, c=0, n=0, s=0;
    char in[20], vowels[]="aeiou", consonants[]="bcdfghjklmnpqrstvwxyz", nums[]="0123456789", symbols[]="!@#$%^&*";
    for(int i=0; i<20; i++){
        switch((rand()%3)+1){
            case 1:
                in[i]=(char)((rand()%26)+97);
                break;
            case 2:
                in[i]=(char)((rand()%10)+48);
                break;
            case 3:
                in[i]=symbols[rand()%8];
                break;
        }

        for(int j=0; j<5; j++){
            if(in[i] == vowels[j]){
                v++;
            }
        }
        for(int j=0; j<21; j++){
            if(in[i] == consonants[j]){
                c++;
            }
        }
        for(int j=0; j<10; j++){
            if(in[i] == nums[j]){
                n++;
            }
        }
        for(int j=0; j<8; j++){
            if(in[i] == symbols[j]){
                s++;
            }
        }
    }
    printf("%s\n", in);
    printf("Vocales: %i\nConsonantes: %i\nDigitos: %i\nSimbolos: %i", v, c, n, s);
}