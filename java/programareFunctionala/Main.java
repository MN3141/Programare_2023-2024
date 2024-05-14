import java.util.ArrayList;
import java.util.List;
public class Main {
    //functie pura=functie anonima ~=functie lambda
    //in Java Stream reprezinta o interfata
    //pt blocuri de decizie vezi Strategy pattern
    public static List<Integer> testSelect(ArrayList<Integer>v)
    {
        //select elements(filter out) that are greater than 5
        /*
            List<Integer> output =new ArrayList<Integer>();
            for(int i=0;i<v.length;i++)
                {
                    if(v.get(i)>5)
                        output.add(v.get(i));
                }
         */
        List<Integer> output=v.stream().filter((x)->x>5).toList();
        //((x)->x>5) expresie lambda

        return output;
    }
    public static boolean isEven(int x)
    {
        return (x%2==0);
    }
    public static List<Integer> testSelect2(ArrayList<Integer>v)
    {
        List<Integer> output=v.stream().filter((param)->isEven(param)).toList();
        //in cadrul filter am putut trece pointer la o functie definita anterior
        
        return output;
    }
    public static List<Integer> testMapping(ArrayList<Integer> v)
    {
        /*
         List<Integer> output =new ArrayList<Integer>();
         for(int i=0;i<v.length;i++)
            output.add(v.get(i)*v.get(i));
         */
        List<Integer> output=v.stream().map((param)->param*param).toList();
        return output;
    }
    public static int testSum(List<Integer> list)
    {
        int output=list.stream().reduce((x0,x1)->x0+x1).get();
        return output;
    }
    public static void main(String[] args) {
        System.out.println("Test programare functionala");
        ArrayList<Integer> list=new ArrayList<>();
        list.add(2);
        list.add(-1);
        list.add(20);
        list.add(-2);
        System.out.println(testSelect(list));
        System.out.println(testSelect2(list));
        System.out.println(testMapping(list));
        System.out.println(testSum(list));
    }
}
