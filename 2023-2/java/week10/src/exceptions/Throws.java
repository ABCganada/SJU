package exceptions;

import java.util.Scanner;

public class Throws {

    static void Method() throws ArithmeticException, NullPointerException
    {
        // Statements that might throw an exception
    }
    public static void main(String args[]) {
        try {
            Method();
        } catch (ArithmeticException e) {
            // Exception handling statements
        } catch (NullPointerException e) {
            // Exception handling statements
        }
    }
}
