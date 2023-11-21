package gui;

import javax.swing.*;
import java.awt.*;

public class TextField {

    public static void main(String[] args) {
        JFrame frame=new JFrame("Java Programming");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JPanel primary= new JPanel();
        primary.setBackground(Color.green);
        primary.setPreferredSize(new Dimension(300,100));

        JTextField textField = new JTextField("This is java");
        textField.selectAll();
        textField.setEditable(false);

        primary.add(textField);

        frame.add(primary);
        frame.pack();
        frame.setVisible(true);
    }
}
