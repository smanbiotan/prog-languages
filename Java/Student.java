/* 
Class - A class is a blueprint of an object.
Object - An object is an instance of a class.
*/ 

public class Student {
  String name;
  int age;
  String subject;

  public Student(String name, int age, String subject) {
    this.name = name;
    this.age = age;
    this.subject = subject;
  }
  public void displayInput(){
    System.out.print("Name: " + name + " | Age: " + age + " " + " Subject: " + subject + "\n");
  }
}

