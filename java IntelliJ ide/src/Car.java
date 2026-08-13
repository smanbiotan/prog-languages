
/*
// inheritance

public class Car extends Vehicle{
    String model;
    int year;

    public Car (String make, String model, int year){
        super(make);
        this.model = model;
        this.year = year;
    }
    public String toString(){
        return "Make: " + make +" Model: " + model + " Year: " + year;
    }
}
*/

/*
// Creating Encapsulation

public class Car {
    private String make;
    private String model;
    private int year;

    public Car (String make, String model, int year) {
        this.setMake(make);
        this.setModel(model);
        this.setYear(year);
    }
    public String getMake () {
        return make;
    }
    public String getModel () {
        return model;
    }
    public int getYear () {
        return year;
    }

    public void setMake (String make) {
        this.make = make;
    }
    public void setModel (String model) {
        this.model = model;
    }
    public void setYear (int year) {
        this.year = year;
    }
}
*/

/*
// Abstraction
public class Car extends Vehicle {

    @Override
    void go(){
        System.out.println("The driver is driving the car...");
    }
}
*/

/*

// Inheritance
public class Hero extends Person {
    String power;

    Hero(String name, int age, String power) {
        super(name, age);
        this.power = power;
    }

    @Override
    public String toString() {
        return super.toString() + " Power: " + this.power;
    }
}
*/


 /*

// Creating Class & Object
public class Car {
    String make;      // Attributes/Fields
    String model;
    String color;
    int year;

Car(String make, String model, String color, int year) {
    this.make = make;
    this.model = model;     // Class constructor
    this.color = color;
    this.year = year;
    }

public String toString(){
    return "Make: " + make +       // Methods/Action
           " | Model:  " + model +
           " | Color: " + color +
           " | Year: " + year;
    }
}
*/