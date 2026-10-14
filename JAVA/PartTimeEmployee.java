package handson_ni_negs;

class PartTimeEmployee extends Employee {
	
    private int hoursWorked;
    private double hourlyRate;

    // Constructor
    public PartTimeEmployee(String employeeName, int employeeId, int hoursWorked, double hourlyRate) {
    	
        super(employeeName, employeeId);
        this.hoursWorked = hoursWorked;
        this.hourlyRate = hourlyRate;
    }

    // Method overriding
    @Override
    public void displayInfo() {
    	
        System.out.println("Employee Type: Part-Time Employee");
        super.displayInfo();
        System.out.println("Hours Worked: " + hoursWorked);
        System.out.println("Hourly Rate: " + hourlyRate);
    }

    // Method overloading
    public double calculateSalary() {
    	
        return hoursWorked * hourlyRate;
    }

    public double calculateSalary(int overtimeHours, double overtimeRate) {
    	
        return (hoursWorked * hourlyRate) + (overtimeHours * overtimeRate);
    }
}