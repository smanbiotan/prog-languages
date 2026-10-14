package handson_ni_negs;

public class MainAnimal {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Dog dog = new Dog("Jandoeg", 3, "Chinese Dragon", true);
		Cat cat = new Cat("Katoe", 2, "Black", true);

		System.out.println("====== DAWG DETAILS =====");
		dog.displayDetails();
		System.out.println();
		System.out.println("====== PEDOHUB DETAILS =====");
		cat.displayDetails();
		System.out.println();
		
		Animal a1; 
		a1 = dog; 

		Animal a2;
		a2 = cat;
		
		System.out.println("====== ANIMAL DETAILS =====");
		a1.displayDetails();
		System.out.println();
		a2.displayDetails();
	}

}
