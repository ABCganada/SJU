package classes;

import java.util.Scanner;

class Test{
    int a, b, sum;

    void getData(){
        System.out.println("Enter the number");
        Scanner sc = new Scanner(System.in);

        a = sc.nextInt();
        b = sc.nextInt();
    }

    void add(){
        sum = a+b;
        System.out.println("Addition is " + sum);
    }
}


public class ClassExample {
    public static void main(String[] args){

        Test obj = new Test();
        obj.getData();
        obj.add();
    }
}
