import java.io.IOException;
import java.util.Scanner;

//Problema 4
public class D {
    public static void main(String[] args) throws IOException {
        String password = "123";
        Scanner input = new Scanner(System.in);
        while(true){
            System.out.print("Ingese la clave: ");
            if(input.nextLine().equals(password)) break;
            System.out.println("Clave incorrecta");
        }
        input.close();
        System.out.println("Clave correcta");
    }
}
