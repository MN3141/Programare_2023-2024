package main;
import java.awt.*;
import java.awt.event.*;
import java.io.File;
class Navigator extends Frame {
    GridLayout gLayout=new GridLayout(0,2,10,10);
    File dir=new File("C:\\Arhiva_ULBS\\Proiecte\\Anul_II\\programare_2023-2024\\java\\tema_gui2\\LUCRU");
    //!!! pt ca metoda getParent() sa functioneze,trb ca la instantiere sa scriem intreaga adresa/cale
    String currentPath=null;
    Label dirLabel=new Label("TEST");
    Button forwardButton=new Button(">>");
    Button backwardButton=new Button("<<");
    public Navigator() {

        try {
            jbInit();
        }
        catch(Exception e) {
            e.printStackTrace();
        }
        show();
    }
    private void jbInit() throws Exception {
        dir.mkdir();
        currentPath=dir.getAbsolutePath();
        dirLabel.setText(currentPath);
        this.setSize(1000  , 500);
        this.setBackground(new Color(128 , 128, 128));
        this.setTitle("Director navigator");
        this.setResizable(true);
        this.setLayout(gLayout);
        this.addWindowListener(new java.awt.event.WindowAdapter() { //pt inchidere fereastra
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
        this.add(backwardButton,null);
        this.add(forwardButton,null);
        this.add(dirLabel,null);
        backwardButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(ActionEvent e) {
                goBack(e);
            }
        });
    }
    void goBack(ActionEvent e)
    {
        dirLabel.setText(dir.getParent());
        dir=new File(dir.getParent());
    }


}