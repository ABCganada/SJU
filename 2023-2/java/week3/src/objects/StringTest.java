package objects;

public class StringTest {

    public static void main(String[] args){

        String animal1 = new String("Horse"); // new operator 없어도 된다 Stirng은
        String animal2 = new String("Fly");
        String newCreature;
        newCreature = animal1 + animal2;
        System.out.println(newCreature.equals("HorseFly"));
        System.out.println(newCreature.equals("horsefly"));

        System.out.println(newCreature.equalsIgnoreCase("horsefly"));
        System.out.println(newCreature.charAt(7));
    }
}
