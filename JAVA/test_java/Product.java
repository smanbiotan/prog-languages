package test_java;

public class Product {

    // Private attributes that store the product information
    private String productName;
    private double price;
    private int quantity;

    // Constructor used to initialize the product attributes
    public Product(String productName, double price, int quantity) {
        this.productName = productName;
        this.price = price;
        this.quantity = quantity;
    }

    // Calculates the total price before applying the discount
    public double calculateTotal() {
        return price * quantity;
    }

    // Calculates the discount based on the total price
    public double calculateDiscount() {
        // Gets the total price of the order
        double total = calculateTotal();

        // Gives a 20% discount for totals of 10,000 or more
        if (total >= 10000) {
            return total * 0.20;
        }

        // Gives a 15% discount for totals of 9,999 or more
        else if (total >= 9999) {
            return total * 0.15;
        }

        // Gives a 10% discount for totals of 4,999 or more
        else if (total >= 4999) {
            return total * 0.10;
        }

        // No discount for totals below 4,999
        else {
            return 0;
        }
    }

    // Calculates the final amount after subtracting the discount
    public double calculateFinalAmount() {
        return calculateTotal() - calculateDiscount();
    }

    // Displays all the product and order information
    public void displayOrder() {
        System.out.println("\nProduct: " + productName);
        System.out.printf("Price: %.2f%n", price);
        System.out.println("Quantity: " + quantity);
        System.out.printf("Total: %.2f%n", calculateTotal());
        System.out.printf("Discount: %.2f%n", calculateDiscount());
        System.out.printf("Final Amount: %.2f%n", calculateFinalAmount());
    }
}