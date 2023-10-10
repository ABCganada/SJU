package arrays;

public class CraetingArray {

    public static void main(String[] args){
        int[] arr = new int[5];

        arr[0] = 2;
        arr[1] = 3;
        arr[2] = 4;
        arr[3] = 5;
        arr[4] = 6;

        for(int i : arr){
            System.out.println(i);
        }
    }
}
