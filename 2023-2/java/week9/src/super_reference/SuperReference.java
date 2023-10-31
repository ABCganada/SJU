package super_reference;

class Upper
{
    void message(){
        System.out.println("This is Upper class");
    }
}
class Lower extends Upper
{
    void message(){
        System.out.println("This is Lower class");
    }
    // Note that display() is only in Lower class
    void display(){
        // will invoke or call current class message() method
        message();
        // will invoke or call parent class message() method
        super.message();
    }
}

public class SuperReference {

    public static void main(String[] args){
        Lower lower = new Lower();

        lower.display();
    }
}
