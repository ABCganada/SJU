import javax.swing.*;

public class Q3 {

    static int flag = 0;

    public static void main(String[] args) {

        int n;

        while (flag == 0) {
            n = Integer.parseInt(JOptionPane.showInputDialog("Enter an integer:"));

            try {
                if (n % 2 == 0) {
                    JOptionPane.showMessageDialog(null, "That number is even", "Message", JOptionPane.INFORMATION_MESSAGE);
                } else {
                    JOptionPane.showMessageDialog(null, "That number is odd", "Message", JOptionPane.INFORMATION_MESSAGE);
                }
            } catch (Exception e) {
                JOptionPane.showMessageDialog(null, e.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
            } finally {

                flag = JOptionPane.showConfirmDialog(null, "Do Another?");

                if (flag == 1) {
                    break;
                }

            }
        }

    }
}
