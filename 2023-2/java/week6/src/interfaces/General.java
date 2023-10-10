package interfaces;

interface person{
    void input(int a, String name);
    void display();
}

public class General implements person {

    int id;
    String name;

    @Override
    public void input(int a, String name) {
        id = a;
        this.name = name;
    }

    @Override
    public void display() {
        System.out.println(id + "\n" + name);
    }

    public static void main(String[] args){
        General obj = new General();
        obj.input(2022, "Sejong");
        obj.display();
    }
}
