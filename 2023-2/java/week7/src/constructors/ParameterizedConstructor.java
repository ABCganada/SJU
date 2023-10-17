package constructors;

class Emp2{
    private String name;

    public Emp2(String name){
        this.name = name;
    }

    public void readName(){
        System.out.println(this.name);
    }
}

public class ParameterizedConstructor {

    public static void main(String[] args){

        Emp2 emp2 = new Emp2("SMG");
        emp2.readName();
    }
}
