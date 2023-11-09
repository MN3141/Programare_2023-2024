import java.io.*;
public class Main {
    public static void main(String[] args) {
        File dir0=new File("DIRECTOR");
        if(dir0.exists()==false)
        {
            dir0.mkdir();
            System.out.println("Director creat.");
        }
        else
        {
            System.out.println(dir0.getName()+" exista deja.");
        }
        File fisier=new File(dir0.getAbsolutePath()+"\\lucru.txt");
       try{
           if(fisier.exists()==false)
           {
               fisier.createNewFile();
               System.out.println("Fisier creat.");
           }
           else{
               System.out.println(fisier.getName()+ " exista deja.");
           }

       }
       catch (IOException e)
       {
           System.out.println("Eroare in crearea fisierului!");
       }

    }
}