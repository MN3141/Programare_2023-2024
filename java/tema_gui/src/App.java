import java.awt.*;
import java.awt.event.*;
import java.util.Arrays;
import javax.swing.JScrollPane;//de cautat o biblioteca awt
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;
//declarari
//=========================================================================
class StudentFrame extends Frame {
private GridLayout gLayout = new GridLayout(0, 4, 10, 10);
private JScrollPane rightScrollPane = new JScrollPane(); //scroll pt tabela
private JTable rightTable = new JTable(); //tabel gol
private String rightTableColumns[] = {"Name","Address","Age","Grade"}; //header
private DefaultTableModel rightTableModel = new DefaultTableModel(rightTableColumns, 0);
private Button addButton = new Button();
private Button clearButton=new Button();
private TextField nameTextField = new TextField();
private TextField addressTextField = new TextField();
private TextField ageTextField = new TextField();
private TextField gradeTextField = new TextField();
private List nameList = new List();
private List addressList = new List();
private List ageList = new List();
private List gradeList = new List();
private Label nameLabel=new Label("Name");
private Label addressLabel=new Label("Address");
private Label ageLabel=new Label("Age");
private Label gradeLabel=new Label("Grade");
int counter=0;
public StudentFrame() {

try {
jbInit();
}
catch(Exception e) {
e.printStackTrace();
}
this.setLayout(gLayout);
this.setBackground(new Color(128 , 128, 128));
this.add(rightScrollPane);
rightScrollPane.getViewport().add(rightTable, null);
rightTable.setModel(rightTableModel);
show();
nameTextField.requestFocus();
}
//=========================================================================
public static void main(String[] args) {
StudentFrame studentFrame = new StudentFrame();
}
//definiri
//=========================================================================
//fereastra principala+buton inchidere
private void jbInit() throws Exception {
    
    this.setSize(1000  , 500);
    this.setResizable(false);
    this.setLayout(null); //componentele pot fi asezate cu mouse-ul
    this.setTitle("Students");
    this.add(nameLabel,null);
    this.add(addressLabel,null);
    this.add(ageLabel,null);
    this.add(gradeLabel,null);
    this.add(nameTextField, null);
    this.add(addressTextField, null);
    this.add(ageTextField, null);
    this.add(gradeTextField, null);
    this.add(addButton, null);
    this.add(clearButton,null);
    this.addWindowListener(new java.awt.event.WindowAdapter() { //pt inchidere fereastra
    public void windowClosing(WindowEvent e) {
    System.exit(0); 
}
});
//=========================================================================
//TextField
// nameTextField.setBounds(new Rectangle(25, 60, 160, 30));
// addressTextField.setBounds(new Rectangle(25, 60, 160, 30));
// ageTextField.setBounds(new Rectangle(25, 60, 160, 30));
// gradeTextField.setBounds(new Rectangle(25, 60, 160, 30)); 
//nu mai este nevoie deoarece avem GridLayout la dispozitie
nameTextField.addKeyListener(new java.awt.event.KeyAdapter() {
public void keyPressed(KeyEvent e) {
studentTextField_keyPressed(e);
}
});

//=========================================================================
//Butoane
addButton.setLabel("Add");
clearButton.setLabel("Clear");
addButton.addActionListener(new java.awt.event.ActionListener() {
public void actionPerformed(ActionEvent e) {
    addButton_actiune(e);
}
});
clearButton.addActionListener(new java.awt.event.ActionListener() {
public void actionPerformed(ActionEvent e) { //problema:metodele celor 2 butoane se suprapun!!
    clearButton_actiune(e);
}
});
//StudentList
//=========================================================================
}

void addButton_actiune(ActionEvent e){
   counter++;
   rightTableModel.setRowCount(0);
   nameList.add(nameTextField.getText());
   addressList.add(addressTextField.getText());
   ageList.add(ageTextField.getText());
   gradeList.add(gradeTextField.getText());
   String name[]=new String[counter]; 
   String address[]=new String[counter]; 
   String age[]=new String[counter]; 
   String grade[]=new String[counter]; //trb studiata dezalocarea
   name=nameList.getItems();
   address=addressList.getItems();
   age=ageList.getItems();
   grade=gradeList.getItems();
   for(int i=0;i<counter;i++)
   {
    for(int j=i+1;j<counter;j++)
        {
            if(name[i].compareTo(name[j])>0)
                {
                    String temp=name[j];
                    name[j]=name[i];
                    name[i]=temp;
                     //===================
                    temp=address[j];
                    address[j]=address[i];
                    address[i]=temp;
                    //===================
                    temp=age[j];
                    age[j]=age[i];
                    age[i]=temp;
                    //===================
                    temp=grade[j];
                    grade[j]=grade[i];
                    grade[i]=temp;
                }
        }
   }
    for(int i=0;i<counter;i++)
    {
    String temp[]={name[i],address[i],age[i],grade[i]};
    rightTableModel.addRow(temp);
    }

nameTextField.setText("");
addressTextField.setText("");
ageTextField.setText("");
gradeTextField.setText("");
}
void clearButton_actiune(ActionEvent e)
{
    nameList.removeAll();
    ageList.removeAll();
    addressList.removeAll();
    gradeList.removeAll();
    rightTableModel.setRowCount(0);
    counter=0;
}
void studentTextField_keyPressed(KeyEvent e)
{
    if(e.getKeyCode()==e.VK_ENTER)
addButton_actiune(new ActionEvent(this, 0, null));
}
}
//=========================================================================