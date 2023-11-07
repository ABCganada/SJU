package exceptions;

import java.util.Scanner;

class Zero{

    int a, b;

    void display(){
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();
        int result = a / b;
        System.out.println(result);
    }
}

public class Exception1 {

    public static void main(String[] args){
        Zero zero = new Zero();
        zero.display();
    }
}
