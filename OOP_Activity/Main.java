public class Main {

    public static void main(String[] args) {

        System.out.println("Name: Sherwin Alvin Manbiotan");
        System.out.println("Section: CKHX1");
        System.out.println();

        Employee employee1 = new Employee("Riel AI", "EMP-001", "Software Engineer", 95000);
        Employee employee2 = new Employee("Moca AI", "EMP-002", "Ai Automation Specialist", 85000);

        employee1.displayInfo();
        employee2.displayInfo();
    }
}