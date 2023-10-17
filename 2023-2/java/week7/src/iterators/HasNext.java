package iterators;

import java.util.ArrayList;
import java.util.Iterator;

public class HasNext {

    public static void main(String[] args) {

        ArrayList<Integer> list = new ArrayList<>();

        list.add(10);
        list.add(15);
        list.add(30);
        list.add(20);
        list.add(5);

        System.out.println(list);

        Iterator<Integer> iter = list.iterator();

        while(iter.hasNext()){
            System.out.println(iter.next());
        }
    }
}
