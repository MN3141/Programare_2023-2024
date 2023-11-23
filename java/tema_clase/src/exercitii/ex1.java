package exercitii;
import library.LibraryCard;
import java.io.*;
import java.util.StringTokenizer;
//!!Pt titluri formate din mai multe cuvinte
//este necesara separarea lor prin '-' sau '_'
//spatiul este rezervat token-urilor
public  class ex1 {
       public ex1()
        {
            String str=null;
            LibraryCard cartele[]=null;
            int indexMax=0;
            int maxCopies=0;
            StringTokenizer strToken=null;
            FileInputStream citireFisier=null;
            //================================================================
            //Citire din fisier
            try{
                citireFisier=new FileInputStream("biblioteca.txt");
            }
            catch (IOException e)
            {
                e.getMessage();
            }
            DataInputStream citire=new DataInputStream(citireFisier);
            try{
                int index=0;
                cartele=new LibraryCard[ Integer.parseInt(citire.readLine())];
                while((str=citire.readLine())!=null)
                {
                    String temp[]=new String[4];
                    int i=0;
                    //=============================================
                    //parsare linie
                    strToken=new StringTokenizer(str," ");
                    while (strToken.hasMoreElements())
                    {
                        temp[i]=strToken.nextToken();
                        i++;
                    }
                    cartele[index]=new LibraryCard(temp[0],temp[1],temp[2],Integer.parseInt(temp[3]));
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
            for(int i=0;i<cartele.length;i++)
            {
                if(maxCopies<cartele[i].getCopies())
                {
                    maxCopies=cartele[i].getCopies();
                    indexMax=i;
                }
            }
            System.out.println(cartele[indexMax].getTitle()+" "+cartele[indexMax].getCopies());

        }
        }