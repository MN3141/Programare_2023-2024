package arbori;
public class BinaryTree{
    Node root;
    public BinaryTree()
    {
        this.root=null;
        insert(new Node(7));
        insert(new Node(1));
        insert(new Node(5));    }
    public void insert(Node z)
    {
        Node y=null;
        Node x=root;
        while(x!=null)
        {
            y=x;
            if(z.key<x.key)
                x=x.leftChild;
            else
                x=x.rightChild;
        }
        z.parent=y;
        if(y==null)
            root=z;
        else
        if(z.key<y.key)
            y.leftChild=z;
        else
            y.rightChild=z;
    }
    public Node getRoot()
    {
        return this.root;
    }
    public void inOrder(Node x)
    {
        if(x!=null)
        {
            inOrder(x.leftChild);
            System.out.print(x.key+" ");
            inOrder(x.rightChild);
        }
    }
    public void preOrder(Node x)
    {
        if(x!=null)
        {
            System.out.print(x.key+" ");
            preOrder(x.leftChild);
            preOrder(x.rightChild);
        }
    }
    public void postOder(Node x)
    {
        if(x!=null)
        {
            preOrder(x.leftChild);
            preOrder(x.rightChild);
            System.out.print(x.key+" ");
        }
    }
    public Node recSearch(Node x,int k)
    {
        if(x==null || k==x.key)
            return x;
        if(k<x.key)
            return recSearch(x.leftChild,k);
        else return recSearch(x.rightChild,k);
    }
    public Node iteratSearch(Node x,int k)
    {
        while(x!=null && k!= x.key)
        {
            if(k<x.key)
                x=x.leftChild;
            else x=x.rightChild;
        }
        return x;
    }
    public Node min(Node x)
    {
        while(x.leftChild!=null)
            x=x.leftChild;
        return x;

    }
    public Node max(Node x)
    {
        while(x.rightChild!=null)
            x=x.rightChild;
        return x;
    }
    public Node successor(Node x)
    {
        if(x.rightChild!=null)
            return min(x.rightChild);
        Node y=x.parent;
        while(y!=null &&  x==y.rightChild)
        {
            x=y;
            y=y.parent;
        }
        return y;
    }
    public Node delete(Node z)
    {
        Node x=null;
        Node y=null;
        Node root=null;
        if(z.leftChild==null || z.rightChild==null)
            y=z;
        else y=successor(z);
        if(y.leftChild!=null)
            x=y.leftChild;
        else x=y.rightChild;
        if(x!=null)
            x.parent=y.parent;
        if(y.parent==null)
            root=x;
        else if(y==y.parent.leftChild)
            y.parent.leftChild=x;
        else y.parent.rightChild=x;
        if(y!=z)
            z.key=y.key;
        return y;

    }
}