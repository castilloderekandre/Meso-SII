import java.io.*;
import java.util.*;
import java.lang.*;

public class C_Cuadro {
    public static int loop(int n, int limit){
        if(n>=limit) n=n%limit;
        else if(n<0) n=(limit-Math.abs(n)%limit)%limit;
        return n;
    }

    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(System.in);
        int in;
        do{
            System.out.print("Ingrese un numero impar entre 3 a 11: ");
            in = input.nextInt();
        }while((in<3 || in>11) || in%2==0);
        int ex=(int)Math.pow(in, 2);
        int x=in/2, y=0;
        int[][] arr = new int[in][in];
        for(int i=0; i<ex; i++){
            arr[y][x]=i+1;
            y=loop(--y, in); x=loop(++x, in);
            if(arr[y][x]!=0) {y=loop(y+2, in); x=loop(--x, in);}
        }
        char[] horizontaldividerc = new char[(Integer.toString(ex).length()+3)*in+1];
        Arrays.fill(horizontaldividerc, '-');
        String horizontaldivider = new String(horizontaldividerc);
        System.out.println(horizontaldivider);
        for(int i=0; i<in; i++){
            System.out.print("| ");
            for(int j=0; j<in; j++){
                char[] repeat = new char[Integer.toString(ex).length() - Integer.toString(arr[i][j]).length()];
                Arrays.fill(repeat, ' ');
                String str = new String(repeat);
                System.out.print(arr[i][j] + str +" | ");
            }
            System.out.println("\n" + horizontaldivider);
        }
        input.close();
    }
}
