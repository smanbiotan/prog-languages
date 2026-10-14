package handson_ni_negs;

class Employee {
	
    private String employeeName;
    private int employeeId;

    // Constructor
    public Employee(String employeeName, int employeeId) {
    	
        this.employeeName = employeeName;
        this.employeeId = employeeId;
    }
    
    // Getters
    public String getEmployeeName() {
    	
        return employeeName;
    }

    public int getEmployeeId() {
    	
        return employeeId;
    }

    // Display employee information
    public void displayInfo() {
    	
        System.out.println("Employee Name: " + employeeName);
        System.out.println("Employee ID: " + employeeId);
    }
}
