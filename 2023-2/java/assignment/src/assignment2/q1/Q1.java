package assignment2.q1;

import java.util.Random;

public class Q1 {

    public static void main(String[] args){

        Random random = new Random();

        /**
         * sample 1
         * */
        for(int i=0; i<20; i++){
            System.out.print(random.nextInt(6) + 1 + " ");
        }
        System.out.println();

        /**
         * sample 2
         * */
        for(int i=0; i<20; i++){
            System.out.print(random.nextInt(6) + 1 + " ");
        }
        System.out.println();
    }
}
