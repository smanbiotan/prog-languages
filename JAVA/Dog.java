package handson_ni_negs;

public class Dog extends Animal{
	
	private String breed;
	private boolean isTrained;
	
	public Dog(String name, int age, String breed, boolean isTrained) {
		
		super(name, age);
		this.breed = breed;
		this.isTrained = isTrained;
	}
	
	// Overloading
	
	public void makeSound() {
		
		System.out.println("The rielkuza says arf arf.");
	}
	
	public void makeSound(String mood) {
		
		System.out.println("The rielkuza is in a " + mood + " mood right now.");
	}
	@Override
	public void displayDetails() {
		
		super.displayDetails();
		System.out.println("Dog Breed: " + breed);
		System.out.println("isTrained?: " + (isTrained ? "Yes" : "No"));
	} 
	
	
}
