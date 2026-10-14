package handson_ni_negs;

public class Animal {
	
	private String name;
	private int age;
	
	public Animal(String name, int age) {
		
		this.name = name;
		this.age = age;
	}
	
	public String getName() {
		
		return name;
	}
	
	public int getAge() {
		
		return age;
	}
	
	
	void calculateFoodIntake(double weight) {
		
		System.out.println("The Animal eats " + weight + " grams.");
	}
	
	void calculateFoodIntake(double weight, int activityLevel) {
		
		System.out.println("The Animal needs to eat " + (weight * activityLevel) + " calories per day.");
	}

	
	void displayDetails() {
		
		System.out.println("Animal Name: " + name);
		System.out.println("Animal Age: " + age);
	}
	
	

}
