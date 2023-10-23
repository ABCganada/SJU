package week4;

import java.util.Scanner;

class TestStu{
    private String name;
    private String birthDay;
    private int id;

    void getData(String name, String birthDay, int id){
        this.name = name;
        this.birthDay = birthDay;
        this.id = id;
    }

    void display(){
        System.out.println("***Student Information***");
        System.out.println(name);
        System.out.println(birthDay);
        System.out.println(id);
    }
}

public class Q1 {

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        String name, birthDay;
        int id;

        System.out.print("Enter your name: ");
        name = sc.nextLine();

        System.out.print("Enter your birthday: ");
        birthDay = sc.nextLine();

        System.out.print("Enter your id: ");
        id = sc.nextInt();

        TestStu testStu = new TestStu();
        testStu.getData(name, birthDay, id);
        testStu.display();

    }
}
