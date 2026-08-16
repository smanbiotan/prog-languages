#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
  char studentNumber[20];
  char fullName[50];
  float quizScore;
  float laboratoryScore;
  float examScore;
  float finalGrade;
  char remarks[25];
};

int main() {

  struct Student *students;

  int n, i;

  printf("Enter number of students: ");
  scanf("%d", &n);
  getchar();

  students = malloc(n * sizeof(struct Student));

  if(students == NULL){
    printf("Memory Allocation Failed...");
    return 1;
  }

  for(i = 0; i < n; i++) {

    printf("\nStudent %d\n\n", i + 1);

    printf("Student Number: ");
    fgets(students[i].studentNumber, 20, stdin);
    students[i].studentNumber[strcspn(students[i].studentNumber, "\n")] = '\0';

    printf("Full Name: ");
    fgets(students[i].fullName, 50, stdin);
    students[i].fullName[strcspn(students[i].fullName, "\n")] = '\0';

    printf("Quiz Score: ");
    scanf("%f", &students[i].quizScore);
    getchar();

    printf("Laboratory Score: ");
    scanf("%f", &students[i].laboratoryScore);
    getchar();

    printf("Exam Score: ");
    scanf("%f", &students[i].examScore);
    getchar();

    students[i].finalGrade 
    = (students[i].quizScore * 0.30 + students[i].laboratoryScore * 0.30 + students[i].examScore * 0.40); 
   
    if(students[i].finalGrade >= 75)
        strcpy(students[i].remarks, "Passed");
    else 
        strcpy(students[i].remarks, "Failed");
  }

  printf("\n===== STUDENT GRADE RECORDS =====\n\n");

  for(i = 0; i < n; i++){

    printf("Student Number   : %s\n", students[i].studentNumber);
    printf("Full Name        : %s\n", students[i].fullName);
    printf("Quiz             : %.2f\n", students[i].quizScore);
    printf("Laboratory       : %.2f\n", students[i].laboratoryScore);
    printf("Exam             : %.2f\n", students[i].examScore);
    printf("Final Grade      : %.2f\n", students[i].finalGrade);
    printf("Remarks          : %s\n\n", students[i].remarks);
    
  }

  FILE * fp;
  
  fp = fopen("grades.txt", "w");

    if(fp == NULL) {
    printf("File error...");
    free(students);
    return 1;
  }


  fprintf(fp, "STUDENT GRADE RECORDS\n");

  for(i = 0; i < n; i++) {

    fprintf(fp, "Student Number   : %s\n", students[i].studentNumber);
    fprintf(fp, "Full Name        : %s\n", students[i].fullName);
    fprintf(fp, "Quiz             : %.2f\n", students[i].quizScore);
    fprintf(fp, "Laboratory       : %.2f\n", students[i].laboratoryScore);
    fprintf(fp, "Exam             : %.2f\n", students[i].examScore);
    fprintf(fp, "Final Grade      : %.2f\n", students[i].finalGrade);
    fprintf(fp, "Remarks          : %s\n\n", students[i].remarks);

  }

  free(students);
  fclose(fp);

  return 0;

}