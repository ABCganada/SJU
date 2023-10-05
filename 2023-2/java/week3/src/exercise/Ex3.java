package exercise;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Ex3 {

    public static void main(String[] args){

        JFrame frame = new JFrame("Nested Panels");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        ImageIcon icon = new ImageIcon("/Users/abcganada/Desktop/스크린샷 2023-09-21 오후 9.55.45.png");

        JPanel panel1 = new JPanel();
        panel1.setPreferredSize(new Dimension(200, 200));
        panel1.setBackground(Color.GREEN);

        JPanel panel2 = new JPanel();
        panel2.setPreferredSize(new Dimension(250, 600));
        panel2.setBackground(Color.CYAN);

        JPanel panel3 = new JPanel();
        panel3.setPreferredSize(new Dimension(600, 600));
        panel3.setBackground(Color.ORANGE);

        JLabel label1 = new JLabel("First Panel");
        panel1.add(label1);

        JLabel label2 = new JLabel("if you want to proceed");
        panel2.add(label2);
        JButton button = new JButton("Click here");
        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(null, "버튼을 클릭하셨습니다!");
            }
        });
        panel2.add(button);

        JLabel label3 = new JLabel("세종대학교(Sejong University)", icon, SwingConstants.CENTER);
        label3.setHorizontalTextPosition(SwingConstants.CENTER);
        label3.setVerticalTextPosition(SwingConstants.BOTTOM);
        panel3.add(label3);

        panel2.add(panel1);

        JPanel primary = new JPanel();
        primary.setBackground(Color.BLUE);
        primary.add(panel2);
        primary.add(panel3);

        frame.getContentPane().add(primary);
        frame.pack();
        frame.setVisible(true);
    }
}
