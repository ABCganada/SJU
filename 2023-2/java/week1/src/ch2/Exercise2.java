package ch2;

class Hash{

    void printBlank(){
        System.out.print(" ");
    }
    void printHash(){
        System.out.print("#");
    }
}

public class Exercise2 {

    public static void main(String[] args){

        Hash hash = new Hash();

        for(int i=0; i<5; i++){
            for(int j=0; j<i; j++) {
                hash.printBlank();
            }

            for(int j=i*2; j<9; j++){
                hash.printHash();
            }

            System.out.println();
        }

        for(int i=0; i<4; i++){
            for(int j=i; j<3; j++){
                hash.printBlank();
            }
            for(int j=6-i*2; j<9; j++){
                hash.printHash();
            }
            System.out.println();
        }
    }
}
