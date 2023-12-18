package week11_1;

class Account {
    private double balance;

    public Account(double balance) {
        this.balance = balance;
    }

    public void credit(double amount) {
        try {
            if (balance >= 1000) {
                balance += amount;
            } else {
                throw new Exception();
            }
        } catch (Exception e) {
            System.out.println("Deposit is less than 1000");
        } finally {
            System.out.println(">> credit operation done");
        }
    }

    public void debit(double amount) {
        try {
            if (balance >= amount && balance >= 1000) {
                balance -= amount;
            } else {
                throw new Exception();
            }
        } catch (Exception e) {
            System.out.println("Debit amount exceeded account balance");
        } finally {
            System.out.println(">> debit operation done");
        }
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }
}

class SavingsAccount extends Account {
    double interest;

    public SavingsAccount(double balance, double interest) {
        super(balance);
        this.interest = interest;
    }

    public double calculateInterest() {
        return getBalance() * (interest / 100.0);
    }
}

class CheckingAccount extends Account {
    double fee;

    public CheckingAccount(double balance, double fee) {
        super(balance);
        this.fee = fee;
    }

    @Override
    public void credit(double amount) {
        try {
            if (amount - fee >= 0) {
                super.credit(amount - fee);
            } else {
                throw new Exception();
            }
        } catch (Exception e) {
            System.out.println("Transaction fee exceeded credit amount");
        }
    }

    @Override
    public void debit(double amount) {
        super.debit(amount + fee);
    }
}


public class Q1 {

    public static void main(String[] args) {

        SavingsAccount savingsAccount = new SavingsAccount(500, 10);
        double amount = savingsAccount.calculateInterest();
        savingsAccount.credit(amount);
        System.out.println(savingsAccount.getBalance());

        savingsAccount.credit(2000);
        System.out.println(savingsAccount.getBalance());

        CheckingAccount checkingAccount = new CheckingAccount(3000, 1200);
        checkingAccount.credit(1000);
        checkingAccount.debit(1000);
        System.out.println(checkingAccount.getBalance());
        checkingAccount.debit(100);
        System.out.println(checkingAccount.getBalance());
    }
}
