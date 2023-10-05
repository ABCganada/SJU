package static_method;

class ComStudent{
    static int id, height;

    static void setData(int a, int b){
        id = a;
        height = b;
    }
}

public class StaticVariables3 {

    public static void main(String[] args){

        ComStudent.setData(2018, 100);
        System.out.println(ComStudent.id);
        System.out.println(ComStudent.height);
    }
}
