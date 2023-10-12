package arraylists.exercise;

import java.util.Random;

public class Ex1 {
    /**
     * 1차원 배열을 사용하여 다음 문제를 해결하세요:
     * 각각 8에서 800 사이의 다섯 개의 숫자를 입력하는 앱을 작성하세요.
     * 각 숫자를 읽을 때, 8의 배수인 경우에만 표시하세요.
     * 이 문제를 해결하기 위해 가능한 가장 작은 배열을 사용하세요.
     * 사용자가 각각의 새로운 값을 입력한 후 입력된 전체 값 세트를 표시합니다.
     * */
    public static void main(String[] args){

        Random rand = new Random();
        int n;

        for (int i = 0; i < 5; i++) {
            n = rand.nextInt(793) + 8;
            System.out.println("Enter number : " + n);

        }
    }
}
