#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    int pid;
    char processName[32];
    int memoryRequired;
    int burstTime;
    char status[12];
} PCB;

typedef struct SNode {

    PCB data;
    struct SNode *next;
} SNode;

typedef struct {

    SNode *head;
    int count;
} ReadyQueue;

PCB makePCB(int pid, const char *name, int mem, int burst, const char *status) {

    PCB p;
    p.pid = pid;
    strncpy(p.processName, name, sizeof(p.processName) - 1);
    p.processName[sizeof(p.processName) - 1] = '\0';
    p.memoryRequired = mem;
    p.burstTime = burst;
    strncpy(p.status, status, sizeof(p.status) - 1);
    p.status[sizeof(p.status) - 1] = '\0';
    return p;
}

int allocCount = 0;

void readyQueue_init(ReadyQueue *q) {

    q->head = NULL;
    q->count = 0;
}

int readyQueue_insertHead(ReadyQueue *q, PCB p) {

    SNode *newNode = malloc(sizeof(SNode));
    if (newNode == NULL)
        return 0;

    newNode->data = p;
    newNode->next = q->head;
    q->head = newNode;
    q->count++;
    allocCount++;
    return 1;
}

int readyQueue_insertTail(ReadyQueue *q, PCB p) {

    SNode *newNode = malloc(sizeof(SNode));
    if (newNode == NULL)
        return 0;

    newNode->data = p;
    newNode->next = NULL;

    if (q->head == NULL) {
        q->head = newNode;
    }
    else {
        SNode *current = q->head;
        while (current->next != NULL)
            current = current->next;
        current->next = newNode;
    }

    q->count++;
    allocCount++;
    return 1;
}

int readyQueue_insertAtPosition(ReadyQueue *q, int position, PCB p) {

    if (position < 0 || position > q->count)
        return 0;
    if (position == 0)
        return readyQueue_insertHead(q, p);

    SNode *newNode = malloc(sizeof(SNode));
    if (newNode == NULL)
        return 0;

    SNode *previous = q->head;
    for (int i = 1; i < position; i++)
        previous = previous->next;

    newNode->data = p;
    newNode->next = previous->next;
    previous->next = newNode;

    q->count++;
    allocCount++;
    return 1;
}

SNode *readyQueue_search(ReadyQueue *q, int pid) {

    SNode *current = q->head;
    while (current != NULL) {
        if (current->data.pid == pid)
            return current;
        current = current->next;
    }
    return NULL;
}

int readyQueue_deleteByKey(ReadyQueue *q, int pid) {

    if (q->head == NULL)
        return 0;

    SNode *current = q->head;

    if (current->data.pid == pid) {

        q->head = current->next;
        free(current);
        q->count--;
        allocCount--;
        return 1;
    }

    SNode *previous = q->head;
    current = q->head->next;

    while (current != NULL) {

        if (current->data.pid == pid)
        {
            previous->next = current->next;
            free(current);
            q->count--;
            allocCount--;
            return 1;
        }
        previous = current;
        current = current->next;
    }

    return 0;
}

int readyQueue_deleteAtPosition(ReadyQueue *q, int position) {

    if (position < 0 || position >= q->count || q->head == NULL)
        return 0;

    if (position == 0) {
        SNode *toDelete = q->head;
        q->head = toDelete->next;
        free(toDelete);
        q->count--;
        allocCount--;
        return 1;
    }

    SNode *previous = q->head;
    for (int i = 1; i < position; i++)
        previous = previous->next;

    SNode *toDelete = previous->next;
    previous->next = toDelete->next;
    free(toDelete);

    q->count--;
    allocCount--;
    return 1;
}

void readyQueue_traverse(ReadyQueue *q) {

    printf("-- READY QUEUE --\n");

    SNode *current = q->head;
    int index = 0;

    while (current != NULL) {
        printf("[%d] PID=%d Name=%s Mem=%dKB Burst=%dms Status=%s\n",
               index,
               current->data.pid,
               current->data.processName,
               current->data.memoryRequired,
               current->data.burstTime,
               current->data.status);
        current = current->next;
        index++;
    }
}

void readyQueue_destroy(ReadyQueue *q) {
    
    SNode *current = q->head;

    while (current != NULL) {
        SNode *next = current->next;
        free(current);
        allocCount--;
        current = next;
    }

    q->head = NULL;
    q->count = 0;
}

int main(void) {
    ReadyQueue rq;
    readyQueue_init(&rq);

    readyQueue_insertTail(&rq, makePCB(101, "Compiler", 256, 120, "READY"));
    readyQueue_insertTail(&rq, makePCB(102, "Browser", 512, 300, "READY"));
    readyQueue_insertHead(&rq, makePCB(103, "TextEditor", 64, 50, "READY"));
    readyQueue_insertAtPosition(&rq, 2, makePCB(104, "MediaPlayer", 128, 200, "READY"));

    printf("=== After building Ready Queue ===\n");
    readyQueue_traverse(&rq);

    SNode *found = readyQueue_search(&rq, 102);
    if (found) {
        printf("Found PID 102 -> Name=%s Mem=%dKB Burst=%dms\n",
               found->data.processName,
               found->data.memoryRequired,
               found->data.burstTime);
    }

    if (!readyQueue_search(&rq, 999))
        printf("PID 999 not found in Ready Queue\n");

    readyQueue_deleteByKey(&rq, 101);
    readyQueue_deleteAtPosition(&rq, 0);

    printf("=== Final Ready Queue ===\n");
    readyQueue_traverse(&rq);

    readyQueue_destroy(&rq);

    /* Part 2 Step 3: temporarily add:
       printf("allocCount=%d\n", allocCount);
    */

    return 0;
}
