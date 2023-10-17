package constructors;

class Fraction {

    private int numerator;
    private int denominator;
    private double quotient;

    public Fraction(int n)
    {
        this(n, 1); //오... 이렇게...
    }

    public Fraction(int n, int d)
    {
        this.numerator = n;
        this.denominator = d;
        this.quotient =
                (double) this.numerator / this.denominator;
    }

    public void printIt()
    {
        System.out.println(this.numerator + " / " +
                this.denominator + " = " + this.quotient);
    } // end printIt
}

public class FractionDriver{

    public static void main(String[] args){
        Fraction fraction1 = new Fraction(3, 4);
        Fraction fraction2 = new Fraction(3);

        fraction1.printIt();
        fraction2.printIt();
    }
}
