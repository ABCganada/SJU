package inheritance;

import java.util.Scanner;

interface manager{
    void getData();
}

class Branch{
    String place;
    public void getPlace(){
        this.place = "Korea";
    }
}

class Bank extends Branch implements manager {
    int id;
    String name;

    @Override
    public void getData() {
        Scanner sc = new Scanner(System.in);
        this.name = sc.nextLine();
        this.id = sc.nextInt();
    }

    void display() {
        System.out.println("***Output***");
        System.out.println(name);
        System.out.println(id);
        System.out.println(place);
    }
}

public class MultipleInheritance2 {

    public static void main(String[] args){
        Bank bank = new Bank();
        bank.getData();
        bank.getPlace();
        bank.display();
    }
}
