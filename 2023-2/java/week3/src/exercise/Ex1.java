package exercise;

import javax.swing.*;
import java.awt.*;

public class Ex1 {

    public static void main(String[] args){

        JFrame frame = new JFrame("Nested Panels");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        ImageIcon icon1 = new ImageIcon("/Users/abcganada/Desktop/스크린샷 2023-09-21 오후 9.44.12.png");
        ImageIcon icon2 = new ImageIcon("/Users/abcganada/Desktop/스크린샷 2023-09-21 오후 9.44.19.png");

        JPanel panel1 = new JPanel();
        panel1.setPreferredSize(new Dimension(650, 650));
        panel1.setBackground(Color.WHITE);

        JPanel panel2 = new JPanel();
        panel2.setPreferredSize(new Dimension(650, 650));
        panel2.setBackground(Color.WHITE);

        JLabel label1 = new JLabel("First Panel", icon1, SwingConstants.CENTER);
        label1.setHorizontalTextPosition(SwingConstants.CENTER);
        label1.setVerticalTextPosition(SwingConstants.BOTTOM);
        panel1.add(label1);

        JLabel label2 = new JLabel("Second Panel", icon2, SwingConstants.LEFT);
        label2.setHorizontalTextPosition(SwingConstants.RIGHT);
        label2.setVerticalTextPosition(SwingConstants.CENTER);
        panel2.add(label2);

        JPanel primary = new JPanel();
        primary.setBackground(Color.BLUE);
        primary.add(panel1);
        primary.add(panel2);

        frame.getContentPane().add(primary);
        frame.pack();
        frame.setVisible(true);
    }
}
