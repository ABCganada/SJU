package week10;

class Account {
    private int balance;

    public Account(int balance) {
        if(balance >= 0) {
            this.balance = balance;
        }
    }

    public void credit(int amount) {
        balance += amount;
    }

    public boolean debit(int amount) {
        if (balance < amount) {
            System.out.println("Debit amount exceeded account balance");
            return false;
        } else {
            balance -= amount;
            return true;
        }
    }

    public int getBalance() {
        return balance;
    }
}

class SavingsAccount extends Account {
    int interest;

    public SavingsAccount(int balance, int interest) {
        super(balance);
        this.interest = interest;
    }

    public double calculateInterest() {
        return getBalance() * (interest) / 100.0;
    }
}

class CheckingAccount extends Account {
    int fee;

    public CheckingAccount(int balance, int fee) {
        super(balance);
        this.fee = fee;
    }

    @Override
    public void credit(int amount) {
        super.credit(amount);
    }

    @Override
    public boolean debit(int amount) {

        if (super.getBalance() >= amount + fee) {
            super.debit(amount + fee);
            return true;
        } else {
            System.out.println("Debit amount exceeded account balance");
            return false;
        }
    }
}

public class Q1 {

    public static void main(String[] args) {

        SavingsAccount savingsAccount = new SavingsAccount(5000, 10);
        double interest = savingsAccount.calculateInterest();
        System.out.println(interest);
        savingsAccount.credit((int)interest);
        System.out.println(savingsAccount.getBalance());

        CheckingAccount checkingAccount = new CheckingAccount(3000, 1200);
        checkingAccount.debit(1000);
        System.out.println("After debit: " + checkingAccount.getBalance());
        checkingAccount.debit(1000);
        System.out.println("After debit: " + checkingAccount.getBalance());
    }
}
