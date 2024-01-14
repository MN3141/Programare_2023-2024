package huffman;

import java.util.Vector;

public class HuffmanTree extends BinaryTree {
    BinaryTree huffTree = new BinaryTree();//OBS:este arbore binar,dar nu de cautare!
    huffCode generatedCode[] = null;//contine simbolul si codificarea acestuia;va fi folosit ca iesire
    Vector<Node> nodeArray = new Vector<Node>();//pt a genera arborul huffTree
    Node tabNoduri[] = null;//folosit pt a salva parintii nodurilor ce contin simboluri

    public HuffmanTree(Node[] array) {
        int n = array.length;
        this.generatedCode = new huffCode[n];
        tabNoduri = new Node[n];
        for (int i = 0; i < n; i++) {
            this.nodeArray.add(array[i]);
            this.nodeArray.elementAt(i).setData(array[i].data);
            this.nodeArray.elementAt(i).setKey(array[i].key);
        }
    }

    private int minIndex() {
        float minValue = this.nodeArray.elementAt(0).key;
        int index = 0;
        for (int i = 1; i < this.nodeArray.size(); i++) {
            if (this.nodeArray.elementAt(i).key < minValue) {
                minValue = this.nodeArray.elementAt(i).key;
                index = i;
            }
        }
        return index;
    }

    private String searchUp(Node node) {
        String sequence = "";
        while (node.parent != null) {
            if (node.key == node.parent.rightChild.key && node.data == node.parent.rightChild.data)//OBS:ID-urile difere,cea ce duce la concluzii eronate!
                sequence = sequence + "1";
            else sequence = sequence + "0";
            node = node.parent;
        }

        return sequence;
    }

    private void createHuffTree()//OBS:Nodurile ce contin symbolurile introduse vor fi mereu frunze
    {
        int n = this.nodeArray.size();
        int indexNodes = 0;
        for (int i = 0; i < n - 1; i++) {
            Node z = new Node();
            int indexMin = this.minIndex();
            z.leftChild = this.nodeArray.elementAt(indexMin);
            Node x = z.leftChild;
            x.parent = z;
            this.nodeArray.remove(indexMin);
            indexMin = this.minIndex();
            z.rightChild = this.nodeArray.elementAt(indexMin);
            Node y = z.rightChild;
            y.parent = z;
            this.nodeArray.remove(indexMin);
            z.key = x.key + y.key;
            if (x.isLeaf()) {
                this.tabNoduri[indexNodes] = new Node(x);
                indexNodes++;
            }
            if (y.isLeaf()) {
                this.tabNoduri[indexNodes] = new Node(y);
                indexNodes++;
            }
            this.nodeArray.add(z);
        }
        this.huffTree.setRoot(nodeArray.elementAt(0));
        //this.huffTree.inOrder(this.huffTree.root);
    }

    private void createHuffCodes() {
        int n = this.generatedCode.length;
        for (int i = 0; i < n; i++) {
            String orig = this.searchUp(this.tabNoduri[i]);
            String reverse = "";
            for (int j = orig.length() - 1; j >= 0; j--)
                reverse = reverse + orig.charAt(j);
            this.generatedCode[i] = new huffCode((char) this.tabNoduri[i].data, reverse);

        }
    }

    public huffCode[] codify() {
        this.createHuffTree();
        this.createHuffCodes();
        int n = this.generatedCode.length;
        huffCode rez[]=new huffCode[n];
        for (int i=0;i<n;i++)
            rez[i]=new huffCode(this.generatedCode[i].symbol,this.generatedCode[i].sequence);
        return rez;

    }
    public String decodify(String message)
    {
        message=message+" ";//improvizatie:
        //Problema:Mereu este verificat nodul radacina,chiar daca acesta niciodata nu va contine un simbol
        //asa ca,indexul va fi mereu in fata cu 1 decat trb
        String decodedMessage="";
        Node startNode=this.huffTree.root;
        for(int i=0;i<message.length();i++)
        {
            if(startNode.isLeaf())
            {
                decodedMessage=decodedMessage+(char)startNode.data;
                startNode=this.huffTree.root;
                i=i-1;

            }
            else if(message.charAt(i)=='1')
                startNode=startNode.rightChild;
                else startNode=startNode.leftChild;
        }
        return decodedMessage;
    }
}