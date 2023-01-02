import java.io.IOException;
import java.util.Scanner;
import java.lang.Math;

public class A_e {
    public static int CalcF(int x){
        if(x==1) return 1;
        return x*CalcF(x-1);
    }

    public static float CalcE(int x, int n){
        float sum=1+x;
        for(int i=2; i<=n; i++){
            sum+=Math.pow(x, 1+i)/(float)CalcF(1+i);
        }
        return sum;
    }
    public static void main(String[] arg) throws IOException {
        int n;
        Scanner input = new Scanner(System.in);
        System.out.print("Ingese N: ");
        n = input.nextInt();
        for(int x=1; x<=100; x++)
            System.out.println("e elevado a " + x + ": " + CalcE(x, n));
        input.close();
    }   
}
