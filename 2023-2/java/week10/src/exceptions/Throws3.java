package exceptions;


class Division1 {
    public int division(int a, int b)throws ArithmeticException{
        int result= a/b;
        return result;
    }
}

public class Throws3 {

    public static void main(String[] args) throws ArithmeticException {
        Division1 division = new Division1();
        System.out.println(division.division(10, 2));
    }
}
