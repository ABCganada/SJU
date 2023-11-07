package assignment;

class Account{
    private int balance;

    public Account(int i) {
        this.balance = i;
    }

    void credit(int i) {
        this.balance += i;
    }

    boolean debit(int withdraw) {
        try {
            if (withdraw > balance) {
                throw new Exception("low balance");
            }
            balance -= withdraw;
            return true;
        } catch (Exception e) {
            System.out.println(e);
            return false;
        }
    }

    public int getBalance() {
        return balance;
    }
}

class SavingsAccount extends Account {
    int interestRate;

    public SavingsAccount(int balance, int interest) {
        super(balance);
        this.interestRate = interest;
    }

    public void CalculateInterest() {
        double interest = getBalance() * (interestRate / 100.0);
        credit((int)interest);
    }
}

class CheckingAccount extends Account {
    int transactionFee;

    public CheckingAccount(int balance, int transactionFee) {
        super(balance);
        this.transactionFee = transactionFee;
    }

    @Override
    boolean debit(int i) {
        int totalDebit = i + transactionFee;

        try {
            if(totalDebit > getBalance()){
                throw new Exception("low balance!!");
            }
            super.debit(totalDebit);
            return true;
        } catch (Exception e){
            System.out.println(e);
            return false;
        }
    }
}

public class BankSystem {

    public static void main(String[] args){
        SavingsAccount savingsAccount = new SavingsAccount(5000, 10);
        savingsAccount.CalculateInterest();
        System.out.println(savingsAccount.getBalance());

        CheckingAccount checkingAccount = new CheckingAccount(3000, 1300);
        checkingAccount.debit(1200);
        System.out.println(checkingAccount.getBalance());

        CheckingAccount checkingAccount2 = new CheckingAccount(3000, 1300);
        checkingAccount2.debit(1900);
        System.out.println(checkingAccount2.getBalance());
    }
}
