package api;

import java.util.Random;
import java.util.Scanner;

public class Ex1 {

    public static void main(String[] args){

        Random gen = new Random();
        Scanner sc = new Scanner(System.in);

        int scr = gen.nextInt(1000) + 1;
        int guess;

        System.out.println("Guess a number between 1 to 1000");
        while(true){
            System.out.print("Guess (0 to exit): ");
            guess = sc.nextInt();

            if(guess == 0){
                break;
            }

            if(guess > scr){
                System.out.println(guess + " is too high. Try again");
            } else if(guess < scr){
                System.out.println(guess + " is too low. Try again");
            } else{
                System.out.println("OMG !");
                break;
            }
        }
    }
}