package polymorphism;

class Test {

    void output() {
        System.out.println("Nothing");
    }

    void output(int a) {
        System.out.println(a);
    }

    void output(int a, char b) {
        System.out.println(a);
        System.out.println(b);
    }

    void output(char b, float a) {
        System.out.println(b);
        System.out.println(a);
    }

    void output(String a){
        System.out.println(a);
    }
}

public class Overload {

    public static void main(String[] args){

        Test test = new Test();
        test.output();
        test.output(10);
        test.output("Korea");
        test.output('a', 200.0f);
        test.output(300, 'z');
    }
}
