package week3;

import java.util.Random;
import java.util.Scanner;

public class Q3 {

    public static void main(String[] args){

        Random random = new Random();
        Scanner sc = new Scanner(System.in);

        int scr1 = sc.nextInt();
        int scr2 = sc.nextInt();
        int scr3 = random.nextInt(101);
        int scr4 = random.nextInt(101);

        int max = (scr1 > scr2 && scr1 > scr3 && scr1 > scr4) ? scr1 : (scr2 > scr3 && scr2 > scr4) ? scr2 : (scr3 > scr4) ? scr3 : scr4;

        System.out.println(max);
    }
}
