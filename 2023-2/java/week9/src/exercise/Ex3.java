package exercise;

interface GeometricObject{
    double getParameter();
    double getArea();
}

interface Resizable{
    void resize(double percentage);
}

class Circle implements GeometricObject{

    protected double radius;

    Circle(double radius) {
        this.radius = radius;
    }

    @Override
    public double getParameter() {
        return 2 * Math.PI * radius;
    }

    @Override
    public double getArea() {
        return Math.PI * Math.pow(radius, 2);
    }
}

class ResizableCircle extends Circle implements Resizable{

    public ResizableCircle(double radius){
        super(radius);
    }

    @Override
    public void resize(double percentage) {
        this.radius = this.radius * (percentage / 100);
    }
}

public class Ex3 {

    public static void main(String[] args){

        ResizableCircle circle = new ResizableCircle(10);
        System.out.println(circle.radius);
        System.out.println(circle.getParameter());
        System.out.println(circle.getArea());

        circle.resize(50);
        System.out.println(circle.radius);
        System.out.println(circle.getParameter());
        System.out.println(circle.getArea());
    }
}
