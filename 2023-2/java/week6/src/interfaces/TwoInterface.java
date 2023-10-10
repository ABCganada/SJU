package interfaces;

interface First {
    public void myMethod();
}

interface Second{
    public void otherMethod();
}

public class TwoInterface implements First, Second{

    @Override
    public void myMethod() {
        System.out.println("Some text ..");
    }

    @Override
    public void otherMethod() {
        System.out.println("Some other text ..");
    }

    public static void main(String[] args){
        TwoInterface twoInterface = new TwoInterface();
        twoInterface.myMethod();
        twoInterface.otherMethod();
    }
}
