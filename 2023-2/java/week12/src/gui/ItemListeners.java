package gui;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;

public class ItemListeners {

    public static void main(String[] args) {

        JFrame frame=new JFrame("Check Box");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel=new JPanel();
        panel.setPreferredSize(new Dimension(400,200));

        JLabel label = new JLabel();
        JCheckBox b1=new JCheckBox("KFC");
        JCheckBox b2=new JCheckBox("Burger King");
        JCheckBox b3=new JCheckBox("McDonals");

        b1.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent e) {
                label.setText("KFC checkBox:"
                        + (e.getStateChange() == 1 ? "Checked" : "Unchecked"));
            }
        });

        b2.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent e) {
                label.setText("BurgerKing checkBox:"
                        + (e.getStateChange() == 1 ? "Checked" : "Unchecked"));
            }
        });

        b3.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent e) {
                label.setText("McDonals checkBox:"
                        + (e.getStateChange() == 1 ? "Checked" : "Unchecked"));
            }
        });

        panel.add(label);
        panel.add(b1);
        panel.add(b2);
        panel.add(b3);

        frame.add(panel);
        frame.pack();
        frame.setVisible(true);
    }
}
