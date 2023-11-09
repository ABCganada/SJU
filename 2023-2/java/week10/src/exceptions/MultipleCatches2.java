package exceptions;

import java.util.Scanner;

public class MultipleCatches2 {
    public static void main(String[] args) {
        Scanner obj = new Scanner(System.in);
        try {
            int n = Integer.parseInt(obj.nextLine());
            if (100 %n == 0)
                System.out.println(n + "factor");
            else
                System.out.println(n+" not a factor");
        }
        catch (ArithmeticException | NumberFormatException ex)
        {
            System.out.println("Exception is notice " + ex);
        }
    }
}
