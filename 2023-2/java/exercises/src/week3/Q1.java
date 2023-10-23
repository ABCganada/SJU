package week3;

import javax.swing.*;
import java.util.Random;

public class Q1 {

    public static void main(String[] args){

        Random random = new Random();

        int num = random.nextInt(25);
        System.out.println("0~24 : " + num);

        num = random.nextInt(6) + 1;
        System.out.println("1~6 : " + num);

        num = random.nextInt(100) + 10;
        System.out.println("10~109 : " + num);

        num = random.nextInt(10) - 5;
        System.out.println("-5 ~ 4 : " + num);

        num = random.nextInt(50) + 100;
        System.out.println("100~149 : " + num);

        num = random.nextInt(22) + 12;
        System.out.println("12~33 : " + num);
    }
}
