package test_java;

public class Student {

    // Private attributes that store the student's information
    private String name;
    private float prelim;
    private float midterm;
    private float finals;

    // Constructor used to initialize the student's attributes
    public Student(String name, float prelim, float midterm, float finals) {
        this.name = name;
        this.prelim = prelim;
        this.midterm = midterm;
        this.finals = finals;
    }

    // Calculates the average of the three grades
    public double calculateAverage() {
        return (prelim + midterm + finals) / 3;
    }

    // Determines whether the student passed or failed
    public String getStatus() {

        // A student passes if the average is 75 or higher
        if (calculateAverage() >= 75) {
            return "PASSED";
        } else {
            return "FAILED";
        }
    }

    // Determines the student's letter grade based on the average
    public String getLetterGrade() {

        // 95 and above receives an A+
        if (calculateAverage() >= 95) {
            return "A+";
        }

        // 85 to 94.99 receives an A-
        else if (calculateAverage() >= 85) {
            return "A-";
        }

        // 75 to 84.99 receives a B
        else if (calculateAverage() >= 75) {
            return "B";
        }

        // Below 75 receives an F
        else {
            return "F";
        }
    }

    // Displays the student's information and calculated results
    public void displayStudentInfo() {

        System.out.println("Name: " + name);
        System.out.printf("Average: %.2f%n", calculateAverage());
        System.out.println("Status: " + getStatus());
        System.out.println("Letter Grade: " + getLetterGrade());
    }
}