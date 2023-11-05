abstract class FiguraGeometrica{
   public abstract float arie(); //doar declaram metoda,nu o definim
}
class Patrat extends  FiguraGeometrica{
    float latura;
    public
    Patrat()
    {
        latura=1;
    }
    Patrat(float num)
    {
        latura=num;
    }

  public float arie()
    {
        return latura*latura;
    }
}
class Cerc extends FiguraGeometrica{
    float raza;
    public
    Cerc()
    {
        raza=1;

    }
    Cerc(float num)
    {
        raza=num;
    }
    public float arie()
    {
        return (float)(Math.PI*raza*raza);
    }
}
public class Main {
    public static void main(String[] args) {
        Patrat q=new Patrat(2);
        Cerc c=new Cerc(2.1f);
        System.out.println(q.arie());
        System.out.println(c.arie());
    }
}