#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 3

typedef struct Node {

    int data;
    struct Node *next;
} Node;

int main() {

     Node n[3];
     Node *temp;

    n[0].data = 10;
    n[1].data = 20;
    n[2].data = 30;

    n[0].next = &n[1];
    n[1].next = &n[2];
    n[2].next = NULL;

    Node *newNode;
    Node *head;

    newNode = malloc(sizeof(newNode));

    head = &n[0];

    temp = head;

    printf("Before Insertion...\n");
    while(temp != NULL) {

        printf("Data: %d\n", temp->data);
        temp = temp->next;
    }

    if(newNode == NULL) {
        printf("Unable to allocate memory...\n");
    } else {
        newNode->data = 40;
        newNode->next = head;
        head = newNode;

        printf("Data inserted successfully...\n");
    }

    // Traverse
    temp = head;

    printf("\nAfter Insertion...\n");
    while(temp != NULL) {

        printf("Data: %d\n", temp->data);
        temp = temp->next;
    }
   
    free(newNode);
    
    return 0;
}









/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 3

typedef struct Student {

    char studentID[20];
    char studentName[50];
    int age;
    struct Student *next;
} Student;

int main() {

    Student stud[SIZE];
    Student *temp;

    for(int i = 0; i < SIZE; i++) {

        printf("Enter Student ID %d: ", i + 1);
        fgets(stud[i].studentID, 20, stdin);
        stud[i].studentID[strcspn(stud[i].studentID,"\n")] = '\0';

        
        printf("Enter Student Name %d: ", i + 1);
        fgets(stud[i].studentName, 50, stdin);
        stud[i].studentName[strcspn(stud[i].studentName,"\n")] = '\0';

        printf("Enter Student Age %d: ", i + 1);
        scanf("%d", &stud[i].age);
        getchar();
        printf("\n");
    }

    for(int i = 0; i < SIZE; i++) {
        if(i == SIZE - 1) {
        stud[i].next = NULL;
        } else {
            stud[i].next = &stud[i + 1];
        }
    }

    temp = &stud[0];

    while(temp != NULL) {

        printf("\nStudent ID: %s\n", temp->studentID);
        printf("Student Name: %s\n", temp->studentName);
        printf("Student Age: %d\n", temp->age);

        temp = temp->next;
    }
  

    return 0;
}
*/