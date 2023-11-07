import java.awt.*;
import java.awt.event.*;
import java.util.Arrays;
import javax.swing.JScrollPane;//de cautat o biblioteca awt
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;
class TableFrame extends Frame {
private GridLayout gLayout = new GridLayout(1, 2, 10, 10);
private JScrollPane leftScrollPane = new JScrollPane();
private JScrollPane rightScrollPane = new JScrollPane();
private String leftTableColumns[] = {"Name", "Age"}; //header
private Object leftTableData[][] = {{"Popescu", "103"}, {"Ionescu", "98"}}; //continut
//JTable(date,coloane)
private JTable leftTable = new JTable(leftTableData, leftTableColumns); //tabel cu date preincarcate
private JTable rightTable = new JTable(); //tabel gol
private String rightTableColumns[] = {"Column 1", "Column 2"}; //header
private DefaultTableModel rightTableModel = new DefaultTableModel(rightTableColumns, 0);
public TableFrame() {
this.setSize(400, 150);
this.setLayout(gLayout);
this.setTitle("Tables");
this.setBackground(new Color(240, 240, 240));
this.add(leftScrollPane);
this.add(rightScrollPane);
leftScrollPane.getViewport().add(leftTable, null);
rightScrollPane.getViewport().add(rightTable, null);
rightTable.setModel(rightTableModel);
for(int i=1; i<=10; i++){
String row[] = {"Row" + i + ", Col 1", "Row" + i + ", Col 2"}; 
rightTableModel.addRow(row);//!! row nu e un tablou normal
}
show();
}
public static void main(String[] args) {
new TableFrame();
}
}