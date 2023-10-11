package assignment2.q3;

import javax.swing.*;
import java.awt.*;

public class Q3 {

    public static void main(String[] args){

        JFrame jFrame = new JFrame("Nested Panels");
        jFrame.setDefaultCloseOperation(jFrame.EXIT_ON_CLOSE);

        ImageIcon image = new ImageIcon("/Users/abcganada/Desktop/스크린샷 2023-09-21 오후 9.55.45.png");

        JPanel jPanel1 = new JPanel();
        jPanel1.setPreferredSize(new Dimension(150, 150));
        jPanel1.setBackground(Color.GREEN);

        JLabel jLabel1 = new JLabel("First Panel");
        jPanel1.add(jLabel1);

        JPanel jPanel2 = new JPanel();
        jPanel2.setPreferredSize(new Dimension(200, 500));
        jPanel2.setBackground(Color.CYAN);

        JLabel jLabel2 = new JLabel("Second Panel");
        jPanel2.add(jLabel2);
        jPanel2.add(jPanel1);

        JPanel jPanel3 = new JPanel();
        jPanel3.setPreferredSize(new Dimension(500, 500));
        jPanel3.setBackground(Color.orange);

        JLabel jLabel3 = new JLabel("세종대학교(Sejong University)", image, SwingConstants.CENTER);
        jLabel3.setVerticalTextPosition(SwingConstants.BOTTOM);
        jLabel3.setHorizontalTextPosition(SwingConstants.CENTER);
        jPanel3.add(jLabel3);

        JPanel primary = new JPanel();
        primary.setBackground(Color.BLUE);
        primary.add(jPanel2);
        primary.add(jPanel3);

        jFrame.add(primary);
        jFrame.pack();
        jFrame.setVisible(true);
    }
}
