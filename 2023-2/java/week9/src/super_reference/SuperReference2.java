package super_reference;

class Person{
    Person(){
        System.out.println("Person class Constructor");
    }
}

class Officer extends Person{
    Officer(){
        //call parent class constructor
        super();
        System.out.println("Officer class Constructor");
    }
}

public class SuperReference2 {

    public static void main(String[] args){
        Officer officer = new Officer();
    }
}
