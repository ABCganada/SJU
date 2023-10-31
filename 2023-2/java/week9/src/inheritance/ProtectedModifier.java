package inheritance;

import java.util.Scanner;

class Staff{
    String name;
    long phone;

    void getPerson(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter name and Phone no.");
        name = sc.nextLine();
        phone = sc.nextInt();
    }

    void putPerson(){
        System.out.println(name);
        System.out.println(phone);
    }
}

class Manager extends Staff{
    float height, weight;

    void getPhysical(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter height and weight");
        height = sc.nextInt();
        weight = sc.nextInt();
    }

    void putPhysical(){
        System.out.println(height);
        System.out.println(weight);
    }
}

public class ProtectedModifier {

    public static void main(String[] args) {
        Manager bank= new Manager();
        bank.getPerson();
        bank.getPhysical();
        System.out.println("Staff Information");
        bank.putPerson();
        bank.putPhysical();
    }
}
