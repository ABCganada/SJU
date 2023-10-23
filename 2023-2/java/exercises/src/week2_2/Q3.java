package week2_2;

import javax.swing.*;

public class Q3 {

    public static void main(String[] args){
        float f1 = Float.parseFloat(JOptionPane.showInputDialog("First Number"));
        float f2 = Float.parseFloat(JOptionPane.showInputDialog("Second Number"));
        float f3 = Float.parseFloat(JOptionPane.showInputDialog("Third Number"));
        float f4 = Float.parseFloat(JOptionPane.showInputDialog("Fourth Number"));

        float max = (f1 > f2 && f1 > f3 && f1 > f4) ? f1 : (f2 > f3 && f2 > f4) ? f2 : (f3 > f4) ? f3 : f4;
        float min = (f1 < f2 && f1 < f3 && f1 < f4) ? f1 : (f2 < f3 && f2 < f4) ? f2 : (f3 < f4) ? f3 : f4;

        JOptionPane.showMessageDialog(null, "Largest: " + max + "\n" + "Smallest: " + min, "Message", JOptionPane.INFORMATION_MESSAGE);
    }
}
