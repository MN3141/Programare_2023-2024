
public class Person {
    String surname;
    String name;
    int telephoneNumber;
    public Person(String surname,String name,int telephoneNumber){
        this.surname=surname;
        this.name=name;
        this.telephoneNumber=telephoneNumber;
    }
    public int getTelephoneNumber()
    {
        return this.telephoneNumber;
    }
    public String getSurname(){return this.surname;}
    public String getName(){return  this.name;}

    @Override
    public String toString() {
        return this.name+" "+this.surname+" "+this.telephoneNumber;
    }
}
