/*
// Dynamic Polymorphism
import java.util.Scanner;

public class Main {
    public static void main() {

        Animal animal = new Animal();
        Dog dog = new Dog();
        Cat cat = new Cat();

        Scanner scanner = new Scanner(System.in);

        System.out.println("What Animal do you want? ");
        System.out.print("(1. Dog) or (2.Cat): ");
        int choice = scanner.nextInt();

        if(choice == 1) {
            animal = new Dog();
            animal.animalSounds();
        }
        else if(choice == 2) {
            animal = new Cat();
            animal.animalSounds();
        }
        else {
            animal = new Animal();
            System.out.println("Invalid choice...");
            animal.animalSounds();
        }

    }
}

// Basic Polymorphism
public class Main {
    public static void main(String[] args) {

    Animal animal = new Animal();
    Dog dog = new Dog();
    Cat cat = new Cat();

    Animal[] animals = {dog, cat};

    for(Animal x: animals) {
        x.animalSounds();
    }
    }
}
*/


/*
// Inheritance

public class Main {
    public static void main (String[] args) {

        Car car1 = new Car("Ford", "Mustang", 2025);

        System.out.println(car1.toString());

    }
}
*/

/*
// Creating Encapsulation

public class Main {

    public static void main(String[] args){

        Car car = new Car("Ford", "Mustang", 2026);

        car.setYear(2036);

        System.out.println(car.getMake());
        System.out.println(car.getModel());
        System.out.print(car.getYear());

    }
}
*/

/*
// Creating Abstraction
public class Main {
    public static void main(String[] args) {

        Car car = new Car();

        car.go();
    }
}
*/

/*
// Creating Inheritance using hero

public class Main{
    public static void main(String[] args) {

        Hero hero1 = new Hero("Batman", 69, "$$$");
        Hero hero2 = new Hero("Superman", 70, "Everything");

        System.out.println(hero1);
        System.out.print(hero2);
    }
}
*/


/*
// Creating Class & Object
public class Main {
    public static void main(String[] args){

        Car car = new Car("Ford", "Mustang", "Red", 2026); // Instantiation

        System.out.print(car.toString());
    }
}
*/