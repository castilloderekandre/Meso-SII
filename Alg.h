#include <string.h>

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
