package this_reference;

class Box2{
    private int l, b, h;

    void setDimension(int l, int b, int h){ //instance method
        this.l=l;
        this.b=b;
        this.h=h;
    }

    void display(){
        System.out.println(l);
        System.out.println(b);
        System.out.println(h);
    }
}

public class ThisReference2 {

    public static void main(String[] args){ //static method

        Box2 obj = new Box2();
        obj.setDimension(10,20,30); //caller object
        obj.display();
    }
}
