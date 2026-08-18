public class Employee {

    String name;
    String employeeID;
    String position;
    int salary;

    public Employee(String name, String employeeID, String position, int salary) {

        this.name = name;
        this.employeeID = employeeID;
        this.position = position;
        this.salary = salary;
    }

    public int calculateAnnualSalary() {

        return salary * 12;
    }

    public void displayInfo() {

        System.out.println("Employee Information");
        System.out.println("Name: " + name);
        System.out.println("Employee ID: " + employeeID);
        System.out.println("Position: " + position);
        System.out.println("Monthly Salary: " + salary);
        System.out.println("Annual Salary: " + calculateAnnualSalary());
        System.out.println();
    }

}