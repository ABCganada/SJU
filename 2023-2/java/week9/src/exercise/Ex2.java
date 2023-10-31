package exercise;

import java.util.Scanner;

interface Manager{
    void getData();
}

class Branch{
    String place;

    public void getPlace() {
        this.place = "Korea";
    }
}

class Bank extends Branch implements Manager{
    int id;
    String name;

    @Override
    public void getData() {
        Scanner sc = new Scanner(System.in);
        this.name = sc.nextLine();
        this.id = sc.nextInt();
    }
}

class HanaBank extends Bank {

    public void display(){
        System.out.println(id);
        System.out.println(name);
        System.out.println(place);
    }
}


public class Ex2 {

    public static void main(String[] args){
        HanaBank hanaBank = new HanaBank();
        hanaBank.getData();
        hanaBank.getPlace();
        hanaBank.display();
    }
}
