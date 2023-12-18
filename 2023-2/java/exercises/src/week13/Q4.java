package week13;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class Q4 {

    static int amount = 0;

    public static void main(String[] args) {

        JFrame frame = new JFrame("Check Box");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel = new JPanel();
        panel.setPreferredSize(new Dimension(300, 200));

        JCheckBox box1 = new JCheckBox("KFC@7500");
        JCheckBox box2 = new JCheckBox("BurgerKing@6500");
        JCheckBox box3 = new JCheckBox("McDonals@5500");

        ArrayList<String> arrayList = new ArrayList<>();

        JButton btn = new JButton("Order");
        btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                if (box1.isSelected()) {
                    amount += 7500;
                    arrayList.add("KFC:7500");
                }

                if (box2.isSelected()) {
                    amount += 6500;
                    arrayList.add("BurgerKing:6500");
                }

                if (box3.isSelected()) {
                    amount += 5500;
                    arrayList.add("McDonals:5500");
                }

                JOptionPane.showMessageDialog(null, "Total: " + amount, "Message", JOptionPane.INFORMATION_MESSAGE);
            }
        });


        panel.add(box1);
        panel.add(box2);
        panel.add(box3);
        panel.add(btn);

        frame.add(panel);
        frame.pack();
        frame.setVisible(true);
    }
}
