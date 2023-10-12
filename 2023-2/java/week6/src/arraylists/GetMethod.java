package arraylists;

import java.util.ArrayList;

public class GetMethod {

    public static void main(String[] args){
        ArrayList<String> list = new ArrayList<>(10);
        list.add("David");
        list.add("Sejong");
        list.add("University");
        list.add("Ryan");
        list.add(1, "seoul");

        System.out.println(list);

        /**
         * get()
         * */
        System.out.println(list.get(1));
    }
}
