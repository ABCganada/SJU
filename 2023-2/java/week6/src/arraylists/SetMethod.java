package arraylists;

import java.util.ArrayList;

public class SetMethod {

    public static void main(String[] args){

        ArrayList<String> list = new ArrayList<>(10);
        list.add("Sejong");
        list.add("University");
        list.add("Ryan");
        list.add(1, "seoul");
        /**
         * set()
         * */
        list.set(2, "Korea");

        for(int i=0; i<list.size(); i++){
            System.out.println(list.get(i));
        }
    }
}
