package inheritance;

import java.util.Scanner;

class Students {
    int id;
    String name;
    void getInfo() {
        Scanner obj= new Scanner(System.in);
        System.out.println("Enter Student Detail:");
        name=obj.nextLine();
        id=obj.nextInt();
    }
    void putInfo() {
        System.out.println(name);
        System.out.println(id);
    }
}

class ComputerStu extends Students {
    int m1,m2;
    void getmark() {
        System.out.println("Enter Two marks:");
        Scanner obj= new Scanner(System.in);
        m1=obj.nextInt();
        m2= obj.nextInt();
    }
    void putmark() {
        System.out.println(m1);
        System.out.println(m2);
    }
}

class Display extends ComputerStu{
    void display() {
        System.out.println("*****Output*****");
        putInfo(); //Class Students
        putmark(); //Class ComputerStu
        int total=m1+m2;
        System.out.println (total);
    }
}

public class MultiLevelInheritance {

    public static void main(String[] args) {
        Display disp= new Display();
        disp.getInfo();
        disp.getmark();
        disp.display();
    }
}
