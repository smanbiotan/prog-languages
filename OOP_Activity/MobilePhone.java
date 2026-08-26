public class MobilePhone {

    String brand;
    String model;
    String storage;
    double price;

    public MobilePhone(String brand, String model, String storage, double price) {
        this.brand = brand;
        this.model = model;
        this.storage = storage;
        this.price = price;
    }

    public void displayInfo() {

        System.out.println("Brand: " + brand);
        System.out.println("Model: " + model);
        System.out.println("Storage: " + storage);
        System.out.println("Price: " + price);
        System.out.println();
    }

    public void makeCall(String number) {

        System.out.println(model + "is calling " + number);
    }
}
