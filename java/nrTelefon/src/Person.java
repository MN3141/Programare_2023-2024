
public class Person {
    String surname;
    String name;
    String telephoneNumber;
    public Person(String surname,String name,String telephoneNumber){
        this.surname=surname;
        this.name=name;
        this.telephoneNumber=telephoneNumber;
    }
    public String getTelephoneNumber()
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
