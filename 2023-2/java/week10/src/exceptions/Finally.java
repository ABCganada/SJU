package exceptions;

import java.util.Scanner;

class Adult1 {
    void display()
    {
        try{
            int age;
            Scanner obj=new Scanner(System.in);
            age=obj.nextInt();
            if(age<18) throw new Exception("!!!under 18");
        //this line is executed when there is no exception
            System.out.println("Valid age");
        }
        //this will be executed when there is exception
        catch(Exception e){
            System.out.println(e);
            System.out.println("Not valid age");
        }
        //this will be executed in either case
        finally {
            System.out.println("Authenticated");
        }
    }
}
public class Finally {

    public static void main(String[] args){
        Adult1 adult = new Adult1();
        adult.display();
    }
}
