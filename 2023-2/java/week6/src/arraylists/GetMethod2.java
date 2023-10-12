package arraylists;

import java.util.ArrayList;

public class GetMethod2 {

    public static void main(String[] args){

        ArrayList<String> list = new ArrayList<>();
        list.add("David");
        list.add("Sejong");
        list.add("University");
        list.add("Ryan");
        list.add(1, "seoul");

        for (int i = 0; i < list.size(); i++) {
            /**
             * get()
             * */
            System.out.println(list.get(i));
        }
    }
}
