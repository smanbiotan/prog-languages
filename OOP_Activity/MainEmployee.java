import java.util.Scanner;

public class MainEmployee {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        System.out.print("Enter Employee Name: ");
        String name = input.nextLine();

        System.out.print("Enter Hourly Rate: ");
        float rate = input.nextFloat();

        System.out.print("Enter Hours Worked: ");
        float hours = input.nextFloat();

        PS_Employee emp1 = new PS_Employee(name, rate, hours);

        emp1.displayEmployeeInfo();

        input.close();
    }
}
