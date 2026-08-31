public class PS_Employee {

    private String name;
    private float rate;
    private float hours;

    public PS_Employee(String name, float rate, float hours) {
        this.name = name;
        this.rate = rate;
        this.hours = hours;
    }

    public float calculateRegularPay() {

        if(hours <= 40) {
            return rate * hours;
        } else {
            return rate * 40;
        }
    }

    public double calculateOvertimePay() {

        if (hours > 40) {
            return (hours - 40) * rate * 1.5;
        } else {
            return 0;
        }
    }

    public double calculateSalary() {

        return calculateRegularPay() + calculateOvertimePay();
    }

    public void displayEmployeeInfo() {

        System.out.printf("Employee Name: %s%n", name);
        System.out.printf("Hourly Rate: %.2f%n", rate);
        System.out.printf("Hours Worked: %.0f%n", hours);
        System.out.println();
        System.out.printf("Regular Pay: %.2f%n", calculateRegularPay());
        System.out.printf("Overtime Pay: %.2f%n", calculateOvertimePay());
        System.out.printf("Total Salary: %.2f%n", calculateSalary());
    }


}
