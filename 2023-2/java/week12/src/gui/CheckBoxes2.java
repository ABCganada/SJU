package gui;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CheckBoxes2 {

    public static void main(String[] args) {

        JFrame frame = new JFrame("Check Box");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel = new JPanel();
        panel.setPreferredSize(new Dimension(500, 200));

        JButton btn = new JButton("Order");

        JCheckBox b1=new JCheckBox("KFC@7500(set)");
        JCheckBox b2=new JCheckBox("BurgerKing@6500(set)");
        JCheckBox b3=new JCheckBox("McDonals@5500(set)");

        btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int amount = 0;
                if (b1.isSelected()) {
                    amount += 7500;
                }
                if (b2.isSelected()) {
                    amount += 6500;
                }
                if (b3.isSelected()) {
                    amount += 5500;
                }
                JOptionPane.showMessageDialog(null, "Total: " + amount);
            }
        });

        panel.add(b1);
        panel.add(b2);
        panel.add(b3);
        panel.add(btn);

        frame.add(panel);
        frame.pack();
        frame.setVisible(true);
    }
}
