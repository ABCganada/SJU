package arraylists;

import java.util.ArrayList;
import java.util.Scanner;

public class ArrayListEx2 {

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Size of array:");
        int n = sc.nextInt();
        ArrayList<Integer> list = new ArrayList<>(n);

        for(int i=0; i<n; i++){
            list.add(sc.nextInt());
        }

        for(int i : list){
            System.out.print(i + " ");
        }

        System.out.println("\n" + list);
    }
}
