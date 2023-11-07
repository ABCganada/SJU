package exceptions;

import java.util.Scanner;

class Bank {
    int deposit;

    Bank() {
        deposit = 3000;
    }

    void withdraw() {
        int withdraw;
        System.out.print("Enter amount to withdraw: ");
        try {
            Scanner sc = new Scanner(System.in);
            withdraw = sc.nextInt();
            if (withdraw > deposit) {
                throw new Exception("low balance");
            }
            System.out.println("Remaining Balance: " + (deposit - withdraw));
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}

public class Throw3 {

    public static void main(String[] args){
        Bank bank = new Bank();
        bank.withdraw();
    }
}
