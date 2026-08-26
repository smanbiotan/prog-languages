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

    public float calculateAverage() {

        return (float) (prelim + midterm + finals) / 3;
    }

    public void getStatus() {

        if(calculateAverage() >= 75) {
            System.out.println("Status: PASSED");
        } else {
            System.out.println("Status: FAILED");
        }

    }

    public void getLetterGrade() {

        if(calculateAverage() >= 95) {
            System.out.println("Letter Grade: 'A'" );
        } else if(calculateAverage() >= 85) {
            System.out.println("Letter Grade: 'B'" );
        } else if(calculateAverage() >= 75) {
            System.out.println("Letter Grade: 'C' " );
        } else {
            System.out.println("Letter Grade: 'F'" );
        }
    }

    public void displayStudentInfo() {

        System.out.println("\n---STUDENT FINAL GRADE---");
        System.out.println("Name: " + name);
        System.out.println("Prelim: " + prelim);
        System.out.println("Midterm: " + midterm);
        System.out.println("Finals: " + finals);
        System.out.println("Average: " + calculateAverage());
    }

}
