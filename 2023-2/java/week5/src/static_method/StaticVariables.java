package static_method;

public class StaticVariables {

    static int id, height;

    void getData(int a, int b){
        id = a;
        height = b;
    }

    public static void main(String[] args){

        StaticVariables obj = new StaticVariables();
        obj.getData(2019, 76);

        System.out.println(id);
        System.out.println(height);
    }
}
