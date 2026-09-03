import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        System.out.print("Enter student name: ");
        String name = input.nextLine();

        System.out.print("Enter Prelim Grade: ");
        float prelim = input.nextFloat();

        System.out.print("Enter Midterm Grade: ");
        float midterm = input.nextFloat();

        System.out.print("Enter Final Grade: ");
        float finals = input.nextFloat();

        Student studKirk = new Student(
                name,
                prelim,
                midterm,
                finals);

        studKirk.displayStudentInfo();

        input.close();
    }


}
