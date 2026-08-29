public class Product {

    private String productName;
    private float price;
    private int quantity;

    public Product(String productName, float price, int quantity) {

        this.productName = productName;
        this.price = price;
        this.quantity = quantity;
    }

    public float calculateTotal() {

        return price * quantity;
    }

    public float calculateDiscount() {

        float total = calculateTotal();

        if (total >= 10000) {
            return total * 0.20f;
        } else if (total >= 5000) {
            return total * 0.15f;
        } else if (total >= 1000) {
            return total * 0.10f;
        } else {
            return 0;
        }
    }

    public float calculateFinalAmount() {

        return calculateTotal() - calculateDiscount();
    }

    public void displayOrder() {

        float total = calculateTotal();
        float discount = calculateDiscount();
        float finalAmount = calculateFinalAmount();

        System.out.println("Product: " + productName);
        System.out.printf("Price: ₱%.2f%n", price);
        System.out.println("Quantity: " + quantity);
        System.out.printf("Total: ₱%.2f%n", total);

        if (total >= 10000) {
            System.out.println("Discount: 20%");
        } else if (total >= 5000) {
            System.out.println("Discount: 15%");
        } else if (total >= 1000) {
            System.out.println("Discount: 10%");
        } else {
            System.out.println("Discount: 0%");
        }

        System.out.printf("Discount Amount: ₱%.2f%n", discount);
        System.out.printf("Final Amount: ₱%.2f%n", finalAmount);
    }
}