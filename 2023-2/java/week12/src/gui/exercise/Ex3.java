package gui.exercise;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Ex3 {

    private static JLabel label2;

    public static void main(String[] args) {

        JFrame frame = new JFrame("Fahrenheit");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel = new JPanel();
        panel.setBackground(Color.YELLOW);
        panel.setPreferredSize(new Dimension(300, 100));

        JLabel label = new JLabel("Enter Fahrenheit temperature");
        JTextField textField = new JTextField("\t");
        textField.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int temperF = Integer.parseInt(textField.getText().trim());
                int temperC = (int)((temperF - 32) / 1.8);

                if (label2 == null) {
                    label2 = new JLabel("Tenperature in Celsius: " + temperC);
                    panel.add(label2);
                } else {
                    label2.setText("Temperature in Celsius: " + temperC);
                }
                frame.revalidate();
            }
        });

        panel.add(label);
        panel.add(textField);
        frame.add(panel);
        frame.pack();
        frame.setVisible(true);
    }
}
