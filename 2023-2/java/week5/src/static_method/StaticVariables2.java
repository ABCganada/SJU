package static_method;

public class StaticVariables2 {

    static int square(int x){
        return x*x;
    }

    public static void main(String[] args){

        int res = StaticVariables2.square(10);
        System.out.println(res);
    }
}
