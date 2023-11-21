package gui.practice;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class TextFieldEx1 {

    public static void main(String[] args) {
        JFrame frame=new JFrame("Java Programming");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel= new JPanel();
        panel.setBackground(Color.green);
        panel.setPreferredSize(new Dimension(300,100));

        JTextField text1 = new JTextField("Enter your name");
        JTextField text2 = new JTextField("Enter your city");
        JTextField text3 = new JTextField("Enter your age");

        JButton btn = new JButton("Submit");
        btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String name = text1.getText();
                String city = text2.getText();
                int age = Integer.parseInt(text3.getText());
                JOptionPane.showMessageDialog(null, "Information\n" +
                        name + "\n" + city + "\n" + age);
            }
        });

        panel.add(text1);
        panel.add(text2);
        panel.add(text3);
        panel.add(btn);

        frame.add(panel);
        frame.pack();
        frame.setVisible(true);
    }
}
