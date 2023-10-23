public class Main {
    public static void main(String[] args) {
        int n=4,m=4;
        int matrix[][]=new int[n][m];
        int matrix2[][]=new int[n][m];
        int matrix3[][]=new int[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                matrix[i][j]=(int)(Math.random()*101)% 101;
        }
        int MAX=matrix[0][0];
        int MIN=matrix[0][0];
        System.out.println("First generated matrix:");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                System.out.print(matrix[i][j] + " ");
            System.out.println();
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(MAX<matrix[i][j])
                    MAX=matrix[i][j];
                if(MIN>matrix[i][j])
                    MIN=matrix[i][j];
            }
        }
        System.out.println("Maximum value:"+MAX);
        System.out.println("Minimum value:"+MIN);
        System.out.println("=======================================");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                matrix2[i][j]=(int)(Math.random()*101)% 101;
        }
        System.out.println("Second generated matrix:");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                System.out.print(matrix2[i][j] + " ");
            System.out.println();
        }
        System.out.println("=======================================");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                matrix3[i][j]=matrix[i][j]+matrix2[i][j];
        }
        System.out.println("The sum of the two matrices:");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                System.out.print(matrix3[i][j] + " ");
            System.out.println();
        }
        System.out.println("=======================================");
       if(m==n)
       {
           for(int i=0;i<n;i++)
           {
               for(int j=0;j<m;j++) {
                    int sum=0;
                   for(int k=0;k<n;k++)
                       sum=sum+matrix[i][k]*matrix2[k][j];
                   matrix3[i][j]=sum;
               }
           }
           System.out.println("The product of the two matrices:");
           for(int i=0;i<n;i++)
           {
               for(int j=0;j<m;j++)
                   System.out.print(matrix3[i][j] + " ");
               System.out.println();
           }
       }
    }
}
