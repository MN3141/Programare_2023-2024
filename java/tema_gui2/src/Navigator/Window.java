package Navigator;
import java.awt.*;
import java.awt.event.*;
public class Window extends Frame {
    public Window()
    {
        this.addWindowListener(new java.awt.event.WindowAdapter() { //pt inchidere fereastra
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }
}