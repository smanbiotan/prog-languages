package test_java;
import java.util.Scanner;

public class MainProduct {
    public static void main(String[] args) {

        // Creates a Scanner object to get input from the user
        Scanner input = new Scanner(System.in);

        // Gets the product name from the user
        System.out.print("Enter Product Name: ");
        String productName = input.nextLine();

        // Gets the product price from the user
        System.out.print("Enter Price: ");
        double price = input.nextDouble();

        // Gets the product quantity from the user
        System.out.print("Enter Quantity: ");
        int quantity = input.nextInt();

        // Creates a Product object using the user's input
        Product product = new Product(
                productName,
                price,
                quantity
        );

        // Displays the product order details
        product.displayOrder();

        // Closes the Scanner object
        input.close();
    }
}