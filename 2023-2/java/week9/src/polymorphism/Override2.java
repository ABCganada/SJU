package polymorphism;

class Parent {

    int no;

    void display() {
        System.out.println(no);
    }
}
class Child extends Parent {

    int no;

    Child(int a, int b) { //constructor
        no = a;
        super.no = b;
    }

    @Override
    void display() {
        System.out.println(no);
    }

    void output() {
        display();
        super.display();
    }

}

public class Override2 {

    public static void main(String[] args) {

        Child obj= new Child(10, 20);
        obj.output();
    }
}
