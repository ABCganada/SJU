package constructors;

import java.util.Scanner;

class Employee{

    private String name;

    public Employee(){
        Scanner sc = new Scanner(System.in);
        System.out.println("name : ");
        this.name = sc.nextLine();
    }

    public void readName(){
        System.out.println("My name is " + this.name);
    }
}

public class EmployeeDriver {

    public static void main(String[] args){
        Employee employee = new Employee();
        employee.readName();
    }
}
