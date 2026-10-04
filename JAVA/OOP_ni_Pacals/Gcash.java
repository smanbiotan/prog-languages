package OOP_ni_Negs;

public class Gcash extends Payment{

	@Override
	void pay (double amount) {
		System.out.println("Paid PHP " + amount + " using Gcash");
	}
}
