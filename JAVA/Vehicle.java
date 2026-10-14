package handson_ni_negs;

class Vehicle {
    private String brand;
    private double speed;

    // Constructor
    public Vehicle(String brand, double speed) {
        this.brand = brand;
        this.speed = speed;
    }

    // Getters
    public String getBrand() {
    	
        return brand;
    }

    public double getSpeed() {
    	
        return speed;
    }

    // Display vehicle details
    public void displayDetails() {
    	
        System.out.println("Brand: " + brand);
        System.out.println("Speed: " + speed + " km/h");
    }

    // Method overloading
    public double calculateTravelTime(double distance) {
    	
        return distance / speed;
    }

    public double calculateTravelTime(double distance, double averageSpeed) {
    	
        return distance / averageSpeed;
    }
}