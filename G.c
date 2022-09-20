#include <stdio.h>
#include <stdlib.h>

char totito[3][3];

int lineas(){
    //Revisamos horizontal
    int sumaX=0, sumaO=0;
    for(int columnas=0; columnas<3; columnas++){
        sumaX=0; sumaO=0;
        for(int filas=0; filas<3; filas++){
            if(totito[columnas][filas]=='X') sumaX++;
            if(totito[columnas][filas]=='O') sumaO++;
            if(sumaX==3) return 1;
            if(sumaO==3) return 2;
        }
    }
    //Revisamos vertical
    sumaX=0; sumaO=0;
    for(int filas=0; filas<3; filas++){
        sumaX=0; sumaO=0;
        for(int columnas=0; columnas<3; columnas++){
            if(totito[columnas][filas]=='X') sumaX++;
            if(totito[columnas][filas]=='O') sumaO++;
            if(sumaX==3) return 1;
            if(sumaO==3) return 2;
        }
    }

    return 0;
}


int main(){
    int estatus=lineas();
    if(estatus==1){
        printf("Gano jugador 1")
    }
    else if(estatus==2){
        printf("Gano computador")
    }
    else{
        printf("Empate")
    }
    return 0;
}