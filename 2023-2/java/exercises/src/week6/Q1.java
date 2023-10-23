package week6;

import java.util.Scanner;

public class Q1 {

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        int[] arr;

        System.out.print("Enter Size of Array->");
        int n = sc.nextInt();
        arr = new int[n];

        int sum = 0;

        System.out.println("Array length->" + arr.length);
        System.out.println("Enter " + arr.length + " Elements");
        for(int i=0; i< arr.length; i++){
            arr[i] = sc.nextInt();
            sum += arr[i];
        }

        System.out.println("****Output*****");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
        System.out.println("Total->" + sum);
    }
}
