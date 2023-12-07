//OBS:Exista exceptii de tip checked si unchecked
//Erorile de tip checked necesita musai un bloc de tip try catch pt a compila codul(ex:citire date)
//Erorile de tip unchecked nu necesita acel bloc
class ExceptieSemn extends Exception{
    ExceptieSemn(String msg)
    {
        super(msg); //.getMessage() returneaza membrul mesaj din clasa Exceptie
    }
}
class Num{
    int x;
    public Num()
    {this.x=0;}
    public Num(int x) throws ExceptieSemn
    {
        if(x<0)  throw new ExceptieSemn("Nu ai voie nr negative,amigo!");
        this.x=x;}
    public void getNum()
    {
        System.out.println(this.x);
    }
    public void setNum(int value)
    {
        this.x=value;
    }

}
public class Main {
    public static void main(String[] args) {
        Num x=null;
        try{
            x=new Num(-1);
        }
        catch (ExceptieSemn e)
        {
            System.out.println(e.getMessage());
        }
    }
}