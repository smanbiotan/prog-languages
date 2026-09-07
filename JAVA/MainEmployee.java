package test_java;

import java.util.Scanner;

public class MainEmployee {
    public static void main(String[] args) {

        // Creates a Scanner object to get input from the user
        Scanner input = new Scanner(System.in);

        // Gets the employee's name
        System.out.print("Enter Employee Name: ");
        String name = input.nextLine();

        // Gets the employee's hourly rate
        System.out.print("Enter Hourly Rate: ");
        float rate = input.nextFloat();

        // Gets the number of hours worked
        System.out.print("Enter Hours Worked: ");
        float hours = input.nextFloat();

        // Creates a PS_Employee object using the user's input
        Employee emp1 = new Employee(name, rate, hours);

        // Displays the employee's information and salary details
        emp1.displayEmployeeInfo();

        // Closes the Scanner object
        input.close();
    }
}