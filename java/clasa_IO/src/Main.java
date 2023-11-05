import java.io.*;

class InputOutput {

    String bufferConsole;
    public
    InputOutput()
    {
        bufferConsole=null;
    }
    String readConsole()
    {
        DataInputStream citire=new DataInputStream(System.in);
        try{

            bufferConsole=citire.readLine();

        }
        catch (IOException e)
        {
            e.getMessage();
        }
        return bufferConsole;
    }
    void readFile(String [] s,String fileName)
    {
        FileInputStream fin=null;
        DataInputStream citire=null;
        try{
            fin=new FileInputStream(fileName);
        }
        catch (FileNotFoundException e)
        {
            e.getMessage();
        }
        citire=new DataInputStream(fin);
        try {
            int n=Integer.parseInt(citire.readLine());
           for(int i=0;i<n;i++)
           {
               s[i]=citire.readLine();
           }
            citire.close();
        }
        catch (IOException e)
        {
            e.getMessage();
        }

    }
    void writeFile(int value,String fileName)
    {
        try{
            FileOutputStream fout=new FileOutputStream(fileName);
            DataOutputStream scriere=new DataOutputStream(fout);
            scriere.write(value); //OBS:.write() suprascrie ce este in fisier
        }
        catch (IOException e)
        {
            e.getMessage();
        }
    }
}
public class Main {
    public static void main(String[] args) {
        InputOutput io = new InputOutput();
        String[] s =new String[100];
        io.readFile(s,"fisier.txt");
        int i=0;
        while(s[i]!=null)
        {
            System.out.println(s[i]);
            i++;
        }
    }
}