package inheritance;

import java.util.Scanner;

class Input{
    protected int no;

    protected void getno(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number");
        no = sc.nextInt();
    }
}

class Square extends Input{

    void square(){
        System.out.println("Square: " + (no * no));
    }
}

class Cube extends Input{

    void cube(){
        System.out.println("Cube: " + (no * no * no));
    }
}

public class HierarchicalInheritance {

    public static void main(String[] args) {
        Square obj1= new Square();
        Cube obj2= new Cube();
        obj1.getno();
        obj1.square();
        obj2.cube();
    }
}
