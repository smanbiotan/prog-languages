package OOP_ni_Negs;

public class MainBank {
	public static void main(String[] args) {
		
		Payment payment; 
		
		payment = new CreditCardPayment();
		payment.pay(1000);
		
		payment = new Gcash();
		payment.pay(20000);
	}
}
