//1
//Sa se scrie un program in C/C++ care primeste de la tastatura doua numere a si b si  genereaza un nou numar format
// din cifrele rezultate in urma aplicarii mediei artimetice pe cifrele numerelor a si b (partea intreaga).
// Extra: Dupa citirea celor doua numere verificati daca ele au acelasi numar de cifre
// si afisati un mesaj in caz contrar (a si b trebuie sa aiba aceeasi lungime).
//=====================================================================================================================
public class Main {
    static int nr_Cif(int x)
    {
        int k=0;
        while(x>0)
        {
            x=x/10;
            k++;
        }
        return k;
    }
    static void to_Array(int x,int[] v,int size)
    {
        for(int i=size-1;i>=0;i--)
        {
            v[i]=x%10;
            x=x/10;
        }
    }
    static void print_Array(int[] v,int size)
    {
        for(int i=0;i<size;i++)
            System.out.print(v[i]);
        System.out.println("");
    }
    static void ex1(int a,int b)
    {
        if(nr_Cif(a)!=nr_Cif(b))
            System.out.println("a si b trebuie sa aiba aceeasi lungime!");
        else {
            int  nr_cif=nr_Cif(a);
            int v[]=new int[nr_cif];
            int w[]=new int[nr_cif];
            int u[]=new int[nr_cif];
            to_Array(a,v,nr_cif);
            to_Array(b,w,nr_cif);
            for(int i=0;i<nr_cif;i++)
            {
                u[i]=(w[i]+v[i])/2;
            }
           print_Array(u,u.length);
        }
        System.out.println("");
    }
    static int unique(int v[])
    {
        int n=v.length;
        int l=0;
        for(int i=0;i<n;i++)
        {
            boolean deplasat=false;
            for(int j=i+1;j<n;j++)
            {
                if(v[i]==v[j])
                {
                    for(int k=j+1;k<n;k++)
                       v[k]=v[k-1];
                    l++;
                }
            }
        }
        return n-l;
    }
    public static void main(String[] args) {
        int a=1234,b=8473;
        ex1(a,b);
    }
}