package assginment;

import java.util.Scanner;

class Account{
    private int balance;

    public Account(int i) {
        this.balance = i;
    }

    void credit(int i) {
        this.balance += i;
    }

    boolean debit(int i) {
        if (i > balance) {
            System.out.println("* Debit amount exceeded account balance");
            return false;
        }
        this.balance -= i;
        return true;
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
        if(totalDebit > getBalance()){
            System.out.println("* Debit amount exceeded account balance");
            return false;
        }
        super.debit(totalDebit);
        return true;
    }
}

public class Asgnm1 {

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

        //user input version
        Scanner sc = new Scanner(System.in);
        int balance, interest, transactionFee, withdraw;

        System.out.print("Enter balance: ");
        balance = sc.nextInt();
        System.out.print("Enter interest rate: ");
        interest = sc.nextInt();

        SavingsAccount savingsAccount1 = new SavingsAccount(balance, interest);
        savingsAccount1.CalculateInterest();
        System.out.println(savingsAccount1.getBalance());

        System.out.print("Enter balance: ");
        balance = sc.nextInt();
        System.out.print("Enter transaction fee: ");
        transactionFee = sc.nextInt();
        System.out.print("Enter withdraw: ");
        withdraw = sc.nextInt();

        CheckingAccount checkingAccount1 = new CheckingAccount(balance, transactionFee);
        checkingAccount1.debit(withdraw);
        System.out.println(checkingAccount1.getBalance());
    }
}
