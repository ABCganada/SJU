package week2_2;

import javax.swing.*;

public class Q2 {

    public static void main(String[] args){
        int n1 = Integer.parseInt(JOptionPane.showInputDialog("First Number"));
        int n2 = Integer.parseInt(JOptionPane.showInputDialog("Second Number"));
        int n3 = Integer.parseInt(JOptionPane.showInputDialog("Third Number"));

        int max = n1 > n2 && n1 > n3 ? n1 : (n2 > n3 ? n2 : n3);
        int min = n1 < n2 && n1 < n3 ? n1 : (n2 < n3 ? n2 : n3);

        JOptionPane.showMessageDialog(null, "Largest: " + max + "\n" + "Smallest: " + min, "Message",
                JOptionPane.INFORMATION_MESSAGE);
    }
}
