class Util{
    public static void Print(int array[])
    {
        for(int i=0;i< array.length;i++)
            System.out.print(array[i]+" ");
        System.out.println();
    }
    public static void selectSort(int array[])
    {
        for(int i=0;i< array.length-1;i++)
        {
            for(int j=i+1;j< array.length;j++)
            {
                if(array[i]>array[j])
                {
                    int temp=array[i];
                    array[i]=array[j];
                    array[j]=temp;
                }
            }
        }
    }
    public static void bubbleSort(int array[])
    {
        boolean sorted=false;
        int n= array.length;
        while(!sorted)
        {
            sorted=true;
            for(int i=0;i<n-1;i++)
            {
                if(array[i]>array[i+1])
                {
                    int temp=array[i];
                    array[i]=array[i+1];
                    array[i+1]=temp;
                    sorted=false;
                }
            }
            n--;
        }
    }
    public static void quickSort(int array[],int first,int last)
    {
        int i=first;
        int j=last;
        int pivot=array[first];
        while(i<j)
        {
            while (array[i]<pivot)
                i++;
            while (array[j]>pivot)
                j--;
            if(i<j)
            {
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
            if(i<=j)
            {
                i++;
                j--;
            }
        }
        if(first<j)
            quickSort(array,first,j);
        if(i<last)
            quickSort(array,i,last);
    }
    private static void merge(int array[],int first,int pivot,int last)
    {
        int k=first;
        int i=first;
        int j=pivot+1;
        int tempArray[]=new int[array.length];
        while((i<=pivot) && (j<=last))
        {
            if(array[i]<array[j])
            {
                tempArray[k]=array[i];
                k++;
                j++;
            }
            else {
                tempArray[k]=array[j];
                k++;
                j++;
            }
        }
            if(j>last)
            {
                for(j=i;j<pivot;j++)
                {
                    tempArray[k]=array[j];
                    k++;
                }
            }
            if(i>pivot)
            {
                for(i=j;i<last;i++)
                {
                    tempArray[k]=array[i];
                    k++;
                }
            }
        for(i=first;i<last;i++)
            array[i]=tempArray[i];
    }
    public static void mergeSort(int array[],int first,int last) //de depanat
    {
        int pivot=0;
        if(first<last)
        {
            pivot=(first+last)/2;
            mergeSort(array,first,pivot);
            mergeSort(array,pivot+1,last);
            merge(array,first,pivot,last);
        }
    }
}
public class Main {
    public static void main(String[] args) {
        int tab[]=new int[100000];
        int v[]=new int[tab.length];
        int w[]=new int[tab.length];
        int u[]=new int[tab.length];
        int x[]=new int[tab.length];
        for(int i=0;i<tab.length;i++)
        {
            tab[i]=(int)(Math.random()*100);
            v[i]=tab[i];
            w[i]=tab[i];
            u[i]=tab[i];
            x[i]=tab[i];
        }
        //Util.Print(tab);
        long t0=System.currentTimeMillis();
        Util.selectSort(u);
        long t1=System.currentTimeMillis();
       // Util.Print(u);
        System.out.print("Selection sort: ");
        System.out.println(t1-t0+ " ms");
        t0=t1;
        Util.mergeSort(v,0,v.length-1);
        t1=System.currentTimeMillis();
        System.out.print("Merge sort: ");
        System.out.println(t1-t0+ " ms");
        t0=t1;
        Util.bubbleSort(w);
        t1=System.currentTimeMillis();
        System.out.print("Bubble sort: ");
        System.out.println(t1-t0+ " ms");
        t0=t1;
        Util.quickSort(x,0,x.length-1);
        t1=System.currentTimeMillis();
        System.out.print("Quick sort: ");
        System.out.println(t1-t0+ " ms");
    }
}