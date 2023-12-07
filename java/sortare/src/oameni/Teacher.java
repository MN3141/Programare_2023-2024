package oameni;

import java.util.Comparator;
import java.util.TreeMap;

public class Teacher extends Person implements socoteli{
    int nrCursuri;
    int vechime;
    public Teacher()
    {
        super();
        this.nrCursuri=0;
        this.vechime=0;
    }
    public Teacher(String name,String address,int age,int nr,int ani)
    {
        super(name,address,age);
        this.nrCursuri=nr;
        this.vechime=ani;
    }

    public float computeSalary() {
        return (this.nrCursuri+this.vechime)*10+100;
    }
    public int getVechime()
    {
        return this.vechime;
    }
    public String getName()
    {
        return this.name;
    }
}