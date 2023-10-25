import java.util.ArrayList;
import java.util.Random;

public class Main {

    public static void main(String[] args) {

        Random random = new Random();
        int n;

        ArrayList<Integer> dice1 = new ArrayList<>(6);
        ArrayList<Integer> dice2 = new ArrayList<>(6);

        for(int i=0; i<6; i++) {
            dice1.add(0);
            dice2.add(0);
        }

        for(int i=0; i<18000; i++){
            n = random.nextInt(6) + 1;
            dice1.set(n-1, dice1.get(n-1) + 1);

            n = random.nextInt(6) + 1;
            dice2.set(n-1, dice2.get(n-1) + 1);
        }

        System.out.println("Face\tFrequency (die1 & die2)");
        for(int i=0; i<6; i++){
            System.out.println((i+1) + "\t\t" + dice1.get(i) + "\t\t\t" + dice2.get(i));
        }
    }
}