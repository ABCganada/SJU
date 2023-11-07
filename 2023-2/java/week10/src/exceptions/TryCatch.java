package exceptions;

import java.util.Scanner;

class Exception11{

    int a, b, result;

    void display() {
        try {
            Scanner sc = new Scanner(System.in);
            a = sc.nextInt();
            b = sc.nextInt();
            result = a / b;
            System.out.println(result);
        } catch (Exception e) {
            System.out.println(e);
        }
        System.out.println("Testing Exception");
    }
}

public class TryCatch {

    public static void main(String[] args){
        Exception11 exception11 = new Exception11();
        exception11.display();
    }
}
