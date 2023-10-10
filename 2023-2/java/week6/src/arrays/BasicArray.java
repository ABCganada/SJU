package arrays;

public class BasicArray {

    public static void main(String[] args){

        final int LIMIT = 15, MULTIPLE = 10;

        int[] list = new int[LIMIT];

        for (int idx = 0; idx < LIMIT; idx++) {
            list[idx] = idx * MULTIPLE;
        }

        list[5] = 999;

        for(int value:list){
            System.out.print(value + " ");
        }
    }
}
