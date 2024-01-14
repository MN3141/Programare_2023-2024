package main;
import huffman.*;
public class Main {
    public static void main(String[] args) {
        Node[] symbols =new Node[6];
        for(int i=0;i<symbols.length;i++)
            symbols[i]=new Node();
        symbols[0].setData((float)'p');
        symbols[0].setKey(100);
        symbols[1].setData((float)'q');
        symbols[1].setKey(17);
        symbols[2].setData((float)'r');;
        symbols[2].setKey(2);
        symbols[3].setData((float)'x');
        symbols[3].setKey(58);
        symbols[4].setData((float)'y');
        symbols[4].setKey(80);
        symbols[5].setData((float)'z');
        symbols[5].setKey(5);
        String message="1111011001";
        HuffmanTree pom=new HuffmanTree(symbols);
        huffCode test[]=pom.codify();
        int n=test.length;
        for (int i = 0; i < n; i++)
        System.out.println("Simbol: " + test[i].getSymbol() + " " + test[i].getSequence());
        String test2=pom.decodify(message);
        System.out.println(test2);
    }
}