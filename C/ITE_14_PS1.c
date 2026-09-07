#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char id[12];
    int numGrades;
    float *grades;
    float average;
} Student;

float computeAverage(Student *s);
Student *findTopStudent(Student *student, int n);
Student *addStudent(Student *student, int *n, const char *name, const char *id, int numGrades, float *grades);
Student *removeStudent(Student *student, int *n, int index);
void printRoster(const Student *student, int n);
void freeStudents(Student *student, int n);

int main(void) {

    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);
    getchar();

    if (n < 3) {
        printf("Enter at least 3 students.\n");
        return 1;
    }

    Student *student = malloc(n * sizeof(Student));

    if (student == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {

        printf("\nEnter student %d:\n", i + 1);

        printf("Enter Student Name: ");
        fgets(student[i].name, sizeof(student[i].name), stdin);
        student[i].name[strcspn(student[i].name, "\n")] = '\0';

        printf("Enter Student ID: ");
        fgets(student[i].id, sizeof(student[i].id), stdin);
        student[i].id[strcspn(student[i].id, "\n")] = '\0';

        printf("Enter number of grades: ");
        scanf("%d", &student[i].numGrades);
        getchar();

        if (student[i].numGrades <= 0) {
            printf("Invalid number of grades.\n");
            freeStudents(student, i);
            return 1;
        }

        student[i].grades = malloc(student[i].numGrades * sizeof(float));

        if (student[i].grades == NULL) {
            printf("Memory allocation failed.\n");
            freeStudents(student, i);
            return 1;
        }

        for (int j = 0; j < student[i].numGrades; j++) {
            printf("Enter grade %d: ", j + 1);
            scanf("%f", &student[i].grades[j]);
            getchar();
        }
    }

    for (int i = 0; i < n; i++) {
        computeAverage(&student[i]);
    }

    printf("\n<=== Initial Roster ===>\n");
    printRoster(student, n);

    Student *top = findTopStudent(student, n);

    printf("\nTop student: %s (Average: %.2f)\n",
           top->name,
           top->average);

    char newName[50];
    char newID[12];
    int newNumGrades;

    printf("\n<=== Add New Student ===>\n");

    printf("Enter Student Name: ");
    fgets(newName, sizeof(newName), stdin);
    newName[strcspn(newName, "\n")] = '\0';

    printf("Enter Student ID: ");
    fgets(newID, sizeof(newID), stdin);
    newID[strcspn(newID, "\n")] = '\0';

    printf("Enter number of grades: ");
    scanf("%d", &newNumGrades);
    getchar();

    if (newNumGrades <= 0) {
        printf("Invalid number of grades.\n");
        freeStudents(student, n);
        return 1;
    }

    float *newGrades = malloc(newNumGrades * sizeof(float));

    if (newGrades == NULL) {
        printf("Memory allocation failed.\n");
        freeStudents(student, n);
        return 1;
    }

    for (int i = 0; i < newNumGrades; i++) {
        printf("Enter grade %d: ", i + 1);
        scanf("%f", &newGrades[i]);
        getchar();
    }

    Student *temp = addStudent(
        student,
        &n,
        newName,
        newID,
        newNumGrades,
        newGrades
    );

    free(newGrades);

    if (temp == NULL) {
        freeStudents(student, n);
        return 1;
    }

    student = temp;

    printf("\n<=== After Adding Student ===>\n");
    printRoster(student, n);

    printf("\nEnter the index of the student to remove (0-%d): ", n - 1);

    int removeIndex;
    scanf("%d", &removeIndex);

    student = removeStudent(student, &n, removeIndex);

    printf("\n<=== Final Roster ===>\n");

    if (student != NULL) {

        printRoster(student, n);

        top = findTopStudent(student, n);

        printf("\nTop student: %s (Average: %.2f)\n",
               top->name,
               top->average);

        freeStudents(student, n);

    } else {
        printf("Roster is now empty.\n");
    }

    return 0;
}

float computeAverage(Student *s) {

    float sum = 0;
    float *ptr = s->grades;

    for (int i = 0; i < s->numGrades; i++) {
        sum += *ptr;
        ptr++;
    }

    s->average = sum / s->numGrades;

    return s->average;
}

Student *findTopStudent(Student *student, int n) {

    Student *top = student;
    Student *ptr = student + 1;

    for (int i = 1; i < n; i++) {

        if (ptr->average > top->average) {
            top = ptr;
        }

        ptr++;
    }

    return top;
}

Student *addStudent(Student *student, int *n, const char *name,
                    const char *id, int numGrades, float *grades) {

    float *newGrades = malloc(numGrades * sizeof(float));

    if (newGrades == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    float *destination = newGrades;
    float *source = grades;

    for (int i = 0; i < numGrades; i++) {
        *destination = *source;
        destination++;
        source++;
    }

    Student *temp = realloc(student, (*n + 1) * sizeof(Student));

    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        free(newGrades);
        return NULL;
    }

    student = temp;

    strcpy(student[*n].name, name);
    strcpy(student[*n].id, id);
    student[*n].numGrades = numGrades;
    student[*n].grades = newGrades;

    computeAverage(&student[*n]);

    (*n)++;

    return student;
}

Student *removeStudent(Student *student, int *n, int index) {

    if (index < 0 || index >= *n) {
        printf("Invalid index!\n");
        return student;
    }

    free(student[index].grades);

    for (int i = index; i < *n - 1; i++) {
        student[i] = student[i + 1];
    }

    (*n)--;

    if (*n == 0) {
        free(student);
        return NULL;
    }

    Student *temp = realloc(student, *n * sizeof(Student));

    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        freeStudents(student, *n);
        exit(1);
    }

    return temp;
}

void printRoster(const Student *student, int n) {

    const Student *ptr = student;

    for (int i = 0; i < n; i++) {

        printf("\nStudent %d:\n", i + 1);
        printf("Student name: %s\n", ptr->name);
        printf("Student ID: %s\n", ptr->id);
        printf("Student average: %.2f\n", ptr->average);

        ptr++;
    }
}

void freeStudents(Student *student, int n) {

    for (int i = 0; i < n; i++) {
        free(student[i].grades);
    }

    free(student);
}
