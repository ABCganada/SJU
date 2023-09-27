package assignment1.q3;

import javax.swing.*;

public class Q3 {

    public static void main(String[] args){

        int n1, n2, n3;
        int max, min;

        n1 = Integer.parseInt(JOptionPane.showInputDialog("First Number"));
        n2 = Integer.parseInt(JOptionPane.showInputDialog("Second Number"));
        n3 = Integer.parseInt(JOptionPane.showInputDialog("Third Number"));

        max = n1 > n2 && n1 > n3 ? n1 : (n2 > n3 ? n2 : n3);
        min = n1 < n2 && n1 < n3 ? n1 : (n2 < n3 ? n2 : n3);

        JOptionPane.showMessageDialog(null, "Largest: " + max + "\n"
                + "Smallest: " + min, "result", JOptionPane.INFORMATION_MESSAGE);
    }
}

