import java.util.Scanner;

class A {
    Scanner sc = new Scanner(System.in);
    int n1, n2;

    public A() {
        System.out.println("Two number");
        int n1 = sc.nextInt();
        int n2 = sc.nextInt();
        this.n1 = n1;
        this.n2 = n2;
    }
}

class B extends A{
    int n3, n4;

    public B() {
        super();
        System.out.println("Enter Two number");
        int n3 = sc.nextInt();
        int n4 = sc.nextInt();
        this.n3 = n3;
        this.n4 = n4;
    }

    public void output() {
        int sum = super.n1 + super.n2 + n3 + n4;
        System.out.println("Addition: " + sum);
    }
}

public class Q1 {

    public static void main(String[] args) {

        B obj = new B();
        obj.output();
    }
}
