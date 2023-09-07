package ch2;

class JavaPrint{
    void printJ(){
        System.out.print("J");
    }
    void printV1(){
        System.out.print("V");
    }
    void printV2(){
        System.out.print("v");
    }
    void printA(){
        System.out.print("a");
    }
    void printTap(){
        System.out.print("    ");
    }
    void printBlank(){
        System.out.print(" ");
    }
}

public class Exercise1 {

    public static void main(String[] args){

        JavaPrint javaPrint = new JavaPrint();

        javaPrint.printBlank();
        javaPrint.printBlank();
        javaPrint.printJ();
        javaPrint.printTap();
        javaPrint.printA();
        javaPrint.printBlank();
        javaPrint.printBlank();
        javaPrint.printV2();
        javaPrint.printTap();
        javaPrint.printV2();
        javaPrint.printBlank();
        javaPrint.printA();
        System.out.println();

    }
}
