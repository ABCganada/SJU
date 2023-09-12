package ch2;

public class Constants {

    public static void main(String[] args) {
        /**
         * constant : not variable
         * */
        final int MIN_HEIGHT = 69;
        final int MAX_LOAD = 250;

        /**
         * Assignment Conversion
         * */
        int dollars = 20;
        double money = dollars;
        System.out.println(money);

        /**
         * Promotion
         * */
        int count = 12;
        double sum = 490.27;
        double avg = sum / count;
        System.out.println(avg);

        /**
         * Casting
         * */
        int total = 50;
        float res = (float) total / 6;
        System.out.println(res);
    }

}
