package Navigator;
import javax.swing.*;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.MutableTreeNode;
import java.awt.*;
import java.io.File;
class NavigatorNode{
    File navigatorFile=null;
    DefaultMutableTreeNode navigatorNode=null;
        NavigatorNode(String path,String name)
        {
            this.navigatorFile=new File(path);
            this.navigatorNode=new DefaultMutableTreeNode(name);
        }

}
public class Arbore  {
    int k=7;
    void Adauga(NavigatorNode parent)
    {

        if(parent.navigatorFile.isDirectory()==true&& k>0)
        {
            String sTemp[]=parent.navigatorFile.list();
            for(int i=0;i< sTemp.length;i++)
            {
                NavigatorNode tempNav=new NavigatorNode(parent.navigatorFile.getPath()+sTemp[i],sTemp[i]);
                DefaultMutableTreeNode koi=new DefaultMutableTreeNode(sTemp[i]);
                System.out.println(sTemp[i]);
                parent.navigatorNode.add(koi);
            }
            for(int i=0;i<sTemp.length;i++)
            {
                NavigatorNode tempNav=new NavigatorNode(parent.navigatorFile.getPath()+sTemp[i],sTemp[i]);
                if(tempNav.navigatorFile.isDirectory()==true)
                {

                    k--;
                    Adauga(tempNav);
                }
            }
        }
    }
     public Arbore(){
         boolean ok=true;
         int k=10;
         Window f=new Window();
         DefaultMutableTreeNode root=new DefaultMutableTreeNode("RADIX");
         NavigatorNode test=new NavigatorNode("C:\\","C:");
         String name="C:";
         String path="C:\\";
         while(k>0)
         {
             NavigatorNode parent=new NavigatorNode(path,name);
             if(parent.navigatorFile.isDirectory()==true)
             {
                 String temp[]=parent.navigatorFile.list();
                 for(int i=0;i< temp.length;i++)
                 {
                     DefaultMutableTreeNode TEMP=new DefaultMutableTreeNode(temp[i]);
                     parent.navigatorNode.add(TEMP);
                 }

                 k--;
             }
         }
         JTree jt=new JTree(root);
         jt.setRootVisible(false); //ascunden radacina intregului arbore
         f.add(jt);
         f.add(new JScrollPane(jt)); //de testat
         f.setSize(500,500);
         f.setVisible(true);
    }

    }