package ch2.gui;

import javax.swing.*;

public class InputDialog {
    /**
     * JOptionPane.showInputDialog()
     * */
    public static void main(String[] args){

//        String str = JOptionPane.showInputDialog("Enter Item name");
        /**
         * int형 정보를 읽기 위해서, 입력값을 int로 바꿔주는 작업이 필요
         * Integer.parseInt() : String을 Integer로 convert하는 method
         * */
        String input = JOptionPane.showInputDialog("Enter no. : ");
        int num = Integer.parseInt(input);
        JOptionPane.showMessageDialog(null, "num : " + num, "String to int", JOptionPane.INFORMATION_MESSAGE);

        /**
         * Double형 정보 마찬가지로
         * Double.parseDouble()
         * */
        input = JOptionPane.showInputDialog("Enter rate : ");
        double rate = Double.parseDouble(input);
        JOptionPane.showMessageDialog(null, "rate : " + rate, "String to double", JOptionPane.INFORMATION_MESSAGE);
    }
}
