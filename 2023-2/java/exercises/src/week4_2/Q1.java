package week4_2;

import java.util.Scanner;

interface Student{
    void getInfo(int id, int weight);
    void display();
}

class Computer implements Student{

    int id, weight;

    @Override
    public void getInfo(int id, int weight) {
        this.id = id;
        this.weight = weight;
    }

    @Override
    public void display() {
        System.out.println(id);
        System.out.println(weight);
    }
}

public class Q1 {

    public static void main(String[] args){

        Computer computer = new Computer();
        Scanner sc = new Scanner(System.in);

        int id = sc.nextInt();
        int weight = sc.nextInt();

        computer.getInfo(id, weight);
        computer.display();
    }
}
