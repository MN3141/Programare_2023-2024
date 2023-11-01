import java.io.DataInput;
import java.io.DataInputStream;
import java.io.IOException;

class Num{
    private
    int nr;
    public
    Num()
    {
        nr=0;
    }
    Num(int x)
    {
        nr=x;
    }
    void setNum(int x)
    {
        nr=x;
    }
    int numDigits()
    {
        int digits=0;
        int temp=nr;
        while(temp!=0)
        {
            digits++;
            temp=temp/10;
        }
        if(digits==0)
            digits++;
        return digits;
    }
}
public class Main {
    public static void main(String[] args) {
            Num x=new Num();
            String str="";
            int nr=0;
            System.out.println("Introducere nr intreg:");
        DataInputStream cetire=new DataInputStream(System.in);
        while (true)
        {
            try{
                str=cetire.readLine();
                nr=Integer.parseInt(str);
                x.setNum(nr);
                break;
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }

            catch (NumberFormatException nfe)
            {
                System.out.println("Nu ai citit nr intreg,amigo!");
            }
        }
        System.out.println("Nr citit are "+x.numDigits()+" cifre.");
        }
        }
