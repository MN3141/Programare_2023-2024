package Navigator;
import javax.swing.*;
import javax.swing.tree.DefaultMutableTreeNode;
public class Arbore  {
     public Arbore(){
         Window f=new Window();
        DefaultMutableTreeNode nodeLucru=new DefaultMutableTreeNode("LUCRU");
        DefaultMutableTreeNode nodeTest=new DefaultMutableTreeNode("TEST");
        DefaultMutableTreeNode style=new DefaultMutableTreeNode("Style");
        DefaultMutableTreeNode color=new DefaultMutableTreeNode("color");
        DefaultMutableTreeNode font=new DefaultMutableTreeNode("font");
        nodeLucru.add(nodeTest);//OBS:Cand un nod contine un alt nod,isi schimba pictograma din
        style.add(color);//fisier in director
        style.add(font);
        style.add(nodeLucru);
        DefaultMutableTreeNode red=new DefaultMutableTreeNode("red");
        DefaultMutableTreeNode blue=new DefaultMutableTreeNode("blue");
        DefaultMutableTreeNode black=new DefaultMutableTreeNode("black");
        DefaultMutableTreeNode green=new DefaultMutableTreeNode("green");
        color.add(red); color.add(blue); color.add(black); color.add(green);
        JTree jt=new JTree(style);
        f.add(jt);
        f.setSize(200,200);
        f.setVisible(true);
    }
    }