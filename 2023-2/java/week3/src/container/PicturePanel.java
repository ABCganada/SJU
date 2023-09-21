package container;

import javax.swing.*;
import java.awt.*;

public class PicturePanel {

    public static void main(String[] args){

        JFrame frame = new JFrame("Nested Panels");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        ImageIcon icon = new ImageIcon("/Users/abcganada/Desktop/wallpaper/oasis/oasis1.png");

        JPanel panel1 = new JPanel();
        panel1.setPreferredSize(new Dimension(600, 600));
        panel1.setBackground(Color.green);

        JLabel label1 = new JLabel("First Panel", icon, SwingConstants.CENTER);
        label1.setHorizontalTextPosition(SwingConstants.CENTER);
        label1.setVerticalTextPosition(SwingConstants.BOTTOM);
        panel1.add(label1);

        JPanel panel2 = new JPanel();
        panel2.setPreferredSize(new Dimension(600, 600));
        panel2.setBackground(Color.ORANGE);

        JLabel label2 = new JLabel("Second Panel");
        panel2.add(label2);

        JPanel primary = new JPanel();
        primary.setBackground(Color.blue);
        primary.add(panel1);
        primary.add(panel2);

        frame.getContentPane().add(primary);
        frame.pack();
        frame.setVisible(true);
    }
}
