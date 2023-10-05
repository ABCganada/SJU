package this_reference;

public class ThisReference3 {

    static int id;
    static String name;

    void input(int a, String name1){
        id = a;
        name = name1;
        this.display();
    }

    private void display(){
        System.out.println(id + "\n" + name);
    }

    public static void main(String[] args){

        ThisReference3 obj = new ThisReference3();
        obj.input(2022, "Sejong");
        obj.display();
    }
}
