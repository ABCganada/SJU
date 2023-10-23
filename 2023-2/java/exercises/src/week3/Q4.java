package week3;

import java.util.Random;
import java.util.Scanner;

public class Q4 {

    public static void main(String[] args) {
        Random random = new Random();
        Scanner sc = new Scanner(System.in);

        int answer = random.nextInt(100) + 1;   //1~100

        int guess = -1;

        while (guess != answer) {
            guess = sc.nextInt();

            if (guess == answer) {
                System.out.println("Congratulations!");
            } else if (guess > answer) {
                System.out.println("Too High");
            } else {
                System.out.println("Too Low");
            }
        }
    }
}
