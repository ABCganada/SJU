package week3;

import java.util.Random;

public class Q2 {

    public static void main(String[] args){
        Random random = new Random();

        int num = random.nextInt(13);
        System.out.println("0 ~ 12 : " + num);

        num = random.nextInt(20) + 1;
        System.out.println("1 ~ 20 : " + num);

        num = random.nextInt(6) + 15;
        System.out.println("15 ~ 20 : " + num);

        num = random.nextInt(11) - 10;
        System.out.println("-10 ~ 0 : " + num);
    }
}
