package OOP_ni_Negs;

public class Student {
	
	  String student_id;
	  String student_name;
	  int student_age;
	  
	  public Student(String student_id, String student_name, int student_age) {
		  this.student_id = student_id;
		  this.student_name = student_name;
		  this.student_age = student_age;
	  }
	
	void getID() {
		System.out.println("Student ID: " + student_id);
	}

	void getName() {
		System.out.println("Student Name: " + student_name);
	}
	
	void getAge() {
		System.out.println("Student Age: " + student_age);
	}

}
