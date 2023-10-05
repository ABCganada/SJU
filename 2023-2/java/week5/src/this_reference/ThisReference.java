package this_reference;

class Box{
    private int l, b, h;

    void setDimension(int x, int y, int z){
        l=x;
        b=y;
        h=z;
    }

    void display(){
        System.out.println(l);
        System.out.println(b);
        System.out.println(h);
    }
}

public class ThisReference {

    public static void main(String[] args){

        Box obj = new Box();
        obj.setDimension(10,20,30);
        obj.display();
    }
}
