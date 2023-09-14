package ch2.gui.exercise;

import javax.swing.*;

public class Q2 {

    public static void main(String[] args){
        /**
         * 숫자 3개를 입력받아 최댓값 출력
         * */

        String input = JOptionPane.showInputDialog(null, "First Number", "input", JOptionPane.QUESTION_MESSAGE);
        int n1 = Integer.parseInt(input);

        input = JOptionPane.showInputDialog(null, "Second Number", "input", JOptionPane.QUESTION_MESSAGE);
        int n2 = Integer.parseInt(input);

        input = JOptionPane.showInputDialog(null, "Third Number", "input", JOptionPane.QUESTION_MESSAGE);
        int n3 = Integer.parseInt(input);

        int max = (n1 > n2 && n1 > n3) ? n1 : (n2 > n3 ? n2 : n3);
        JOptionPane.showMessageDialog(null, "Largest : " + max, "Message", JOptionPane.INFORMATION_MESSAGE);
    }
}
