package arraylists.exercise;

import java.util.Scanner;

/**
 * (항공사 예약 시스템)
 * 작은 항공사가 방금 새로운 자동 예약 시스템을 위한 컴퓨터를 구입했습니다.
 * 당신은 새로운 시스템을 개발하라는 요청을 받았습니다.
 * 항공사의 유일한 비행기(정원: 10석)의 각 항공편에 좌석을 할당하는 앱을 작성해야 합니다.
 *
 * 다음 대안을 표시하세요
 * 퍼스트 클래스의 경우 1을 입력하고 이코노미의 경우 2를 입력하십시오.
 * 사용자가 1을 입력하는 경우, 앱은 일등석 섹션(좌석 1-5)에 좌석을 할당해야 합니다.
 * 사용자가 2를 입력하는 경우, 앱은 이코노미 섹션(6-10석)에 좌석을 할당해야 합니다.
 * 비행기의 좌석 차트를 나타내기 위해 boolean 유형의 1차원 배열을 사용하세요.
 * 배열의 모든 요소를 false로 초기화하여 모든 좌석이 비어 있음을 나타냅니다.
 * 각 좌석이 할당됨에 따라, 좌석을 더 이상 사용할 수 없음을 나타내기 위해
 * 배열의 해당 요소를 true로 설정하십시오.
 * 당신의 앱은 이미 할당된 좌석을 할당해서는 안 됩니다.
 * 이코노미 섹션이 가득 찼을 때, 당신의 앱은 그 사람에게 일등석 섹션에 배치할 수 있는지
 * 물어봐야 합니다(그리고 그 반대의 경우도 마찬가지입니다).
 * 그렇다면, 적절한 좌석 배정을 하세요.
 * 그렇지 않다면, "다음 항공편은 3시간 후에 출발합니다"라는 메시지를 표시하세요. "
 * */

class Airline{

    public boolean[] reservation;
    private int economyIdx;
    private int firstIdx;

    public Airline(int n){
        economyIdx = 5;
        firstIdx = 0;
        reservation = new boolean[n];
        for(int i=0; i<n; i++){
            reservation[i] = false;
        }
    }

    public boolean reserveEconomy(){

        if(economyIdx == 10){
            System.out.println("Economy section is full. Enter \"y\" if you want to reserve First.");
            return false;
        }
        reservation[economyIdx++] = true;
        return true;
    }

    public boolean reserveFirst(){

        if(firstIdx == 5){
            System.out.println("First section is full. Enter \"y\" if you want to reserve Economy.");
            return false;
        }
        reservation[firstIdx++] = true;
        return true;
    }
}

public class Ex2 {

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        Airline airline = new Airline(10);
        String answer;

        for(int i=0; i<10; i++){
            int reserve = sc.nextInt();

            if(reserve==1){
                if(!airline.reserveFirst()){
                    answer = sc.next();
                    if(answer.equals("y")){
                        airline.reserveEconomy();
                    }
                }
            } else{
                if(!airline.reserveEconomy()){
                    answer = sc.next();
                    if (answer.equals("y")) {
                        airline.reserveFirst();
                    }
                }
            }
        }

        for(int i=0; i<10; i++){
            System.out.print(airline.reservation[i] + " ");
        }
    }
}
