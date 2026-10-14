package handson_ni_negs;

class RegularEmployee extends Employee {
	
    private double monthlySalary;
    private String department;

    // Constructor
    public RegularEmployee(String employeeName, int employeeId, double monthlySalary, String department) {
    	
        super(employeeName, employeeId);
        this.monthlySalary = monthlySalary;
        this.department = department;
    }

    // Method overriding
    @Override
    public void displayInfo() {
    	
        System.out.println("Employee Type: Regular Employee");
        super.displayInfo();
        System.out.println("Monthly Salary: " + monthlySalary);
        System.out.println("Department: " + department);
    }

    // Method overloading
    public double calculateSalary() {
    	
        return monthlySalary;
    }

    public double calculateSalary(double bonus) {
    	
        return monthlySalary + bonus;
    }
}