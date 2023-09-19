package api;

import java.util.Random;

public class RandomNumbers {

    public static void main(String[] args){

        Random generator = new Random();
        int num1;
        float num2;

        num1 = generator.nextInt();
        System.out.println("Random integer : " + num1);

        num1 = generator.nextInt(10);
        System.out.println("From 0 to 9 : " + num1);

        num1 = generator.nextInt(10) + 1;
        System.out.println("From 1 to 10 : " + num1);

        num2 = generator.nextFloat();
        System.out.println("Random float (between 0 to 1) : " + num2);

        num2 = generator.nextFloat() * 6;
        num1 = (int)num2 + 1;
        System.out.println("From 1 to 6 : " + num1);
    }
}
