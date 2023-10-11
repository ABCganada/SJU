package assignment2.q2;

import java.util.Random;

class Dice{

    Random random;
    int[] diceFrequency;

    public Dice(){
        random = new Random();
        diceFrequency = new int[6];
    }

    void roll(){
        int rollResult = random.nextInt(6) + 1;
        diceFrequency[rollResult-1]++;
    }

    void printResult(){
        System.out.println("Face" + "\t\t" + "Frequency");

        for(int i=0; i<6; i++){
            System.out.println(i+1 + "\t\t\t" + diceFrequency[i]);
        }
    }
}

public class Q2 {

    public static void main(String[] args){

        Dice dice = new Dice();

        for(int i=0; i<60000000; i++){
            dice.roll();
        }

        dice.printResult();
    }
}
