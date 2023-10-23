package week3_2;

import javax.swing.*;
import java.awt.*;

public class Q1 {

    public static void main(String[] args){
        JFrame frame = new JFrame("Nested Panels");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel1 = new JPanel();
        panel1.setPreferredSize(new Dimension(300, 300));
        panel1.setBackground(Color.GREEN);

        JLabel label1 = new JLabel("First Panel");
        panel1.add(label1);

        JPanel panel2 = new JPanel();
        panel2.setPreferredSize(new Dimension(300, 300));
        panel2.setBackground(Color.ORANGE);

        JLabel label2 = new JLabel("Second Panel");
        panel2.add(label2);

        JPanel panel3 = new JPanel();
        panel3.setPreferredSize(new Dimension(300, 300));
        panel3.setBackground(Color.WHITE);

        JLabel label3 = new JLabel("Third Panel");
        panel3.add(label3);

        JPanel primary = new JPanel();
        primary.setBackground(Color.BLUE);
        primary.add(panel1);
        primary.add(panel2);
        primary.add(panel3);

        frame.add(primary);
        frame.pack();
        frame.setVisible(true);
    }
}
