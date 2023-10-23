package week6;

import java.util.Scanner;

public class Q2 {

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size: ");
        int n = sc.nextInt();
        float [] arr = new float[n];

        System.out.println("The size of the array: " + arr.length);

        for (int i = 0; i < arr.length; i++) {
            System.out.print("Enter number " + (i+1) + ": ");
            arr[i] = sc.nextFloat();
        }

        System.out.println("The numbers in reverse order:");
        for (int i = arr.length - 1; i >= 0; i--) {
            System.out.print(arr[i]+" ");
        }
        System.out.println();

    }
}
