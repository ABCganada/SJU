package arraylists;

import java.util.ArrayList;
import java.util.Scanner;

public class ClearMethod {

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        System.out.println("size of array : ");
        int n = sc.nextInt();

        ArrayList<Integer> list = new ArrayList<>(n);

        for (int i = 0; i < n; i++) {
            list.add(sc.nextInt());
        }

        for (int i = 0; i < list.size(); i++) {
            System.out.print(list.get(i) + " ");
        }
        System.out.println();

        /**
         * clear()
         * */
        list.clear();

        System.out.println("size of list after clear: " + list.size());
    }
}
