package interfaces;

interface in1{
    final int a = 10;

    void display();
}



public class TestClass implements in1{

    @Override
    public void display(){
        System.out.println("University");
    }

    public static void main(String[] args){
        TestClass t = new TestClass();
        t.display();
        System.out.println(a);
    }
}
