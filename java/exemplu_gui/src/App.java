import java.awt.*;
import java.awt.event.*;
//declarari
//=========================================================================
class StudentFrame extends Frame {
private List studentList = new List();
private TextField studentTextField = new TextField();
private Button addButton = new Button();
public StudentFrame() {
try {
jbInit();
}
catch(Exception e) {
e.printStackTrace();
}
show();
}
//=========================================================================
public static void main(String[] args) {
StudentFrame studentFrame = new StudentFrame();
}
//definiri
//=========================================================================
private void jbInit() throws Exception {
this.addWindowListener(new java.awt.event.WindowAdapter() { //pt inchidere fereastra
public void windowClosing(WindowEvent e) {
this_windowClosing(e);
}
});
studentList.setBounds(new Rectangle(210, 60, 160, 140)); //parte de aranjare
studentTextField.setBounds(new Rectangle(25, 60, 160, 30));
addButton.setLabel("Add");
addButton.setBounds(new Rectangle(70, 120, 80, 25));
addButton.addActionListener(new java.awt.event.ActionListener() {
public void actionPerformed(ActionEvent e) {
addButton_actionPerformed(e);
}
});
this.setSize(400, 220);
this.setResizable(false);
this.setLayout(null); //componentele pot fi asezate cu mouse-ul
this.setTitle("Students");
this.setBackground(new Color(240, 240, 240));
this.add(addButton, null);
this.add(studentTextField, null);
this.add(studentList, null);
}
void this_windowClosing(WindowEvent e) {
System.exit(0); //inchiderea aplicatiei
}
void addButton_actionPerformed(ActionEvent e) {
studentList.add(studentTextField.getText());
studentTextField.setText(""); //stergere
}
}
//=========================================================================