package polymorphism;

interface Person {
    public void display();
}

class Manager implements Person {

    @Override
    public void display() {
        System.out.println("Parent");
    }
}

class Handsome extends Manager {

    @Override
    public void display() {
        super.display();
        System.out.println("Child");
    }
}

public class InterfacePolymorphism {

    public static void main(String[] args){
        Handsome handsome = new Handsome();
        handsome.display();
    }
}
