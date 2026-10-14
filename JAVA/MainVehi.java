package handson_ni_negs;

public class MainVehi {
    public static void main(String[] args) {

        // Create objects
        Car car = new Car("Toyota", 120, 4, "Gasoline");

        Motorcycle motorcycle = new Motorcycle("Honda", 100, 150, false);

        // Runtime polymorphism
        Vehicle vehicle1 = car;
        Vehicle vehicle2 = motorcycle;

        // Display details
        System.out.println("===== CAR DETAILS =====");
        vehicle1.displayDetails();

        System.out.println("\n===== MOTORCYCLE DETAILS =====");
        vehicle2.displayDetails();

        // Vehicle method overloading
        System.out.println("\n===== TRAVEL TIME =====");
        System.out.printf("Travel time: %.2f hours%n",
            car.calculateTravelTime(240));

        System.out.printf("Travel time at 80 km/h: %.2f hours%n",
            car.calculateTravelTime(240, 80));

        // Car method overloading
        System.out.println("\n===== CAR ENGINE =====");
        car.startEngine();
        car.startEngine("Sport");

        // Motorcycle method overloading
        System.out.println("\n===== MOTORCYCLE ENGINE =====");
        motorcycle.startEngine();
        motorcycle.startEngine(true);
    }
}