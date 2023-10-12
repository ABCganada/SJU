package arraylists;

import java.util.ArrayList;
import java.util.Scanner;

public class RemoveMethod {

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        System.out.println("size of array : ");
        int n = sc.nextInt();

        ArrayList<Integer> list = new ArrayList<>(n);

        for(int i=0; i<n; i++){
            list.add(sc.nextInt());
        }

        System.out.println(list);
        /**
         * remove(int idx)
         * */
        System.out.println(list.remove(2));
        System.out.println(list);
    }
}
