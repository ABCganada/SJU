package encapsulation;

import java.util.Scanner;

class Test{
    // private으로 variable 선언하면서 캡슐화를 지킴
    private int a, b;
    private int sum;

    // 서비스 메서드로 public으로 선언
    public void getData(){
        System.out.println("Enter the number");
        Scanner sc = new Scanner(System.in);

        a = sc.nextInt();
        b = sc.nextInt();
    }

    public void add(){
        sum = a+b;
        System.out.println(sum);
    }
}

public class ClassExample {
    public static void main(String[] args){

        Test obj1 = new Test();
        obj1.getData();
        obj1.add();
    }
}
