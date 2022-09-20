import java.io.IOException;
import java.util.Scanner;

public class E_Senx {
    public static long calcF(int x){
        if(x==1) return 1;
        return x*calcF(x-1);
    }
    
    public static float senx(int x, int n){
        if(n<=0) return 0;
        float sum=x;
        for(int i=0; i<n-1; i++){
            sum+=(Math.pow(x, 3+i)/calcF(3)) * (i%2==0 ? -1 : 1);
        }
        return sum;
    }
    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(System.in);
        System.out.print("Ingese X: ");
        int x = input.nextInt();
        System.out.print("Ingrese N: ");
        int n = input.nextInt();
        System.out.print("Sen("+x+"): " + senx(x, n));
    }
}