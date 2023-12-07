package main;
import oameni.*;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Vector;

public class Main {
    public static void main(String[] args) {
     Teacher s1=new Teacher("Ciuca Norris","Felwood",30,20,10);
     Teacher s2=new Teacher("Gigel","Victoria",40,1,2);
     Teacher s3=new Teacher("Andras","Vaslui",27,1,-1);
     Teacher s4=new Teacher("Hans","Vaslui",27,1,10);
     Teacher tab[] =new Teacher[4];
     tab[0]=s1;
     tab[1]=s2;
     tab[2]=s3;
     tab[3]=s4;
     for(int i=0;i<4;i++)
         System.out.println(tab[i].getName());
        System.out.println("=========================");
        Arrays.sort(tab,new Comparator<Teacher>()
        {
            public int compare(Teacher t1,Teacher t2){
                return (-1)*(t1.getVechime()- t2.getVechime());
            }
        });
        for(int i=0;i<4;i++)
            System.out.println(tab[i].getName());
    }
}