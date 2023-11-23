package gui.exercise;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Ex4 {

    public static void main(String[] args) {

        JFrame frame=new JFrame("Check Box");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel=new JPanel();
        panel.setPreferredSize(new Dimension(300,100));
        panel.setBackground(Color.orange);

        JRadioButton r1=new JRadioButton("Java");
        r1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (r1.isSelected()) {
                    JOptionPane.showMessageDialog(null, "Java is Selected");
                }
            }
        });
        JRadioButton r2=new JRadioButton("C#");
        r2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (r2.isSelected()) {
                    JOptionPane.showMessageDialog(null, "C# is Selected");
                }
            }
        });
        JRadioButton r3=new JRadioButton("Capston");
        r3.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (r3.isSelected()) {
                    JOptionPane.showMessageDialog(null, "Capston is Selected");
                }
            }
        });

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
