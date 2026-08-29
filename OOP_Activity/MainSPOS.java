import java.util.Scanner;
public class MainSPOS{

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        System.out.print("Enter Product Name: ");
        String productName = input.nextLine();

        System.out.print("Enter Price: ");
        float price = input.nextFloat();

        System.out.print("Enter Quantity: ");
        int quantity = input.nextInt();
        System.out.println();

        Product product = new Product(productName, price, quantity);

        product.displayOrder();

        input.close();
    }
}