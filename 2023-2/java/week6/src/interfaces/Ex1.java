package interfaces;

interface Student{
    public void getInfo(int id, int weight);
    public void display();
}

public class Ex1 implements Student{

    int id;
    int weight;

    @Override
    public void getInfo(int id, int weight) {
        this.id = id;
        this.weight = weight;
    }

    @Override
    public void display() {
        System.out.println(id+"\n"+weight);
    }

    public static void main(String[] args){
        Ex1 ex1 = new Ex1();
        ex1.getInfo(2022, 70);
        ex1.display();
    }
}
