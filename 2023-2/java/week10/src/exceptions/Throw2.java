package exceptions;

import java.util.Scanner;

class Adult {

    void display() {
        try {
            int age;
            Scanner sc = new Scanner(System.in);
            age = sc.nextInt();
            if (age < 18) throw new Exception("!!!under 18");
            System.out.println("Valid age");
        } catch (Exception e) {
            System.out.println(e);
            System.out.println("Not valid age");
        }
    }
}

public class Throw2 {

    public static void main(String[] args){
        Adult adult = new Adult();
        adult.display();
    }
}
