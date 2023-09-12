package ch1;

public class SampleMessage {

    public static void main(String[] args){

        String s1;
        String s2 = " and I say Hello";

        s1 = "goodBye";
        s1 = "You say " + s1;
        s1 = s1 + s2 + ".";

//        System.out.println(s1);
//        System.out.println("Last character:" + s1.charAt(30));
//        System.out.println(s1.length());

        String animal1 = "Horse";
        String animal2 = "Fly";
        String newCreature;
        newCreature = animal1 + animal2;

        /**
         * boolean Type의 equals Method
         * */
        System.out.println(newCreature.equals("HorseFly"));
        System.out.println(newCreature.equals("Horse Fly"));

        /**
         * equalsIgnoreCase : 대소문자를 구별하지 않음
         * */
        System.out.println(newCreature.equalsIgnoreCase("HorseFly"));
    }
}
