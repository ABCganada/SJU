package week13;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Q1 {

    static int push = 0;

    public static void main(String[] args) {
        JFrame frame = new JFrame("Java Programming");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel = new JPanel();
        panel.setPreferredSize(new Dimension(300, 200));
        panel.setBackground(Color.GREEN);

        JLabel label = new JLabel("This is a Java Programming");

        JButton btn = new JButton("Push");
        btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                push++;
                String str = "Push: " + push;
                JOptionPane.showMessageDialog(null, str, "Message", JOptionPane.INFORMATION_MESSAGE);
            }
        });

        panel.add(label);
        panel.add(btn);

        frame.add(panel);
        frame.pack();
        frame.setVisible(true);
    }
}
