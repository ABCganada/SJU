package week13;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Q3 {

    public static void main(String[] args) {

        JFrame frame = new JFrame("Fahrenheit");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel = new JPanel();
        panel.setPreferredSize(new Dimension(300, 100));
        panel.setBackground(Color.YELLOW);

        JLabel label1 = new JLabel("Enter Fahrenheit temperature: ");
        JLabel label2 = new JLabel();
        JTextField text = new JTextField("        ");
        text.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                double f = Double.parseDouble(text.getText());
                double c = (f - 32) / 1.8;

                String str = "Temperature in Celsius: " + c;
                label2.setText(str);
            }
        });

        panel.add(label1);
        panel.add(text);
        panel.add(label2);

        frame.add(panel);
        frame.pack();
        frame.setVisible(true);
    }
}
