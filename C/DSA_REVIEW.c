#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 3

typedef struct Student {

    char studentID[20];
    char studentName[30];
    int studentAge;
    struct Student *next;
} Student;

int main() {
    
    Student s[SIZE];
    Student *temp;

    for(int i = 0; i < SIZE; i++) {

        printf("Enter Student ID %d: ", i + 1);
        fgets(s[i].studentID, 30, stdin);
        s[i].studentID[strcspn(s[i].studentID, "\n")] = '\0';       

        printf("Enter Student Name %d: ", i + 1);
        fgets(s[i].studentName, 30, stdin);
        s[i].studentName[strcspn(s[i].studentName, "\n")] = '\0';     

        printf("Enter Student Age %d: ", i + 1);
        scanf("%d", &s[i].studentAge);
        getchar();
        printf("\n");
    }

    // Student *newHead;
    Student *head;
    //newHead = malloc(sizeof(int));
    
    head = &s[0];

    for(int i = 0; i < SIZE; i++) {

        if(i == SIZE - 1) { // 0 = 2
            s[i].next = NULL;
        } else {
            s[i].next = &s[i + 1];
        }
    }

    temp = head;

    while(temp != NULL) {

        printf("Student ID: %s\n", temp->studentID);
        printf("Student Name: %s\n", temp->studentName);
        printf("Student Age: %d\n\n", temp->studentAge);
        temp = temp->next;
    }

    return 0;
}