package container;

import javax.swing.*;
import java.awt.*;

public class NestedPanels {

    public static void main(String[] args){

        JFrame frame = new JFrame("Nested Panels");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel1 = new JPanel();
        panel1.setPreferredSize(new Dimension(150, 100));
        panel1.setBackground(Color.green);

        JLabel label1 = new JLabel("First Panel");
        panel1.add(label1);

        JPanel panel2 = new JPanel();
        panel2.setPreferredSize(new Dimension(150, 100));
        panel2.setBackground(Color.ORANGE);

        JLabel label2 = new JLabel("Second Panel");
        panel2.add(label2);

        JPanel primary = new JPanel();
        primary.setBackground(Color.blue);
        primary.add(panel1);
        primary.add(panel2);

        frame.getContentPane().add(primary);
        frame.pack();
        frame.setVisible(true);
    }
}
