package gui.exercise;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Ex1 {

    static int cnt = 1;

    public static void main(String[] args) {

        JFrame frame = new JFrame("Java Programming");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel = new JPanel();
        panel.setBackground(Color.GREEN);
        panel.setPreferredSize(new Dimension(300, 100));

        JLabel label = new JLabel("This is a Java Programming");

        JButton btn = new JButton("Push");
        btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(null, "Push:"+cnt, "Message", JOptionPane.INFORMATION_MESSAGE);
                cnt++;
            }
        });

        frame.add(panel);
        panel.add(label);
        panel.add(btn);

        frame.pack();
        frame.setVisible(true);
    }
}
