package inheritance;

import java.util.Scanner;

interface A1{
    public void input();
}

interface A2{
    public void get();
}

interface AA extends A1, A2{
    public void result();
}

class Result implements AA{
    int n1, n2;

    @Override
    public void input() {
        Scanner sc = new Scanner(System.in);
        n1 = sc.nextInt();
    }

    @Override
    public void get() {
        Scanner sc = new Scanner(System.in);
        n2 = sc.nextInt();
    }

    @Override
    public void result() {
        System.out.println(n1 + n2);
    }
}

public class MultipleInheritance {

    public static void main(String[] args){
        Result result = new Result();
        result.input();
        result.get();
        result.result();
    }
}
