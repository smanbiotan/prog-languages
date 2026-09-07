package test_java;

public class BankAccount {

    // Private attributes that store the bank account information
    private String accountNumber;
    private String accountName;
    private double balance;

    // Constructor used to initialize the account information
    public BankAccount(String accountNumber, String accountName, double balance) {
        this.accountNumber = accountNumber;
        this.accountName = accountName;
        this.balance = balance;
    }

    // Deposits money into the bank account
    public void deposit(double amount) {

        // Checks if the deposit amount is greater than zero
        if (amount > 0) {
            balance += amount;
            System.out.println("Deposit successful.");
        } else {
            System.out.println("Invalid deposit amount.");
        }
    }

    // Withdraws money from the bank account
    public void withdraw(double amount) {

        // Checks if the amount is valid and there is enough balance
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            System.out.println("Withdrawal successful.");
        } else {
            System.out.println("Insufficient balance.");
        }
    }

    // Returns the current account balance
    public double checkBalance() {
        return balance;
    }

    // Displays the account information
    public void displayAccountInfo() {

        System.out.println("\nAccount Number: " + accountNumber);
        System.out.println("Account Name: " + accountName);
        System.out.printf("Remaining Balance: %.2f%n", balance);
    }
}