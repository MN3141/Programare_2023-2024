import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        //EX 1
        System.out.println("EX1:");
        System.out.println("======================================================================================:");
            String str=null;
            int varsta=0;
        DataInputStream cetire =new DataInputStream(System.in);
        System.out.println("Introduceti numele si varsta:");
        try{
            str=cetire.readLine();
            varsta=Integer.parseInt(cetire.readLine());
        }
        catch (IOException e)
        {
            e.getMessage();
        }
        System.out.println("Hello "+str+"!");
        if(varsta>100)
        {
            System.out.println("Esti batran!");
        }
        else
        {
            System.out.println("Esti tanar!");
        }
        //======================================================================================
        //EX 2
        System.out.println("EX2:");
        System.out.println("======================================================================================:");
        int num=0;
        String name[]=null;
        FileInputStream citireFisier=null;
        try{
            citireFisier=new FileInputStream("semigrupa.txt");
        }
        catch (IOException e)
        {
            e.getMessage();
        }
        cetire=new DataInputStream(citireFisier);
            try{
                int nr=Integer.parseInt(cetire.readLine());
                name=new String[nr];
                for(int i=0;i<nr;i++)
                {
                    name[i]=cetire.readLine();
                    name[i]=name[i].toUpperCase();
                }
            }
            catch (IOException e)
            {
                e.getMessage();
            }
        Arrays.sort(name);
            for(int i=0;i<name.length;i++)
                System.out.println(name[i]);
        //======================================================================================
    }
}