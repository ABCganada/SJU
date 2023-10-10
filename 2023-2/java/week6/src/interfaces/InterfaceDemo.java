package interfaces;

interface Animal{
    public void animalSound();
    public void sleep();
}

class Pig implements Animal{
    @Override
    public void animalSound() {
        System.out.println("khu khu");
    }

    @Override
    public void sleep() {
        System.out.println("Zzz");
    }
}

public class InterfaceDemo {

    public static void main(String[] args){
        Pig pig = new Pig();
        pig.animalSound();
        pig.sleep();
    }
}
