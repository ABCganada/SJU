package inheritance;

class A{
    int x, y;

    void getData(int a, int b){
        x = a;
        y = b;
    }

    int add(){
        System.out.println("Super class");
        return x+y;
    }
}

class B extends A{
    int sub(){
        System.out.println("Sub class");
        return x-y;
    }
}


public class SingleInheritance {

    public static void main(String[] args){
        B b = new B();
        int add, sub;

        b.getData(5,3);
        add = b.add();
        sub = b.sub();

        System.out.println(add);
        System.out.println(sub);
    }
}
