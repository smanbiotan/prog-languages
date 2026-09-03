public class BankAccount {

    private String accountNumber;
    private String accountName;
    private float balance;

    public BankAccount(String accountNumber, String accountName, float balance) {
        this.accountNumber = accountNumber;
        this.accountName = accountName;
        this.balance = balance;
    }

    public void deposit(float amount) {

        if (amount > 0) {
            balance += amount;
            System.out.println("Deposit successful.");
        } else {
            System.out.println("Invalid deposit amount.");
        }
    }

    public void withdraw(float amount) {

        if (amount > 0 && amount <= balance) {
            balance -= amount;
            System.out.println("Withdrawal successful.");
        } else {
            System.out.println("Insufficient balance.");
        }
    }

    public float checkBalance() {
        return balance;
    }

    public void displayAccountInfo() {

        System.out.print("Account Number: " + accountNumber);
        System.out.print("Account Name: " + accountName);
        System.out.print("Remaining Balance: " + balance);
    }
}