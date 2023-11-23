package exercitii;
import machina.*;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.StringTokenizer;

//!!Pt titluri formate din mai multe cuvinte
//este necesara separarea lor prin '-' sau '_'
//spatiul este rezervat token-urilor
public class ex2 {
  public  ex2()
    {
        String str=null;
        Car masini[]=null;
        int indexMin=0;
        float minPrice=999999999f;
        StringTokenizer strToken=null;
        FileInputStream citireFisier=null;
        //================================================================
        //Citire din fisier
        try{
            citireFisier=new FileInputStream("garaj.txt");
        }
        catch (IOException e)
        {
            e.getMessage();
        }
        DataInputStream citire=new DataInputStream(citireFisier);
        try{
            int index=0;
            masini=new Car[ Integer.parseInt(citire.readLine())];
            while((str=citire.readLine())!=null)
            {
                String temp[]=new String[5];
                int i=0;
                //=============================================
                //parsare linie
                strToken=new StringTokenizer(str," ");
                while (strToken.hasMoreElements())
                {
                    temp[i]=strToken.nextToken();
                    i++;
                }
                masini[index]=new Car(temp[0],temp[1],Float.parseFloat(temp[2]),Float.parseFloat(temp[3]),Float.parseFloat(temp[4]));
                index++;
                //=============================================
            }
            citire.close();

        }
        catch (IOException e)
        {
            e.getMessage();
        }
        //=============================================
        for(int i=0;i<masini.length;i++)
        {
            if(minPrice>masini[i].getPrice())
            {
                indexMin=i;
                minPrice=masini[i].getPrice();
            }
        }
        System.out.println(masini[indexMin].getModel()+" "+masini[indexMin].getPrice());
    }
}