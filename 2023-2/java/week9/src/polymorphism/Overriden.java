package polymorphism;

class Upper {

    void message()
    {
        System.out.println("This is Upper class");
    }
}

class Lower extends Upper {

    //same method of the super class is used
    @Override
    void message()
    {
        super.message();
        System.out.println("This is Lower class");
    }
}

public class Overriden {

    public static void main(String[] args) {
        Lower s = new Lower();

        // calling message() of Lower
        s.message();
    }
}
