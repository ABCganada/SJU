package week13;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Q2 {

    public static void main(String[] args) {

        JFrame frame = new JFrame("Java Programming");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel = new JPanel();
        panel.setPreferredSize(new Dimension(300, 100));
        panel.setBackground(Color.GREEN);

        JTextField text1 = new JTextField("Number1");
        JTextField text2 = new JTextField("Number2");
        JTextField text3 = new JTextField("Sum");

        JButton btn = new JButton("ADD");
        btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int n1 = Integer.parseInt(text1.getText());
                int n2 = Integer.parseInt(text2.getText());

                int sum = n1 + n2;

                text3.setText(String.valueOf(sum));
            }
        });

        panel.add(btn);
        panel.add(text1);
        panel.add(text2);
        panel.add(text3);

        frame.add(panel);

        frame.pack();
        frame.setVisible(true);
    }
}
