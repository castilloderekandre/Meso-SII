import java.io.IOException;

//Problema 3
public class C {
    public static void main(String[] args) throws IOException {
        int[] sumas = new int[4];
        for(int i=50; i<=100; i++){
            System.out.println(i);
            sumas[0]=0;
            System.out.print(1);
            for(int j=2; j<i; j++)
                if(i%j==0) {sumas[0]+=j; System.out.print(" - " + j);}
                 if(sumas[0]<i)  sumas[1]++;
            else if(sumas[0]==i) sumas[2]++;
            else if(sumas[0]>i)  sumas[3]++;
            System.out.println("\nSuma: " + sumas[0] + "\n------------");
        }
        System.out.println("Deficientes: " + sumas[1] + "\nExactos: " + sumas[2] + "\nAbudantes: " + sumas[3]);
    }
}
