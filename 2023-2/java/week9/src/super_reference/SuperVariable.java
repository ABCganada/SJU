package super_reference;

class One{
    int a = 10;
}

class Two extends One{
    int a = 100;

    void display(){
        System.out.println("Child Class: " + a);
        System.out.println("Parent Class: " + super.a);
    }
}

public class SuperVariable {

    public static void main(String[] args){

        Two two = new Two();
        two.display();
    }
}
