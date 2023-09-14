package ch2.scanner;

import java.util.Scanner;

public class ScannerPractice {

    public static void main(String[] args){

        /**
         * new를 통해 Scanner 객체를 생성
         * */
        Scanner sc = new Scanner(System.in);

        String name;
        System.out.print("Enter your name: ");

        /**
         * nextLine() : 줄바꿈할 때까지의 input을 모두 읽는다.
         * */
        name = sc.nextLine();

        System.out.println("Hello, " + name);

        /**
         * next() : 공백 전까지의 문자열, 단어를 받는다
         * nextInt()
         * nextLong()
         * nextDouble()
         * */
    }
}
