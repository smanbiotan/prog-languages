package handson_ni_negs;

public class Cat extends Animal{

	private String color;
	private boolean isIndoor;
	
	public Cat(String name, int age, String color, boolean isIndoor) {
		
		super(name, age);
		this.color = color;
		this.isIndoor = isIndoor;
	}
	
	// Overloading
	public void makeSound() {
		
		System.out.println("The rielkuza goes meow meow");
	}
	
	public void makeSound(boolean isHungry) {
		
		System.out.println("The rielkuza is currently " + (isHungry ? " Hungry" : " not Hungry"));
	}
	
	@Override
	public void displayDetails() {
		
		super.displayDetails();
		System.out.println("Cat Color: " + color);
		System.out.println("isIndoor?: " + (isIndoor ? "Yes" : "No"));
	} 
}
