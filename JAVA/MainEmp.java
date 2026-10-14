package handson_ni_negs;

public class MainEmp {
    public static void main(String[] args) {

        // Create one object for each child class
        RegularEmployee regular = new RegularEmployee("Maria Santos", 101, 25000.00, "IT");

        PartTimeEmployee partTime = new PartTimeEmployee("Juan Dela Cruz", 102, 80, 150.00);

        // Display regular employee information
        System.out.println("===== REGULAR EMPLOYEE =====");
        regular.displayInfo();

        System.out.printf("Regular Salary: %.2f%n",
            regular.calculateSalary());

        System.out.printf("Salary with Bonus: %.2f%n",
            regular.calculateSalary(3000.00));

        // Display part-time employee information
        System.out.println("\n===== PART-TIME EMPLOYEE =====");
        partTime.displayInfo();

        System.out.printf("Part-Time Salary: %.2f%n",
            partTime.calculateSalary());

        System.out.printf("Salary with Overtime: %.2f%n",
            partTime.calculateSalary(5, 200.00));
    }
}