package arrays;

import java.util.Scanner;

public class Ex1 {

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of array->");
        int n = sc.nextInt();
        System.out.println("Array length->"+n);
        System.out.println("Enter "+n+" Elements");

        int[] arr = new int[n];
        int total = 0;
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
            total += arr[i];
        }

        System.out.println("****Output****");
        for(int i : arr){
            System.out.print(i+" ");
        }
        System.out.println();
        System.out.println("Total->"+total);
    }
}
