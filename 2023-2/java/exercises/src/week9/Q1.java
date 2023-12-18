package week9;

import java.util.Scanner;

class A {
    int n1, n2;

    public A(int n1, int n2) {
        this.n1 = n1;
        this.n2 = n2;
    }
}

class B extends A {
    int n3, n4, sum;

    public B(int n1, int n2, int n3, int n4) {
        super(n1, n2);
        this.n3 = n3;
        this.n4 = n4;
    }

    public void sumNumber() {
        sum = n1 + n2 + n3 + n4;
    }

    public void printResult() {
        System.out.println(sum);
    }
}

/*
* single level inheritance
* */
public class Q1 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int a, b, c, d;
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();
        d = sc.nextInt();

        B obj = new B(a, b, c, d);
        obj.sumNumber();
        obj.printResult();
    }
}
