import java.io.IOException;
import java.util.Scanner;
import java.lang.Math;

public class A_e {
    public static int CalcF(int x){
        if(x==1) return 1;
        return x*CalcF(x-1);
    }

    public static float CalcE(int x){
        float sum=1+x;
        for(int i=1; i<=100; i++){
            sum+=Math.pow(x, 1+i)/(float)CalcF(1+i);
        }
        return sum;
    }
    public static void main(String[] arg) throws IOException {
        float in;
        Scanner input = new Scanner(System.in);
        System.out.print("Ingrese un numero: ");
        in = input.nextFloat();
        System.out.print("e elevado a " + in + ": " + CalcE((int)in));
        input.close();
    }   
}
