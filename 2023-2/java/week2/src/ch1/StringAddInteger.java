package ch1;

public class StringAddInteger {

    public static void main(String[] args){

        /**
         * "+"가 문자열이랑 같이 쓰이면
         * */
        System.out.println("Sejong " + "Univ");
        System.out.println("Sejong " + 10);
        System.out.println("Sejong " + 10 + 10); //concatenated
        System.out.println("Sejong " + (10+10)); //added

        System.out.println("24 and 45 concatenated: " + 24 + 45);
        System.out.println("24 and 45 added: " + (24+45));
    }
}
