package arraylists;

import java.util.ArrayList;

public class ArrayListEx1 {

    public static void main(String[] args){

        ArrayList<String> list = new ArrayList<>();
        list.add("David");
        list.add("Sejong");
        list.add("10");
        list.add(1, "30");
        System.out.println(list);

        for(String i : list){
            System.out.print(i + " ");
        }
    }
}
