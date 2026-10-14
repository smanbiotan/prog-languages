package handson_ni_negs;

class Car extends Vehicle {
	
    private int numberOfDoors;
    private String fuelType;

    // Constructor
    public Car(String brand, double speed, int numberOfDoors, String fuelType) {
    	
        super(brand, speed);
        this.numberOfDoors = numberOfDoors;
        this.fuelType = fuelType;
    }

    // Method overriding
    @Override
    public void displayDetails() {
    	
        System.out.println("Vehicle Type: Car");
        super.displayDetails();
        System.out.println("Number of Doors: " + numberOfDoors);
        System.out.println("Fuel Type: " + fuelType);
    }

    // Method overloading
    public void startEngine() {
    	
        System.out.println("Car engine started normally.");
    }

    public void startEngine(String mode) {
    	
        System.out.println("Car engine started in " + mode + " mode.");
    }
}