package constructors;

class Student{
    String name;

    Student(){
        this.name = "SMG";
        System.out.println(this.name);
    }
}

public class DefaultConstructor {

    public static void main(String[] args) {

        Student student = new Student();
    }
}
