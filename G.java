import java.io.IOException;
import java.util.Random;
import java.util.Scanner;

public class G {
    
    public static int regresar(int x){
        if(x>numero-1)
        {
            x=0;
        }
        else if(x<0)
        {
            x=numero-1;
            Random
        }
        return x;
    }
    
    public static int exponenciacion(int x, int y){
        if(x==0) 
            return 1;
        if(x<0) 
            return 0;
        for(int i=0; i<y-1; i++)
            x*=x;
        return x;
    }

    static int numero=4;

    public static void main(String[] args) throws IOException {
        Scanner ingreso = new Scanner(System.in);
        while(numero%2==0 || !(numero>=3 && numero<=11))
        {
            System.out.println("Escriba un numero para el cuadro magico: ");
            numero = ingreso.nextInt();
        }
        ingreso.close();
        int maximo=exponenciacion(numero, 2);
        int columna=numero/2;
        int fila=0;
        int[][] cuadromagico = new int[numero][numero];

        for(int i=1; i<=maximo; i++)
        {
            cuadromagico[fila][columna]=i;
            fila=fila-1;
            columna=columna+1;
            fila=regresar(fila);
            columna=regresar(columna);
            if(cuadromagico[fila][columna]>=1)
            {
                fila=fila+1;
                fila=regresar(fila);
                fila=fila+1;
                fila=regresar(fila); 
                columna=columna-1;
                columna=regresar(columna);
            }
        }

        for(int i=0; i<numero; i++)
        {
            System.out.print("\n");
            for(int j=0; j<numero; j++)
            {
                System.out.print(cuadromagico[i][j] + " ");
            }
        }
    }
}
