package gui;

import javax.swing.*;
import java.awt.*;

public class RadioButtons1 {

    public static void main(String[] args) {

        JFrame frame=new JFrame("Check Box");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel=new JPanel();
        panel.setPreferredSize(new Dimension(300,100));
        panel.setBackground(Color.orange);

        JRadioButton r1=new JRadioButton("Java");
        JRadioButton r2=new JRadioButton("C#");
        JRadioButton r3=new JRadioButton("Capston");

        ButtonGroup group=new ButtonGroup();
        group.add(r1);
        group.add(r2);
        group.add(r3);

        panel.add(r1);
        panel.add(r2);
        panel.add(r3);

        frame.add(panel);
        frame.pack();
        frame.setVisible(true);
    }
}
