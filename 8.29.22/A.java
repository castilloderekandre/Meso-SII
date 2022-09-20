import java.io.IOException;

//Factorial
class A{
    public static void main(String[] args) throws IOException{
        int s_impares=0,deficientes=0, abundantes=0, exactos=0;
         for(int i=50;i<=150;i++)
         {
             if(i%2==1)s_impares++;
             
             int s_divisores=0;
         
                for(int k=1;k<i;k++)
                {
                     if(i%k==0){ 
                        s_divisores+=k;
                     System.out.println(k);
                     }
                }
                if(s_divisores<i)
                {
                    System.out.println("\n"+i+"\t Es un número deficiente");      
                    deficientes++;
                }
                if(s_divisores==i)
                {
                    System.out.println("\n"+i+"\t Es un número exacto/perfecto");      
                    exactos++;
                }
                if(s_divisores>i)
                {
                    System.out.println("\n"+i+"\t Es un número abundante");      
                    abundantes++;
                }
         }
         System.out.println("\n Suma de impares \t"+s_impares);
         System.out.println("\n Numeros deficientes \t"+deficientes);
         System.out.println("\n Numeros exactos \t"+exactos);
         System.out.println("\n Numeros abundantes \t"+abundantes);
    }
}