public class Main {
    public static void main(String[] args) {
        byte x=10;
        System.out.print("TEST1 Afisare pe ecran:");
        System.out.println(x);
        System.out.println("=================================================");
        System.out.print("TEST2 Adunare cu tipuri diferite de variabila:");
        int y=1;
        y=x+y;//x=x+y nu merge
        System.out.println(y);//conversia se face mereu de la tipul mai mic la cel mare
        System.out.println("=================================================");
        System.out.print("TEST3 Lucru cu tablouri:");
        int v[]=new int[10];
        v[0]=1;//nu mai merge *(v+index)
        for(int i=0;i<10;i++) //indexarea tot de la 0 se face
            v[i]=i;
        for(int i=9;i>=0;i--)
            System.out.print(v[i]+ " ");// echivalent cu cout<<v[i]<<" ";
        System.out.println("");
        System.out.println("=================================================");
        System.out.print("TEST4:String:");
        String A="Conc";
        System.out.println(A+"atenare");
        A=A+"atenare";
        System.out.println(A.substring(0,5));//substring(inceput,capat+1)
        System.out.println("=================================================");
    }
}