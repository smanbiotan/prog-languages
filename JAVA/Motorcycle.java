package handson_ni_negs;

class Motorcycle extends Vehicle {
	
    private int engineCC;
    private boolean hasSidecar;

    // Constructor
    public Motorcycle(String brand, double speed, int engineCC, boolean hasSidecar) {
    	
        super(brand, speed);
        this.engineCC = engineCC;
        this.hasSidecar = hasSidecar;
    }

    // Method overriding
    @Override
    public void displayDetails() {
    	
        System.out.println("Vehicle Type: Motorcycle");
        super.displayDetails();
        System.out.println("Engine Displacement: " + engineCC + " CC");
        System.out.println("Has Sidecar: " + hasSidecar);
    }

    // Method overloading
    public void startEngine() {
    	
        System.out.println("Motorcycle engine started.");
    }

    public void startEngine(boolean warmUp) {
    	
        if (warmUp) {
            System.out.println("Motorcycle engine started with warm-up.");
        } else {
            System.out.println("Motorcycle engine started without warm-up.");
        }
    }
}