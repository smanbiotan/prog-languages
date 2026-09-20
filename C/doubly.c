// Doubly Linked List
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int age;
    struct Node *prev;
    struct Node *next;
} Node;

int main() {    

    Node *head = malloc(sizeof(Node));
    Node *second = malloc(sizeof(Node));
    Node *third = malloc(sizeof(Node));

    head->age = 18; // i set ang head value sa 18
    head->prev = NULL; // then we set the prev in NULL kay wala may prev node para maka point 
    head->next = second; // next = second

    second->age = 19; // i set ang second value sa 19
    second->prev = head; // then i maka point nata which is sa atong head kay mao man atong previous node
    second->next = third; // next = thirrd

    third->age = 20; // i set ang third value sa 20
    third->prev = second; // then i point nato sa prev node which is sa atong second kay mao man atong previous node
    third->next = NULL; // then atong third node i equal nato sa NULL kay mao may next node niya always NULL and last node

    Node *temp = head; // forward

    printf("Forward: \n");

    while(temp != NULL) {
        printf("Student Age: %d\n", temp->age);
        temp = temp->next;
    }

    temp = third; // backward

    printf("\nBackward\n");

    while(temp != NULL) {
        printf("Student Age: %d\n", temp->age);
        temp = temp->prev;
    }

    free(third); // dont forget if alloc > use > free.
    free(second);
    free(head);

    return 0;
}
