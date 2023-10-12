import java.lang.Math;
class Complex{
    int a;  //nu merge int a,b;
    int b;
    void Init()
    {
        a=0;
        b=0;
    }
    int Re()
    {
      return a;
    }
    int Im()
    {
        return b;
    }
    double modulus()
    {
        double rez=a*a+b*b;
        return Math.sqrt(rez);
    }
    Complex sum(Complex z0,Complex z1)
    {
        Complex z2=new Complex();
        z2.a=z0.a+z1.a;
        z2.b=z0.b+z1.b;
        return z2;
    }
    Complex product(Complex z0,Complex z1)
    {
        Complex z2=new Complex();
        z2.a=z0.a*z1.a-z0.b*z1.b;
        z2.b=z0.a*z1.b+z0.b*z1.a;
        return z2;
    }
}
public class Main {
    public static void main(String[] args) {
    Complex z=new Complex();
    z.Init();
    }
}