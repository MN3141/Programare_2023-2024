package huffman;
public class huffCode {
    char symbol;
    String sequence="";
    int key;
    public huffCode(char symbol,int key)
    {this.symbol=symbol;
        this.key=key;
     }
     public  huffCode(char symbol,String st)
     {
         this.symbol=symbol;
         this.sequence=st;
     }
    public void setSequence(String st)
    {
        this.sequence=st;
    }
    public char getSymbol()
    {
        return this.symbol;
    }
    public String getSequence()
    {
        return this.sequence;
    }

}