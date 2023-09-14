package ch2.gui;

import javax.swing.*;

public class GuiExample {

    /**
     * JOptionPane.showMessageDialog()
     * INFORMATION, ERROR, WARNING, QUESTION, PLAIN
     * */
    public static void main(String[] args){
        JOptionPane.showMessageDialog(null, "This is GUI Dialogue Box");
        JOptionPane.showMessageDialog(null, "Try again", "Error", JOptionPane.ERROR_MESSAGE);
        JOptionPane.showMessageDialog(null, "You want to Continue", "Warning", JOptionPane.WARNING_MESSAGE);
        JOptionPane.showMessageDialog(null, "Plain dialog", "information", JOptionPane.PLAIN_MESSAGE);
        JOptionPane.showConfirmDialog(null, "Do you want to Close?");



    }
}
