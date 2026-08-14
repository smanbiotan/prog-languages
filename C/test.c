#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student{
  char studentNumber[20];
  char fullName[50];
  float quizScore;
  float labScore;
  float examScore;
  float finalGrade;
  char remarks[20];
};

int main() {

  struct Student *students;

  int i, n;

  printf("Enter a number: ");
  scanf("%d", &n);
  getchar();

  students = malloc(n * sizeof(struct Student));

  if(students == NULL) {
    printf("Memory allocation failed...");
    return 1;
  }

  for(i = 0; i < n; i++){
    printf("\nStudent %d\n\n", i + 1);

    printf("Student Number  : ");
    fgets(students[i].studentNumber, sizeof(students[i].studentNumber), stdin);
    students[i].studentNumber[strcspn(students[i].studentNumber,"\n")] = '\0';

    printf("Full Name       : ");
    fgets(students[i].fullName, sizeof(students[i].fullName), stdin);
    students[i].fullName[strcspn(students[i].fullName,"\n")] = '\0';

    printf("Quiz Score      : ");
    scanf("%f", &students[i].quizScore);
    getchar();

    printf("Laboratory Score: ");
    scanf("%f", &students[i].labScore);
    getchar();

    printf("Exam Score      : ");
    scanf("%f", &students[i].examScore);
    getchar();

    students[i].finalGrade =
    students[i].quizScore * 0.30 +
    students[i].labScore * 0.30 +
    students[i].examScore * 0.40;

    if (students[i].finalGrade >= 75) {
      strcpy(students[i].remarks,"Passed");
    } else {
      strcpy(students[i].remarks,"Failed");
    }
  }
 
  printf("===== STUDENT GRADE RECORDS =====\n\n");

  for(i = 0; i < n; i++){

    printf("Student Number  : %s\n", students[i].studentNumber);
    printf("Full Name       : %s\n", students[i].fullName);
    printf("Quiz            : %.2f\n", students[i].quizScore);
    printf("Laboratory      : %.2f\n", students[i].labScore);
    printf("Exam            : %.2f\n", students[i].examScore);
    printf("Final Grade     : %.2f\n", students[i].finalGrade);
    printf("Remarks         : %s\n", students[i].remarks);

  }

  FILE *fp;

  fp = fopen("grades.txt", "w");

  if(fp == NULL) {
    printf("File Handling Failed...\n");
    free(students);
    return 1;
  }

  for(i = 0; i < n; i++){
    fprintf(fp, "%s\n %s\n %f\n %f\n %f\n %f\n %s\n\n",
    students[i].studentNumber,
    students[i].fullName,
    students[i].quizScore,
    students[i].labScore,
    students[i].examScore,
    students[i].finalGrade,
    students[i].remarks);
  }

  free(students);
  fclose(fp);

  return 0;
}
