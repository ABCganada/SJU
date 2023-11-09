package exceptions;

class Final {
    void display() throws Exception {
        int a = 10;
        int b = 0;
        int result = a / b;
    }
    void output() throws Exception {
        display();
    }
    void finalDisplay() {
        try {
            output();
        } catch (Exception e) {
            System.out.println("Input the correct number");
        }
    }
}

public class Propagation {

    public static void main(String[] args) {
        Final finals = new Final();
        finals.finalDisplay();
    }
}
