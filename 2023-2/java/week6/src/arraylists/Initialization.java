package arraylists;

import java.util.ArrayList;
import java.util.Scanner;

public class Initialization {

    public static void main(String[] args){

        ArrayList<Integer> str = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
        System.out.println(str.size());

        str.add(sc.nextInt());
        System.out.println(str.size());
        str.add(sc.nextInt());
        System.out.println(str.size());
    }
}
