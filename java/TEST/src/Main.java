import java.awt.*;
import java.awt.event.*;
import java.util.Arrays;
//declarari
//=========================================================================
class StudentFrame extends Frame {

    private Button addButton = new Button();
    private Button clearButton=new Button();
    private TextField studentTextField = new TextField();
    private List studentList = new List();
    int counter=0;
    public StudentFrame() {
        try {
            jbInit();
        }
        catch(Exception e) {
            e.printStackTrace();
        }
        show();
        studentTextField.requestFocus();
    }
    //=========================================================================
    public static void main(String[] args) {
        StudentFrame studentFrame = new StudentFrame();
    }
    //definiri
//=========================================================================
//fereastra principala+buton inchidere
    private void jbInit() throws Exception {
        this.setSize(400, 220);
        this.setResizable(false);
        this.setLayout(null); //componentele pot fi asezate cu mouse-ul
        this.setTitle("COM. BALGRAD");
        this.setBackground(new Color(10, 20, 255));
        this.add(addButton, null);
        this.add(studentTextField, null);
        this.add(studentList,null);
        this.add(clearButton,null);
        this.addWindowListener(new java.awt.event.WindowAdapter() { //pt inchidere fereastra
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
//=========================================================================
//TextField
        studentTextField.setBounds(new Rectangle(25, 60, 160, 30));
        studentTextField.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyPressed(KeyEvent e) {
                studentTextField_keyPressed(e);
            }
        });

//=========================================================================
//Butoane
        addButton.setLabel("Add");
        addButton.setBounds(new Rectangle(100, 120, 80, 25));
        clearButton.setLabel("Clear");
        clearButton.setBounds(new Rectangle(10, 120, 80, 25));
        addButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(ActionEvent e) { //problema:metodele celor 2 butoane se suprapun!!
                addButton_actiune(e);
            }
        });
        clearButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(ActionEvent e) { //problema:metodele celor 2 butoane se suprapun!!
                clearButton_actiune(e);
            }
        });
//StudentList
        studentList.setBounds(new Rectangle(210, 60, 160, 140));
//=========================================================================

    }

    void addButton_actiune(ActionEvent e){
        counter++;
        studentList.add(studentTextField.getText());
        String temp[]=new String[counter]; //de vazut cu dezalocarea memoriei
        temp=studentList.getItems();
        studentList.removeAll();
        Arrays.sort(temp);
        for(int i=0;i<temp.length;i++)
            studentList.add(temp[i],i);
        studentTextField.setText("");

    }
    void clearButton_actiune(ActionEvent e)
    {
        studentList.removeAll();
    }
    void studentTextField_keyPressed(KeyEvent e)
    {
        if(e.getKeyCode()==e.VK_ENTER)
            addButton_actiune(new ActionEvent(this, 0, null));
    }
}
//=========================================================================