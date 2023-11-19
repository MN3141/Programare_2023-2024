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
        File test=new File("C:\\Arhiva_ULBS\\Proiecte\\Anul_II\\programare_2023-2024\\java\\test_FILE");
       if(test.isDirectory()==true)
           System.out.println(test.getName()+" este director.");
       else System.out.println(test.getName()+" este fisier.");
    }
}