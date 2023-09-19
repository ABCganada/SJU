package objects;

import java.util.Scanner;

public class Ex1 {

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        String input;

        Student st1 = new Student();
        System.out.print("Name : ");
        input = sc.nextLine();
        st1.name = input;
        System.out.print("Id : ");
        input = sc.nextLine();
        st1.id = Integer.parseInt(input);

        Student st2 = new Student();
        System.out.print("Name : ");
        input = sc.nextLine();
        st2.name = input;
        System.out.print("Id : ");
        input = sc.nextLine();
        st2.id = Integer.parseInt(input);

        System.out.println("*****Output****");

        if(st1.id == st2.id && st1.name.equals(st2.name)){
            System.out.println("Duplicate entry");
        } else{
            System.out.println("Name : " + st1.name);
            System.out.println("Id : " + st1.id);
            System.out.println("Name : " + st2.name);
            System.out.println("Id : " + st2.id);
        }

    }
}

class Student{
    int id;
    String name;
}
