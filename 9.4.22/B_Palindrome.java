import java.io.IOException;
import java.util.Scanner;

public class B_Palindrome {
    static String abc="abcdefghijklmnopqrstuvwxyz", tildeVowels="áéíúó", normalVowels="aeiuo";
    public static boolean checkPalindrome(String str){
        str=str.toLowerCase();
        for(int i=0; i<tildeVowels.length(); i++){
            str = str.replaceAll(Character.toString(tildeVowels.charAt(i)), Character.toString(normalVowels.charAt(i)));
        }
        for(int j=0; j<str.length(); j++){
            Boolean inordinary=false;
            for(int i=0; i<abc.length(); i++){
                if(str.charAt(j)==abc.charAt(i)){
                    inordinary=true;
                    break;
                }
            }
            if(!inordinary) str = str.replaceAll(Character.toString(str.charAt(j)), "");
        }
        StringBuilder inverse = new StringBuilder(str);
        inverse.reverse();
        return str.equals(inverse.toString());
    }
    
    public static void main(String[] arg) throws IOException {
        Scanner input = new Scanner(System.in);
        String in;
        do{
            in = input.nextLine();
            if(checkPalindrome(in))
                System.out.println("Es un palindromo");
            else
                System.out.println("No es un palindromo");
        }while(!in.equals("\n"));
        input.close();
    }
}
