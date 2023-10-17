package constructors.exercise;

class ConstructEx{
    private int field1;
    private int field2;

    public ConstructEx(){
        System.out.println("call No args construct");
    }

    public ConstructEx(int a){
        this.field1 = a;
        System.out.println("call 1 args construct");
        System.out.println(field1);
    }

    public ConstructEx(int a, int b){
        this.field1 = a;
        this.field2 = b;
        System.out.println("call all args construct");
        System.out.println(field1 + " " + field2);
    }
}

public class Ex1 {

    public static void main(String[] args){
        ConstructEx constructEx1 = new ConstructEx();
        ConstructEx constructEx2 = new ConstructEx(3);
        ConstructEx constructEx3 = new ConstructEx(3, 4);
    }
}
