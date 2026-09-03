public class Student {

    private String name;
    private float prelim;
    private float midterm;
    private float finals;

    public Student(String name,  float prelim,  float midterm,  float finals) {
        this.name = name;
        this.prelim = prelim;
        this.midterm = midterm;
        this.finals = finals;
    }

    public double calculateAverage() {

        return (prelim + midterm + finals) / 3;
    }

    public String getStatus() {

        if(calculateAverage() >= 75) {
            return "PASSED";
        } else {
            return "FAILED";
        }

    }

    public String getLetterGrade() {

        if(calculateAverage() >= 95) {
            return "A+";
        } else if(calculateAverage() >= 85) {
            return "A- ";
        } else if(calculateAverage() >= 75) {
            return "B ";
        } else {
            return "F ";
        }
    }

    public void displayStudentInfo() {

        System.out.println("\n---STUDENT FINAL GRADE---");
        System.out.println("Name: " + name);
        System.out.printf("Average: %.2f%n", calculateAverage());
        System.out.println("Status: " + getStatus());
        System.out.println("Letter Grade: " + getLetterGrade());
    }

}
