package assignment1.q2;

import javax.swing.*;
import java.util.Random;

public class Q2 {

    public static void main(String[] args) {
        Random gen = new Random();
        int num = gen.nextInt(1000) + 1;

        int guess = -1;

        while (true) {
            guess = Integer.parseInt(JOptionPane.showInputDialog("Guess a number between 1 and 1000"));

            if(guess == 0){
                break;
            } else if(guess == num){
                int again = JOptionPane.showConfirmDialog(null, "Congratulations! Play again?",
                        "message", JOptionPane.YES_NO_OPTION);

                if(again == JOptionPane.YES_OPTION){
                    num = gen.nextInt(1000) + 1;
                } else{
                    break;
                }
            } else if(guess > num){
                JOptionPane.showMessageDialog(null, guess + " is too high. Try again.",
                        "message", JOptionPane.INFORMATION_MESSAGE);
            } else{
                JOptionPane.showMessageDialog(null, guess + " is too low. Try again.",
                        "message", JOptionPane.INFORMATION_MESSAGE);
            }
        }
    }
}
