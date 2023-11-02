package polymorphism;

class Input{

    void big(int a, int b) {
        System.out.println(a > b ? a : b);
    }

    void big(float a, float b) {
        System.out.println(a > b ? a : b);
    }
}

public class Overload2 {

    public static void main(String[] args) {
        Input input = new Input();
        input.big(10, 20);
        input.big(10.5f, 10f);
    }
}
