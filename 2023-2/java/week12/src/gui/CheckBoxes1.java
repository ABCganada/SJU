package gui;

import javax.swing.*;
import java.awt.*;

public class CheckBoxes1 {

    public static void main(String[] args) {

        JFrame frame = new JFrame("Check Box");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel = new JPanel();
        panel.setBackground(Color.ORANGE);
        panel.setPreferredSize(new Dimension(300, 300));

        JCheckBox b1 = new JCheckBox("Java");
        JCheckBox b2 = new JCheckBox("C#");

        panel.add(b1);
        panel.add(b2);

        frame.add(panel);
        frame.pack();
        frame.setVisible(true);
    }
}
