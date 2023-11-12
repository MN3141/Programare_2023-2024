package Navigator;
import javax.swing.*;
import javax.swing.tree.DefaultMutableTreeNode;
import java.io.File;

public class Arbore  {
     public Arbore(){
         Window f=new Window();
         File rootFile=new File("C:\\");
         String s[]= rootFile.list();
         DefaultMutableTreeNode fii[]=new DefaultMutableTreeNode[s.length];
         DefaultMutableTreeNode rootNode=new DefaultMutableTreeNode("C");
         for(int i=0;i<s.length;i++)
         {
             fii[i]=new DefaultMutableTreeNode(s[i]);
             rootNode.add(fii[i]);
         }
         System.out.println(fii[1].getParent());
        JTree jt=new JTree(rootNode);
        f.add(jt);
        f.setSize(200,200);
        f.setVisible(true);
    }
    }