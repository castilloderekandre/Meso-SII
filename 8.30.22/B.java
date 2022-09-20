import java.io.IOException;

//Problema 2
public class B {
    public static void main(String[] args) throws IOException{
        for(int i=1; i<=100; i++){
            int factors=2;
            for(int j=2; j<i; j++)
                if(i%j==0) {factors++; break;}
            if(factors==2) System.out.print(i + " - ");
        }
    }
}
