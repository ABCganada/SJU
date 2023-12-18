package week9;

class Person {
    String name;

    public Person(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }
}

class Vehicle {
    String name;
    int cylinderNum;
    Person owner;

    public Vehicle(String name, int cylinderNum, Person owner) {
        this.name = name;
        this.cylinderNum = cylinderNum;
        this.owner = owner;
    }

    public void printInfo() {
        System.out.println("Vehicle Manufacturer: " + name);
        System.out.println("Vehicle Cylinders: " + cylinderNum);
        System.out.println("Vehicle Owner: " + owner.getName());
    }
}

class Truck extends Vehicle {
    double capacity;

    public Truck(String name, int cylinderNum, Person owner, double capacity) {
        super(name, cylinderNum, owner);
        this.capacity = capacity;
    }

    public void printInfo() {
        System.out.println("Truck Manufacturer: " + name);
        System.out.println("Truck Cylinders: " + cylinderNum);
        System.out.println("Truck Owner: " + owner.getName());
        System.out.println("Truck Capacity: " + capacity);
    }
}

public class Q3 {

    public static void main(String[] args) {

        Person person = new Person("John Doe");
        Truck truck = new Truck("Toyota", 4, person, 5);

        truck.printInfo();
    }
}
