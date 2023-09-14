package ch2.scanner.exercise;

import java.util.Scanner;

public class Q1 {

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();

        System.out.println("a : " + a);
        System.out.println("b : " + b);
        System.out.println("c : " + c);

        int max, min;

        max = (a > b && a > c) ? a : (b > c ? b : c);

        min = (a < b && a < c) ? a : (b < c ? b : c);

        System.out.println("max : " + max);
        System.out.println("min : " + min);
    }
}
