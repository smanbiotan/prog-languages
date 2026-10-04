package OOP_ni_Negs;

public class Calculator {
	
	int add(int a, int b) {
		return a + b;
	}
	
	double add(double a, double b) {
		
		return a + b;
	}
	
	void displayAdd() {
		
		System.out.println("int add: " + add(16, 4));
		System.out.println("int double: " + add(4, 26));
	}
}
