import java.util.Scanner;

public class MainBankAccount {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        System.out.print("Enter Account Number: ");
        String accountNumber = input.nextLine();

        System.out.print("Enter Account Name: ");
        String accountName = input.nextLine();

        System.out.print("Enter Initial Balance: ");
        float balance = input.nextFloat();

        BankAccount bank1 = new BankAccount(
                accountNumber,
                accountName,
                balance
        );

        System.out.print("Enter Deposit Amount: ");
        float deposit = input.nextFloat();

        bank1.deposit(deposit);

        bank1.displayAccountInfo();

        input.close();
    }
}