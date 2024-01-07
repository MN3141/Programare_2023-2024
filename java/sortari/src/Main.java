class Util{
    public static void Print(int array[])
    {
        for(int i=0;i< array.length;i++)
            System.out.print(array[i]+" ");
        System.out.println();
    }
    public static void insertSort(int array[])
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
        while(sorted==false)
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
        while(i<pivot && j<last)
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
        int v[]={2,11,3,0,-2,11111,1};
        int w[]=v;
        Util.Print(w);
        Util.mergeSort(w,0,6);
        Util.Print(w);
    }
}