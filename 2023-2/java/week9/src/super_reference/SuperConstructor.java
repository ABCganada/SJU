package super_reference;

class First{
    int n1, n2;

    First(int a, int b){
        n1 = a;
        n2 = b;
        System.out.println(n1);
        System.out.println(n2);
    }
}

class Second extends First {

    Second(){
        super(10, 20);
    }
}

public class SuperConstructor {

    public static void main(String[] args){
        Second second = new Second();
    }
}
