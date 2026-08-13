package sher.studypedia;

public class Student {
	
	private String studentID;
	private String name;
	private double grade1;
	private double grade2;
	private double grade3;
	
	public Student(String studentID, String name, double grade1, double grade2, double grade3) {
		
		this.studentID = studentID;
		this.name = name;
		this.grade1 = grade1;
		this.grade2 = grade2;
		this.grade3 = grade3;
	}
	
	public double calculateAverage(){
		return (grade1 + grade2 + grade3) / 3;
	}
	
	public String getStatus() {
		
		if (calculateAverage() >= 75) {
			return "PASSED";
		} else {
			return "FAILED";
		}
	} 
	
	public void displayStudentInfo() {
		
		System.out.println("===== STUDENT INFORMATION =====");
		System.out.println("Student ID: " + studentID);
		System.out.println("Name: " + name);
		System.out.println("Grade 1: " + grade1);
		System.out.println("Grade 2: " + grade2);
		System.out.println("Grade 3: " + grade3);
		System.out.println("Average: " + calculateAverage());
		System.out.println("Status: " + getStatus());
		System.out.println("===============================");
	}
}
