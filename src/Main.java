public class Main {

    public static void main(String[] args) {

        MobilePhone phone1 = new MobilePhone("Apple", "Iphone 17", "1TB", 95000);
        MobilePhone phone2 = new MobilePhone("Samsung", "Galaxy S24", "256 GB", 65000);

        System.out.println("Name: Sherwin Alvin Manbiotan");
        System.out.println("Section: CKHX1");
        System.out.println();

        System.out.println("=== Mobile Phone 1 ===");
        phone1.displayInfo();
        System.out.println("=== Mobile Phone 2 ===");
        phone2.displayInfo();

        phone1.makeCall("09123456789");
        phone2.makeCall("09876543210");
    }
}
