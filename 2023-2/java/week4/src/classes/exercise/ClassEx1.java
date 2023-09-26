package classes.exercise;

import java.util.Scanner;

class Student{
    String name;
    int birthday, id;

    Scanner sc = new Scanner(System.in);

    void setName(){
        System.out.print("Enter your name: ");
        this.name = sc.nextLine();
    }

    void setBirthday(){
        System.out.print("Enter your birthday: ");
        this.birthday = sc.nextInt();
    }

    void setId(){
        System.out.print("Enter your id: ");
        this.id = sc.nextInt();
    }

    void printStudentInformation(){
        System.out.println("***Student information***");
        System.out.println(name);
        System.out.println(birthday);
        System.out.println(id);
    }
}

public class ClassEx1 {

    public static void main(String[] args){

        Student st = new Student();

        st.setName();
        st.setBirthday();
        st.setId();

        st.printStudentInformation();
    }
}
