package week6_2;

import java.util.Scanner;

class AirLine{
    public boolean[] seat;
    private int f;
    private int e;

    public AirLine(int n){
        f = 0;
        e = 5;
        seat = new boolean[n];
        for(int i=0; i<seat.length; i++){
            seat[i] = false;
        }
    }

    public boolean reserveFirst(){
        if(f == 5){
            System.out.println("First is full. Do you wanna reserve Economy class?");
            return false;
        }
        seat[f++] = true;
        return true;
    }
    public boolean reserveEconomy(){
        if(e == 10){
            System.out.println("Economy is full. Do you wanna reserve First class?");
            return false;
        }
        seat[e++] = true;
        return true;
    }
}

public class Q1 {

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        AirLine airLine = new AirLine(10);

        int reserve;
        String ans;

        for(int i=0; i<10; i++){
            reserve = sc.nextInt();

            if(reserve == 1){
                if(!airLine.reserveFirst()){
                    ans = sc.nextLine();
                    if(ans.equals("yes")){
                        airLine.reserveEconomy();
                    }
                }
            }else{
                if(!airLine.reserveEconomy()){
                    ans = sc.nextLine();
                    if(ans.equals("yes")){
                        airLine.reserveFirst();
                    }
                }
            }
        }

        for(int i=0; i<airLine.seat.length; i++){
            System.out.print(airLine.seat[i] + " ");
        }
        System.out.println();
    }
}
