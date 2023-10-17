package constructors;

public class OverloadConstructor{
    private int id;
    private String name;
    private int age;

    //creating two argument constructor
    OverloadConstructor(int i, String n){
        this.id = i;
        this.name = n;
    }

    //creating three arg constructor
    OverloadConstructor(int i, String n, int a){
        this.id = i;
        this.name = n;
        this.age=a;
    }

    void display(){
        System.out.println(id+" "+name+" "+age);
    }

    public static void main(String args[]){
        OverloadConstructor s1 = new OverloadConstructor(111,"david");
        OverloadConstructor s2 = new OverloadConstructor(222,"Ryan",25);
        s1.display();
        s2.display();
    }
}
