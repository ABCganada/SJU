package ch1;

public class StringBasics {

    public static void main(String[] args) {

        String s1;
        String s2 = "and I say Hello";

        s1 = "goodBye";
        s1 = "You say " + s1;
        s1 += ", " + s2 + ".";

        System.out.println(s1);
    }
}
