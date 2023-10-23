package week2_2;

import javax.swing.*;

public class Q1 {

    public static void main(String[] args){
        String name = JOptionPane.showInputDialog("Enter Name");
        int qty = Integer.parseInt(JOptionPane.showInputDialog("Enter Quantity"));
        double price = Double.parseDouble(JOptionPane.showInputDialog("Enter Rate(Won)"));

        JOptionPane.showMessageDialog(null,"Total " + name + "price: " + qty*price + " Won", "Message", JOptionPane.INFORMATION_MESSAGE);

    }
}
