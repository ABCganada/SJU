package exceptions;

import java.util.Scanner;

class Exception3{

    int a, b, result;

    void display() {
        try {
            Scanner sc = new Scanner(System.in);
            a = sc.nextInt();
            b = sc.nextInt();
            if(b==0) throw new Exception("//zero");
            result = a / b;
            System.out.println(result);
        } catch (Exception e){
            System.out.println(e);
        }
    }
}

public class Throw {

    public static void main(String[] args){
        Exception3 exception3 = new Exception3();
        exception3.display();
    }
}
