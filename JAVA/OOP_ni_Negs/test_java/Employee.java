package test_java;

public class Employee {

    // Private attributes that store the employee's information
    private String name;
    private float rate;
    private float hours;

    // Constructor used to initialize the employee's attributes
    public Employee(String name, float rate, float hours) {
        this.name = name;
        this.rate = rate;
        this.hours = hours;
    }

    // Calculates the employee's regular pay
    public float calculateRegularPay() {

        // If the employee worked 40 hours or less,
        // all hours are paid at the regular rate
        if (hours <= 40) {
            return rate * hours;
        } else {
            // Only the first 40 hours are counted as regular pay
            return rate * 40;
        }
    }

    // Calculates the employee's overtime pay
    public double calculateOvertimePay() {

        // Overtime applies to hours worked beyond 40
        if (hours > 40) {
            return (hours - 40) * rate * 1.5;
        } else {
            // No overtime pay if the employee worked 40 hours or less
            return 0;
        }
    }

    // Calculates the employee's total salary
    public double calculateSalary() {

        // Total salary is regular pay plus overtime pay
        return calculateRegularPay() + calculateOvertimePay();
    }

    // Displays the employee's information and salary details
    public void displayEmployeeInfo() {

        System.out.printf("Employee Name: %s%n", name);
        System.out.printf("Hourly Rate: %.2f%n", rate);
        System.out.printf("Hours Worked: %.0f%n", hours);

        System.out.println();

        // Displays the calculated regular pay
        System.out.printf("Regular Pay: %.2f%n", calculateRegularPay());

        // Displays the calculated overtime pay
        System.out.printf("Overtime Pay: %.2f%n", calculateOvertimePay());

        // Displays the total salary
        System.out.printf("Total Salary: %.2f%n", calculateSalary());
    }
}