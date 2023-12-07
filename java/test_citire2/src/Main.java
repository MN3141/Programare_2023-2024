import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

public class Main {
    public static void main(String[] args) {
    String str=null;
    String str2=null;
    int x=0;
    FileInputStream fin=null;
        try{
            fin=new FileInputStream("test2.txt");//fisierul nr trb pus in src!!
        }
        catch (FileNotFoundException e)
        {
            e.getMessage();
        }
        DataInputStream citire=new DataInputStream(fin);
       try{
           while((str=citire.readLine())!=null)
           {
System.out.println(str);
           }
           //citire.close(); //merge si fara metoda .close()
           //System.in.read();//echivalent cu getch() din C
       }
       catch (IOException e)
       {
           e.getMessage();
       }
    }
}