import java.io.IOException;
import java.util.Scanner;

//Problema 5
public class E {
    public static void main(String[] args) throws IOException {
        int in=1; float[] pairs = new float[4];
        Scanner input = new Scanner(System.in);
        while(in!=0){
            System.out.print("Ingrese un numero positivo: ");
            in=input.nextInt();
            if(in>0){
                if(in%2==0) {
                    pairs[0]++;
                    pairs[1]+=in;
                }else{
                    pairs[2]++;
                    pairs[3]+=in;
                }
            }else{
                System.out.println("\n*Ingrese un numero positivo*");
            }
        }
        System.out.print("% de pares: "   + (pairs[0] * 100 / (pairs[0] + pairs[2])) + 
                       "\n% de impares: " + (pairs[2] * 100 / (pairs[0] + pairs[2])) +
                       "\nSuma de pares: "  + pairs[1] +
                       "\nSuma de impares: " + pairs[3] + 
                       "\nSuma total: " + (pairs[1] + pairs[3]));
        input.close();
    }
}
