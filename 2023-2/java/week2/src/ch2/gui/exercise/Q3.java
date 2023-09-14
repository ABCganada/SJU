package ch2.gui.exercise;

import javax.swing.*;

public class Q3 {

    public static void main(String[] args){
        /**
         * 숫자 4개를 입력받아 최솟값 출력
         * */

        String input = JOptionPane.showInputDialog(null, "First Number", "input", JOptionPane.QUESTION_MESSAGE);
        float n1 = Float.parseFloat(input);

        input = JOptionPane.showInputDialog(null, "Second Number", "input", JOptionPane.QUESTION_MESSAGE);
        float n2 = Float.parseFloat(input);

        input = JOptionPane.showInputDialog(null, "Third Number", "input", JOptionPane.QUESTION_MESSAGE);
        float n3 = Float.parseFloat(input);

        input = JOptionPane.showInputDialog(null, "Fourth Number", "input", JOptionPane.QUESTION_MESSAGE);
        float n4 = Float.parseFloat(input);

        float min = (n1 < n2 && n1 < n3) ? n1 : (n2 < n3 ? n2 : n3);
        min = min < n4 ? min : n4;
        JOptionPane.showMessageDialog(null, "smallest : " + min, "Message", JOptionPane.INFORMATION_MESSAGE);
    }
}
