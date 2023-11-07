import java.util.Arrays;
import java.util.Vector;

class Student{
    public
    String Name;
    String Address;
    int Age;
    float Grade;
    Student()
    {
        Name="Ciuca";
        Address="Aiud";
        Age=30;
        Grade=10.5f;
    }
}
public class App {
    public static void main(String[] args) throws Exception {
       Vector<Student> V=new Vector<>();
       for(int i=9;i>=0;i--)
        {
            Student temp=new Student();
            temp.Name=temp.Name+(int)(Math.random()*10 +1);
            V.add(temp);
        }
        for(int i=0;i<10;i++)
        {
            for(int j=i+1;j<10;j++)
            {
                if((V.get(i).Name.compareTo(V.get(j).Name))>0)
                {
                    String temp=V.get(j).Name;
                    V.get(j).Name=V.get(i).Name;
                    V.get(i).Name=temp;
                }

            }
        }
        for(int i=0;i<10;i++)
        {
            System.out.println(V.get(i).Name);
        }
    }
}
