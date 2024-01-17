package main;
import huffman.*;
public class Main {
    public static void main(String[] args) {
        Node[] symbols =new Node[6];
        for(int i=0;i<symbols.length;i++)
            symbols[i]=new Node();
        symbols[0].setData((float)'a');
        symbols[0].setKey(45);
        symbols[1].setData((float)'b');
        symbols[1].setKey(13);
        symbols[2].setData((float)'c');;
        symbols[2].setKey(12);
        symbols[3].setData((float)'d');
        symbols[3].setKey(16);
        symbols[4].setData((float)'e');
        symbols[4].setKey(9);
        symbols[5].setData((float)'f');
        symbols[5].setKey(5);
        String message="1000110011010";
        HuffmanTree pom=new HuffmanTree(symbols);
        huffCode test[]=pom.codify();
        int n=test.length;
        for (int i = 0; i < n; i++)
        System.out.println("Simbol: " + test[i].getSymbol() + " " + test[i].getSequence());
        String test2=pom.decodify(message);
        System.out.println(test2);
    }
}