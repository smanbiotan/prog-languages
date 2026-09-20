
// Singly Linked List
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int age;
    struct Node *next;
} Node;

int main() {

    Node *head = malloc(sizeof(Node));
    Node *second = malloc(sizeof( Node));
    Node *third = malloc(sizeof( Node));
 
    head->age = 18;
    head->next = second;

    second->age = 19;
    second->next = third;

    third->age = 20;
    third->next = NULL;

    Node *temp = head;

    while(temp != NULL) {
        printf("Student Age: %d\n", temp->age);
        temp = temp->next;
    }

    free(third);
    free(second);
    free(head);

    return 0;
}
