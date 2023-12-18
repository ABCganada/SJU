package week9;

interface GeometricObject {
    void getPerimeter(double r);
    double getArea();
}

interface Resizable {
    void resize(int percentage);
}

class Circle implements GeometricObject {

    protected double r;

    public void testCircle() {
        System.out.println("Circle's radius: "  +r);
        System.out.println("Circle's area: " + getArea());
    }

    @Override
    public void getPerimeter(double r) {
        this.r = r;
    }

    @Override
    public double getArea() {
        return r * r * Math.PI;
    }
}

class ResizableCircle extends Circle implements Resizable{

    public void testResizableCircle() {
        System.out.println("Circle's radius: "  + r);
        System.out.println("Circle's area: " + getArea());
    }

    @Override
    public void resize(int percentage) {
        r = r * (1 + percentage / 100.0);
    }
}

public class Q5 {

    public static void main(String[] args) {

        Circle circle = new Circle();
        circle.getPerimeter(10);
        circle.testCircle();

        ResizableCircle resizableCircle = new ResizableCircle();
        resizableCircle.getPerimeter(circle.r);
        resizableCircle.resize(20);
        resizableCircle.testResizableCircle();
    }
}
