import java.io.IOException;
import java.util.Random;

/*
 * Generar un vector[20] de 20 numeros aleatorios donde la suma de los primeros 10 
 * siempre sea mayor a los ultimos 10
 */

 public class D_Vector{
    public static void order(int[] arr){
        int buffer;
        for(int i=0; i<arr.length; i++){
            for(int j=0; j<arr.length; j++){
                if(arr[i]>arr[j]){
                    buffer=arr[i];
                    arr[i]=arr[j];
                    arr[j]=buffer;
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        int[] arr = new int[20], sum = new int[2];
        Random r = new Random();
        for(int i=0; i<arr.length; i++){
            arr[i]= r.nextInt(20);
            System.out.print(arr[i] + (i!=arr.length/2-1 ? " - " : " | "));
        }
        System.out.println();
        order(arr);
        for(int i=0; i<arr.length; i++){
            System.out.print(arr[i] + (i!=arr.length/2-1 ? " - " : " | "));
            if(i<arr.length/2) sum[0]+=arr[i];
            if(i>=arr.length/2) sum[1]+=arr[i];
        }
        System.out.print("\nSuma de primeros 10: " + sum[0] + "\nSuma de ultimos 10: " + sum[1]);
    }
 }