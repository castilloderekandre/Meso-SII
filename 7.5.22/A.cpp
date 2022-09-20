#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cout<<"Ingrese cantidad de terminos\n>"; cin>>n;
    float product=2;
    for(int i=1; i<n; i++){
        product*=(i+(i%2>0))/(1.0+(i-1+((i-1)%2>0)));
        cout<<(i+(i%2>0))<<"/"<<(1.0+(i-1+((i-1)%2>0)))<<endl;
    }
    cout<<product;
    return 0;
}