package ch2.gui.exercise;

import javax.swing.*;

public class Q1 {

    public static void main(String[] args){

        /**
         * 이름, Quantity, Rate를 showInputDialog()에서 입력받아
         * showMessageDialog()에 출력하기
         * */

        String name = JOptionPane.showInputDialog(null, "Enter name", "input", JOptionPane.QUESTION_MESSAGE);

        String input = JOptionPane.showInputDialog(null, "Enter Quantity", "input", JOptionPane.QUESTION_MESSAGE);
        int q = Integer.parseInt(input);

        input = JOptionPane.showInputDialog(null, "Enter Rate(Won)", "input", JOptionPane.QUESTION_MESSAGE);
        double p = Double.parseDouble(input);

        JOptionPane.showMessageDialog(null, "Total " + name + " price: " + p*q + " Won");
    }
}
