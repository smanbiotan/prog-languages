package sher.studypedia;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
	
		
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("Enter Student ID: ");
		String studentID = scanner.nextLine();
		
		System.out.print("Enter Student Name: ");
		String name = scanner.nextLine();
		
		System.out.print("Enter Grade 1: ");
		double grade1 = scanner.nextDouble();
		
		System.out.print("Enter Grade 2: ");
		double grade2 = scanner.nextDouble();
		
		System.out.print("Enter Grade 3: ");
		double grade3 = scanner.nextDouble();
		
		System.out.println();
		
		Student student = new Student(
				studentID,
				name, 
				grade1,
				grade2,
				grade3
				);
		
		student.displayStudentInfo();
				
		scanner.close();
		
	}
}






/*
public class Main {
	
	public static void main(String[] args) {
		
		Vehicle vehicle = new Vehicle();
		Car car = new Car();
		
		vehicle.go();
		car.go();
	}
}
*/


/*
public class Main {
	public static void main(String[] args) {
		 
	Vehicle vehicle = new Vehicle("Ford");
	Car car = new Car("Mustang", 2026);

	System.out.println(vehicle.make);
	System.out.println(car.model);
	System.out.println(car.year);

	}
}
*/

/*
public class Main {
	public static void main(String[] args) {
		 
	Animal animal = new Animal();
	Dog dog = new Dog();
	Cat cat = new Cat();

	animal.animalSound();
	dog.animalSound();
	cat.animalSound();
	}
}
*/