package exceptions;

import java.util.Scanner;

public class MultipleCatches {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        try {
            int n = Integer.parseInt(sc.nextLine());
            if (100 % n == 0) {
                System.out.println(n + " factor");
            } else {
                System.out.println(n + " not a factor");
            }
        } catch (ArithmeticException e) {
            System.out.println("Arithmetic " + e);
        } catch (NumberFormatException e) {
            System.out.println("Number Format Exception " + e);
        }
    }
}
