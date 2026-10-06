/*
// Dynamic Integer Array Using malloc()
// Possible problem: Create an array dynamically and calculate cubes
#include <stdio.h>
#include <stdlib.h>

int *makeCubes(int n) {
    int *a = malloc(n * sizeof(int));

    if (a == NULL)
        return NULL;

    for (int i = 0; i < n; i++) {
        a[i] = i * i * i;
    }

    return a;
}

int main(void) {
    int n = 4;

    int *c = makeCubes(n);

    if (c == NULL)
        return 1;

    for (int i = 0; i < n; i++) {
        printf("%d ", c[i]);
    }

    printf("\n");

    free(c);
    c = NULL;

    return 0;
}
*/

/*
// Singly Linked List — Complete Implementation
// Possible problem: Insert, delete, print, and free a linked list

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertHead(struct Node **head, int val) {
    struct Node *n = malloc(sizeof *n);

    if (!n)
        return;

    n->data = val;
    n->next = *head;

    *head = n;
}

void insertTail(struct Node **head, int val) {
    struct Node *n = malloc(sizeof *n);

    if (!n)
        return;

    n->data = val;
    n->next = NULL;

    if (*head == NULL) {
        *head = n;
        return;
    }

    struct Node *cur = *head;

    while (cur->next)
        cur = cur->next;

    cur->next = n;
}

int deleteByKey(struct Node **head, int key) {
    struct Node *cur = *head;
    struct Node *prev = NULL;

    while (cur && cur->data != key) {
        prev = cur;
        cur = cur->next;
    }

    if (!cur)
        return 0;

    if (!prev)
        *head = cur->next;
    else
        prev->next = cur->next;

    free(cur);

    return 1;
}

void printList(const struct Node *head) {
    for (; head; head = head->next)
        printf("%d -> ", head->data);

    printf("NULL\n");
}

void freeList(struct Node **head) {
    struct Node *cur = *head;

    while (cur) {
        struct Node *next = cur->next;

        free(cur);

        cur = next;
    }

    *head = NULL;
}

int main(void) {
    struct Node *list = NULL;

    insertTail(&list, 7);
    insertTail(&list, 14);
    insertTail(&list, 21);

    insertHead(&list, 3);

    printList(list);

    deleteByKey(&list, 3);
    deleteByKey(&list, 21);
    deleteByKey(&list, 99);

    printList(list);

    freeList(&list);

    return 0;
}
*/

/*
// Delete Last Node in Singly Linked List
// Possible problem: Implement/fix deleteLast()
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void deleteLast(struct Node **head) {

    if (*head == NULL)
        return;

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *prev = *head;

    while (prev->next->next != NULL)
        prev = prev->next;

    free(prev->next);

    prev->next = NULL;
}

void printList(struct Node *head) {

    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

int main(void) {

    struct Node *head = malloc(sizeof *head);
    struct Node *second = malloc(sizeof *second);
    struct Node *third = malloc(sizeof *third);

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    printList(head);

    deleteLast(&head);

    printList(head);

    while (head != NULL) {
        struct Node *next = head->next;
        free(head);
        head = next;
    }

    return 0;
}
*/

/*
// Array-Based Stack
// Possible problem: Implement push(), pop(), peek()
#include <stdio.h>

#define CAP 4

struct Stack {
    int data[CAP];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

int push(struct Stack *s, int v) {

    if (s->top == CAP - 1)
        return 0;

    s->data[++s->top] = v;

    return 1;
}

int pop(struct Stack *s, int *out) {

    if (isEmpty(s))
        return 0;

    *out = s->data[s->top--];

    return 1;
}

int peek(struct Stack *s, int *out) {

    if (isEmpty(s))
        return 0;

    *out = s->data[s->top];

    return 1;
}

int main(void) {

    struct Stack s;

    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);

    int value;

    while (pop(&s, &value)) {
        printf("Pop: %d\n", value);
    }

    return 0;
}
*/

/*
// Linked Stack
// Possible problem: Stack using dynamically allocated nodes

#include <stdio.h>
#include <stdlib.h>

struct SNode {
    int data;
    struct SNode *next;
};

int isEmpty(struct SNode *top) {
    return top == NULL;
}

int push(struct SNode **top, int v) {

    struct SNode *n = malloc(sizeof *n);

    if (!n)
        return 0;

    n->data = v;
    n->next = *top;

    *top = n;

    return 1;
}

int pop(struct SNode **top, int *out) {

    if (isEmpty(*top))
        return 0;

    struct SNode *t = *top;

    *out = t->data;

    *top = t->next;

    free(t);

    return 1;
}

int main(void) {

    struct SNode *top = NULL;

    push(&top, 4);
    push(&top, 5);
    push(&top, 6);

    int value;

    while (pop(&top, &value)) {
        printf("Pop: %d\n", value);
    }

    return 0;
}
*/

/*
// Linked Queue
// Possible problem: Queue using front and rear

#include <stdio.h>
#include <stdlib.h>

struct QNode {
    int data;
    struct QNode *next;
};

struct Queue {
    struct QNode *front;
    struct QNode *rear;
};

int enqueue(struct Queue *q, int v) {

    struct QNode *n = malloc(sizeof *n);

    if (!n)
        return 0;

    n->data = v;
    n->next = NULL;

    if (q->rear)
        q->rear->next = n;
    else
        q->front = n;

    q->rear = n;

    return 1;
}

int dequeue(struct Queue *q, int *out) {

    if (!q->front)
        return 0;

    struct QNode *t = q->front;

    *out = t->data;

    q->front = t->next;

    if (!q->front)
        q->rear = NULL;

    free(t);

    return 1;
}

int main(void) {

    struct Queue q = {NULL, NULL};

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    int value;

    while (dequeue(&q, &value)) {
        printf("Dequeue: %d\n", value);
    }

    return 0;
}
*/