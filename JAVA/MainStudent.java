package test_java;

import java.util.Scanner;

public class MainStudent {

    public static void main(String[] args) {

        // Creates a Scanner object to get input from the user
        Scanner input = new Scanner(System.in);

        // Gets the student's name
        System.out.print("Enter student name: ");
        String name = input.nextLine();

        // Gets the student's Prelim grade
        System.out.print("Enter Prelim Grade: ");
        float prelim = input.nextFloat();

        // Gets the student's Midterm grade
        System.out.print("Enter Midterm Grade: ");
        float midterm = input.nextFloat();

        // Gets the student's Final grade
        System.out.print("Enter Final Grade: ");
        float finals = input.nextFloat();

        // Creates a Student object using the inputted information
        Student studKirk = new Student(
                name,
                prelim,
                midterm,
                finals
        );

        // Displays the student's information and results
        studKirk.displayStudentInfo();

        // Closes the Scanner object
        input.close();
    }
}