package assignment3.q2;

import java.util.Scanner;

class Account{  //base class
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

        try {
            if(totalDebit > getBalance()){
                throw new Exception("Error: low balance!!");
            }
            super.debit(totalDebit);
            return true;
        } catch (Exception e){
            System.out.println(e);
            return false;
        }
    }
}

public class Q2 {

    public static void main(String[] args){
        System.out.println("\n=== Saving account ===");
        SavingsAccount savingsAccount = new SavingsAccount(5000, 10);
        savingsAccount.CalculateInterest();
        System.out.println("account's balance: " + savingsAccount.getBalance());

        System.out.println("\n=== Withdraw account ===");
        CheckingAccount checkingAccount = new CheckingAccount(3000, 1300);
        checkingAccount.debit(1200);
        System.out.println("account's balance: " + checkingAccount.getBalance());

        System.out.println("\n=== Withdraw account ===");
        CheckingAccount checkingAccount2 = new CheckingAccount(3000, 1300);
        checkingAccount2.debit(1900);
        System.out.println("account's balance: " + checkingAccount2.getBalance());

        //user input version
        System.out.println("\n>> >> User Input Test << <<");
        Scanner sc = new Scanner(System.in);
        int balance, interest, transactionFee, withdraw;

        System.out.println("\n=== Saving account ===");
        System.out.print("Enter balance: ");
        balance = sc.nextInt();
        System.out.print("Enter interest rate: ");
        interest = sc.nextInt();

        SavingsAccount savingsAccount1 = new SavingsAccount(balance, interest);
        savingsAccount1.CalculateInterest();
        System.out.println("account's balance: " + savingsAccount1.getBalance());

        System.out.println("\n=== Withdraw account ===");
        System.out.print("Enter balance: ");
        balance = sc.nextInt();
        System.out.print("Enter transaction fee: ");
        transactionFee = sc.nextInt();
        System.out.print("Enter withdraw: ");
        withdraw = sc.nextInt();

        CheckingAccount checkingAccount1 = new CheckingAccount(balance, transactionFee);
        checkingAccount1.debit(withdraw);
        System.out.println("account's balance: " + checkingAccount1.getBalance());
    }
}


