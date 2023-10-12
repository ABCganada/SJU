package arraylists;

import java.util.ArrayList;

public class AddMethod {

    public static void main(String[] args){

        ArrayList<String> list = new ArrayList<>(10);
        list.add("David");
        list.add("Sejong");
        list.add("Univ");
        list.add("Ryan");
        list.add(1, "seoul");

        System.out.println(list);
    }
}
