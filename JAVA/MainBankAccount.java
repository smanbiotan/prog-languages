package test_java;

import java.util.Scanner;

public class MainBankAccount {
    public static void main(String[] args) {

        // Creates a Scanner object to get input from the user
        Scanner input = new Scanner(System.in);

        // Gets the account number
        System.out.print("Enter Account Number: ");
        String accountNumber = input.nextLine();

        // Gets the account name
        System.out.print("Enter Account Name: ");
        String accountName = input.nextLine();

        // Gets the initial account balance
        System.out.print("Enter Initial Balance: ");
        double balance = input.nextDouble();

        // Creates a BankAccount object using the user's input
        BankAccount account = new BankAccount(
                accountNumber,
                accountName,
                balance
        );

        // Gets the deposit amount and adds it to the account
        System.out.print("Enter Deposit Amount: ");
        double depositAmount = input.nextDouble();
        account.deposit(depositAmount);

        // Gets the withdrawal amount and subtracts it from the account
        System.out.print("Enter Withdrawal Amount: ");
        double withdrawAmount = input.nextDouble();
        account.withdraw(withdrawAmount);

        // Displays the final account information
        account.displayAccountInfo();

        // Closes the Scanner object
        input.close();
    }
}