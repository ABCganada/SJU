package week9;

interface manager {

    public void getData(int id, String name);
}

class Branch {
    String place;

    public Branch(String place) {
        this.place = place;
    }

    public String getPlace() {
        return place;
    }
}

class Bank extends Branch implements manager {
    int id;
    String name;

    public Bank(String place) {
        super(place);
    }

    @Override
    public void getData(int id, String name) {
        this.id = id;
        this.name = name;
    }
}

class HanaBank extends Bank {
    String bankName;

    public HanaBank(String place, String bankName) {
        super(place);
        this.bankName = bankName;
    }
}

public class Q4 {

    public static void main(String[] args) {

        HanaBank hanaBank = new HanaBank("Seoul", "Hana bank");
        hanaBank.getData(1234, "John Doe");

        System.out.println("Bank Name: " + hanaBank.bankName);
        System.out.println("Bank Place: " + hanaBank.place);
        System.out.println("Manager Id: " + hanaBank.id);
        System.out.println("Manager Name: " + hanaBank.name);
    }
}
