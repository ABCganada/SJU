package ch2.scanner;

import java.util.Scanner;

public class PriceAndQty {

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        System.out.print("Price of purchase item: ");
        double p = sc.nextDouble();

        System.out.print("Quantity: ");
        int q = sc.nextInt();

        System.out.println("Total purchase order = $" + p*q);
    }
}
