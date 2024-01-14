package huffman;
public class Node{
    protected int key;
    protected float data;
    protected Node leftChild;
    protected Node rightChild;
    protected Node parent;
    public Node()
    {
        this.key=0;
        this.parent=null;
        this.leftChild=null;
        this.rightChild=null;
        this.data=0;
    }
    public Node(int k){
    this.key=k;
    this.parent=null;
    this.leftChild=null;
    this.rightChild=null;
    this.data=0;
    }
    public Node(Node node)
    {
        this.key= node.key;
        this.parent=node.parent;
        this.leftChild=node.leftChild;
        this.rightChild=node.rightChild;
        this.data=node.data;
    }
    public void setKey(int k)
    {
        this.key=k;
    }
    public void setData(float x)
    {
        this.data=x;
    }
    public boolean isLeaf()
    {
        boolean k=false;
        if(this.leftChild==null && this.rightChild==null)
            k=true;
        return k;
    }


}