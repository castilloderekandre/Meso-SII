#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void order(char arr[]){
    int aSize=strlen(arr)-1;
    char buffer;
    for(int i=0; i<aSize; i++)
        for(int j=i+1; j<aSize; j++){
            if(arr[i]>arr[j]){
                buffer=arr[i];
                arr[i]=arr[j];
                arr[j]=buffer;
            }
        }
}

int charCount(char arr[], char c){
    int sum=0, aSize=strlen(arr)-1;
    for(int i=0; i<aSize; i++)
        if(toupper(arr[i])==c) sum++;
    return sum;
}

int main(){
    char inp[41], ABC[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    printf("S1: ");
    fgets(inp, 40, stdin);
    order(inp);
    printf("S2: %s", inp);
    int aSize=strlen(inp);
    for(int i=0; i<26; i++){
        int r=charCount(inp, ABC[i]);
        if(r)
            printf("S3: %c: %i\n", ABC[i], r);
    }
    return 0;
}