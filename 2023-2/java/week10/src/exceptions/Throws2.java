package exceptions;

class Division {

    int division(int a, int b) throws ArithmeticException {
        int result = a / b;
        return result;
    }
}

class Test extends Division {

}

public class Throws2 {

    public static void main(String[] args) {
        Test test = new Test();

        try {
            System.out.println(test.division(10, 0));
        } catch (Exception e) {
            System.out.println("Exception Caught");
        }
    }
}
