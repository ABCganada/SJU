package week3_2;

import javax.swing.*;
import java.awt.*;

public class Q2 {

    public static void main(String[] args){

        JFrame frame = new JFrame("Nested Panels");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        ImageIcon image = new ImageIcon("/Users/abcganada/Desktop/스크린샷 2023-09-21 오후 9.55.45.png");

        JPanel panel1 = new JPanel();
        panel1.setPreferredSize(new Dimension(150, 150));
        panel1.setBackground(Color.GREEN);

        JLabel label1 = new JLabel("First Panel");
        panel1.add(label1);

        JPanel panel2 = new JPanel();
        panel2.setPreferredSize(new Dimension(200, 500));
        panel2.setBackground(Color.CYAN);

        JLabel label2 = new JLabel("Second Panel");
        panel2.add(label2);
        panel2.add(panel1);

        JPanel panel3 = new JPanel();
        panel3.setPreferredSize(new Dimension(500, 500));
        panel3.setBackground(Color.ORANGE);

        JLabel label3 = new JLabel("세종대학교(Sejong University)", image, SwingConstants.CENTER);
        label3.setHorizontalTextPosition(SwingConstants.CENTER);
        label3.setVerticalTextPosition(SwingConstants.BOTTOM);

        panel3.add(label3);

        JPanel primary = new JPanel();
        primary.setBackground(Color.BLUE);
        primary.add(panel2);
        primary.add(panel3);

        frame.add(primary);
        frame.pack();
        frame.setVisible(true);
    }
}
