package week1;

public class Q3 {

    public static void main(String[] args){

        for(int i=0; i<5; i++){
            for(int j=0; j<i; j++){
                System.out.print(" ");
            }
            for(int j=i*2; j<9; j++){
                System.out.print("#");
            }
            System.out.println();
        }

        for(int i=3; i>=0; i--){
            for(int j=0; j<i; j++){
                System.out.print(" ");
            }
            for(int j=i*2; j<9; j++){
                System.out.print("#");
            }
            System.out.println();
        }
    }
}
