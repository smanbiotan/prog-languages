import java.util.Scanner;

public class test{
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("Enter your Name: ");
    String f_name = scanner.nextLine();

    System.out.print("Enter your Address: ");
    String address = scanner.nextLine();

    System.out.print("Enter your Birthday (MM/DD/YYYY): ");
    String birthday = scanner.nextLine();

    System.out.print("Enter your Email: ");
    String email = scanner.nextLine();

    System.out.print("Enter your Cellphone Number (+63): ");
    long cp_number = scanner.nextLong();
    scanner.nextLine();
  
    System.out.print("Enter your Moto: ");
    String moto = scanner.nextLine();

    System.out.println();

    System.out.println("Name: " + f_name);
    System.out.println("Address: " + address);
    System.out.println("Birthday: " + birthday);
    System.out.println("Email: " + email);
    System.out.println("CP: " + cp_number);
    System.out.println("Moto: " + moto);

  }
}