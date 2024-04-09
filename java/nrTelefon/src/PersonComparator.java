import java.util.Comparator;

public class PersonComparator implements Comparator<Person>
{
    public int compare(Person p0,Person p1)
    {
        int returnValue=0;
        if(p0.getSurname().compareToIgnoreCase(p1.getSurname())<0)
            returnValue=-1;
        else if(p0.getSurname().compareToIgnoreCase(p1.getSurname())==0)
            {
                if(p0.getName().compareToIgnoreCase(p1.getName())<0)
                    returnValue=-1;
                else
                    returnValue=1;
            }
        return returnValue;
    }
}