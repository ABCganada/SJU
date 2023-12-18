package week9;

class Quadrilateral {
    double x1, y1, x2, y2, x3, y3, x4, y4;

    public Quadrilateral(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
        this.x3 = x3;
        this.y3 = y3;
        this.x4 = x4;
        this.y4 = y4;
    }

    public double getX1() {
        return x1;
    }

    public double getY1() {
        return y1;
    }

    public double getX2() {
        return x2;
    }

    public double getY2() {
        return y2;
    }

    public double getX3() {
        return x3;
    }

    public double getY3() {
        return y3;
    }

    public double getX4() {
        return x4;
    }

    public double getY4() {
        return y4;
    }

    public double calculateArea() {
        return 0.0;
    }
}

class Trapezoid extends Quadrilateral {

    public Trapezoid(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
        super(x1, y1, x2, y2, x3, y3, x4, y4);
    }

    @Override
    public double calculateArea() {
        double base1 = Math.sqrt(Math.pow(getX2() - getX1(), 2) + Math.pow(getY2() - getY1(), 2));
        double base2 = Math.sqrt(Math.pow(getX4() - getX3(), 2) + Math.pow(getY4() - getY3(), 2));
        double h = Math.abs(getY2() - getY1());

        return 1 / 2 * (base1 + base2) * h;
    }
}

class Parallelogram extends Trapezoid {

    public Parallelogram(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
        super(x1, y1, x2, y2, x3, y3, x4, y4);
    }

    @Override
    public double calculateArea() {
        double base = Math.sqrt(Math.pow(getX2() - getX1(), 2) + Math.pow(getY2() - getY1(), 2));
        double h = Math.abs(getY2() - getY1());

        return base * h;
    }
}

class Rectangle extends Parallelogram {

    public Rectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
        super(x1, y1, x2, y2, x3, y3, x4, y4);
    }

    @Override
    public double calculateArea() {
        double length = Math.sqrt(Math.pow(getX2() - getX1(), 2) + Math.pow(getY2() - getY1(), 2));
        double width = Math.sqrt(Math.pow(getX4() - getX1(), 2) + Math.pow(getY4() - getY1(), 2));

        return length * width;
    }
}

class Square extends Rectangle {

    public Square(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
        super(x1, y1, x2, y2, x3, y3, x4, y4);
    }

    @Override
    public double calculateArea() {
        double side = Math.sqrt(Math.pow(getX2() - getX1(), 2) + Math.pow(getY2() - getY1(), 2));

        return side * side;
    }
}

public class Q2 {

    public static void main(String[] args) {
        Trapezoid trapezoid = new Trapezoid(0, 0, 0, 5, 3, 8, 6, 0);
        Parallelogram parallelogram = new Parallelogram(0, 0, 0, 5, 3, 8, 3, 3);
        Rectangle rectangle = new Rectangle(0, 0, 0, 5, 3, 5, 3, 0);
        Square square = new Square(0, 0, 0, 4, 4, 4, 4, 0);

        System.out.println("Trapezoid Area: " + trapezoid.calculateArea());
        System.out.println("Parallelogram Area: " + parallelogram.calculateArea());
        System.out.println("Rectangle Area: " + rectangle.calculateArea());
        System.out.println("Square Area: " + square.calculateArea());
    }
}
