#include <iostream>
#include <cmath>
using namespace std;

//c - "coordinate"; x or y | n - number to add/subtract | size - (root) size of array
//Loops a number back around if it reaches it's limit: 3->1
int looped(int c, int n, int size){
    if(c+n < 0){
        c=size-1;
        c+=n+1;
    }
    else if(c+n > size-1){
        c=0;
        c+=n-1;
    }
    else{
        c+=n;
    }
    return c;
}

//Returns number of digits in 'n'
int nL(int n){
    int l=1;
    while((int)(n/10.0)>0){
        n=(int)(n/10.0);
        l++;
    }
    return l;
}

int main(){
    //as - array (root) size | ap - array potential
    int as, ap; bool valid=true;
    cout<<"Elija un numero impar entre 3 y 11 (limites inclusivos)\n>"; 
    do{
        if(!valid){
            cout<<"Elija un numero dentro de estos parametros:\n    *Impar\n    *Entre 3 y 11 (limites inclusivos)\n>";
        }
        cin>>as;
        if(as>=3 && as<=11 && as%2>0){
            valid=true;
        }else{
            valid=false;
        }
    }while(!valid);

    //declares array of user-defined size. Declares array "potential" (how many elements it has). Fills array with zeros
    int arr[as][as];
    ap = pow(as, 2);
    for(int i=0; i<as; i++){
        for(int j=0; j<as; j++){
            arr[i][j]=0;
        }
    }
    int breaker=1, x=floor(as/2.0), y=0;
    while(breaker<=ap){
        if(arr[y][x]==0){
            arr[y][x]=breaker;
            x=looped(x, 1, as);
            y=looped(y, -1, as);
            breaker++;
        }else{
            //Sets coordinates below previous num
            x=looped(x, -1, as);
            y=looped(y, 2, as); 
        }
    }

    //Row length sum
    int rLS=1;
    for(int i=0; i<as; i++){
        //Sum of "string" length. +3: initial 1w space to left and right, and '|'
         rLS+=nL(arr[0][i]) + nL(ap) - nL(arr[0][i]) + 3;
    }
    
    cout<<endl<<string(rLS, '-')<<endl;
    for(int i=0; i<as; i++){
        cout<<"|";
        for(int j=0; j<as; j++){
            //Left space. nL(ap) +2: initial 1w space to left and right
            
            int d_ap=nL(ap), d_arr=nL(arr[i][j]), lS=floor((d_ap+2)/2.0)-floor(d_arr/2.0)-(d_ap%2==0 && d_arr%2==1);
            cout<<string(lS, ' ');
            //Num + right space. +2: initial 1w space to left and right
            cout<<arr[i][j]<<string(d_ap+2-lS-d_arr, ' ')<<"|";
        }
        cout<<endl<<string(rLS, '-')<<endl;
    }
    return 0;
}