package ch2.scanner.exercise;

import java.util.Scanner;

public class Q2 {

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        String s1 = sc.nextLine();

        System.out.println(s1.equals("Sample message"));
        System.out.println(s1.equalsIgnoreCase("sAmPLe MESsAgE"));
    }
}
