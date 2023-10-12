package arrays;

public class ArrayObject {

    public static void main(String[] args){
        System.out.println("Array of Objects");

        Emp[] emps = new Emp[10];

        for(int i=0; i<emps.length; i++){
            emps[i] = new Emp(i+1);
        }
    }
}

class Emp{
    int id;
    public Emp(int no){
        id = no;
        System.out.println("Array of objects : " + id);
    }
}
