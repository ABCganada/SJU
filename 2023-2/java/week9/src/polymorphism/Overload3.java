package polymorphism;

class Overloading1{

    void msg() {
        System.out.println("Upper");
    }
}

class Overloading2 extends Overloading1{

    void msg(int a) {
        System.out.println(a);
    }
}

public class Overload3 {

    public static void main(String[] args) {
        Overloading2 overloading2 = new Overloading2();
        overloading2.msg();
        overloading2.msg(10);
    }
}
