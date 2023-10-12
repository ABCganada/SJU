package arraylists;

import java.util.ArrayList;
import java.util.Scanner;

public class AddAllMethod {

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        System.out.println("size if array : ");
        int n = sc.nextInt();

        ArrayList<Integer> list = new ArrayList<>(n);

        for(int i=0; i<n; i++){
            list.add(sc.nextInt());
        }

        System.out.println("size of 2nd array : ");
        n = sc.nextInt();

        ArrayList<Integer> list2 =  new ArrayList<>(n);

        for (int i = 0; i < n; i++) {
            list2.add(sc.nextInt());
        }

        /**
         * addAll(ArrayList list)
         * */
        list.addAll(list2);
        System.out.println(list);
    }
}
