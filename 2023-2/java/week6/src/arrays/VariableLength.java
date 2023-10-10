package arrays;

class Test1{
    void get(int ...a){
        System.out.println("Number of args: " + a.length);

        System.out.println(a[0]);

        for(int i:a){
            System.out.print(i+" ");
        }
        System.out.println();
    }
}

public class VariableLength {

    public static void main(String[] args){

        Test1 obj = new Test1();
        obj.get(100);
        obj.get(10,20,30,40,50);
        obj.get(70, 60);
    }
}
