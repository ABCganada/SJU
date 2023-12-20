import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Q2 {

    public static void main(String[] args) {

        JFrame frame = new JFrame("Simple Calculator");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel = new JPanel();
        panel.setPreferredSize(new Dimension(500, 100));
        panel.setBackground(Color.GREEN);

        JTextField text1 = new JTextField("Number1");
        JTextField text2 = new JTextField("Number2");
        JTextField text3 = new JTextField("Result");

        JButton addBtn = new JButton("+");
        addBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    int n1 = Integer.parseInt(text1.getText());
                    int n2 = Integer.parseInt(text2.getText());

                    int res = n1 + n2;
                    text3.setText(String.valueOf(res));
                } catch (Exception ex) {    //string input exception
                    JOptionPane.showMessageDialog(null, ex.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        JButton subBtn = new JButton("-");
        subBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    int n1 = Integer.parseInt(text1.getText());
                    int n2 = Integer.parseInt(text2.getText());

                    int res = n1 - n2;
                    text3.setText(String.valueOf(res));
                } catch (Exception ex) {    //string input exception
                    JOptionPane.showMessageDialog(null, ex.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        JButton mulBtn = new JButton("*");
        mulBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    int n1 = Integer.parseInt(text1.getText());
                    int n2 = Integer.parseInt(text2.getText());

                    int res = n1 * n2;
                    text3.setText(String.valueOf(res));
                } catch (Exception ex) {    //string input exception
                    JOptionPane.showMessageDialog(null, ex.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        JButton divBtn = new JButton("/");
        divBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    int n1 = Integer.parseInt(text1.getText());
                    int n2 = Integer.parseInt(text2.getText());

                    if (n2 == 0) {
                        throw new ArithmeticException();
                    }

                    int res = n1 / n2;
                    text3.setText(String.valueOf(res));
                } catch (ArithmeticException ex) {  //zero divide exception handling
                    JOptionPane.showMessageDialog(null, "zero cannot divide number.", "Error", JOptionPane.ERROR_MESSAGE);
                } catch (Exception ex) {    //string input exception
                    JOptionPane.showMessageDialog(null, ex.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        panel.add(addBtn);
        panel.add(subBtn);
        panel.add(mulBtn);
        panel.add(divBtn);
        panel.add(text1);
        panel.add(text2);
        panel.add(text3);

        frame.add(panel);

        frame.pack();
        frame.setVisible(true);
    }
}
