package container;

import javax.swing.*;
import java.awt.*;

public class FramePanel {

    public static void main(String[] args){

        //Creation of Frame
        JFrame frame = new JFrame("JAVA PROGRAMMING");

        //Set what the close button does
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        //Panel is created
        JPanel primary = new JPanel();
        primary.setBackground(Color.ORANGE);
        primary.setPreferredSize(new Dimension(300, 100));

        //Creation of two labels
        JLabel label1 = new JLabel("This is JAVA Programming");
        JLabel label2 = new JLabel("with frame, panel and labels");

        //Addition of label to the primary panel
        primary.add(label1);
        primary.add(label2);
        frame.getContentPane().add(primary);

        //Adjust the frame to panel size
        frame.pack();

        //setVisible method causes the frame to be displayed on the Monitor
        frame.setVisible(true);
    }
}
