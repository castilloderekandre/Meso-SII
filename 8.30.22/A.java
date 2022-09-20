import java.io.IOException;
import java.util.Scanner;

//Problema 1
public class A {
    public static void main(String[] args) throws IOException{
        int x, y, sum=0;
        Scanner input = new Scanner(System.in);

        System.out.print("Ingrese un numero inicial: ");
        x = input.nextInt();
        System.out.print("Ingrese un numero final: ");
        y = input.nextInt();

        for(int i=x; i<=y; i++){
            System.out.print(i);
            if(i<y) System.out.print(" - ");
            sum+=i;
        }
        System.out.println("\nSuma: " + sum);
        input.close();
    }
}
