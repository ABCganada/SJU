package gui;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ActiveEvent {

    public static void main(String[] args) {
        JFrame jFrame = new JFrame("Java Programming");
        jFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel jPanel = new JPanel();
        jPanel.setBackground(Color.GREEN);
        jPanel.setPreferredSize(new Dimension(300, 100));

        JLabel jLabel = new JLabel("This is a Java Programming");

        JButton btn = new JButton("Click");

        btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(null, "Welcome to Java.");
            }
        });

        jPanel.add(jLabel);
        jPanel.add(btn);

        jFrame.add(jPanel);
        jFrame.pack();
        jFrame.setVisible(true);
    }
}
