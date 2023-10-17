package iterators;

import java.util.ArrayList;
import java.util.Iterator;

public class IteratorHasNext {
    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<>();
        list.add("A");
        list.add("B");
        list.add("C");
        list.add("D");
        System.out.println(list);

        //Get iterator
        Iterator<String> iterator = list.iterator();
        //Iterate over all elements
        while (iterator.hasNext()) {
            //Get current element
            String value = iterator.next();
            System.out.println(value);
            //Remove element
            if (value.equals("B")) {
                iterator.remove();
            }
        }
        System.out.println(list);
    }

}
