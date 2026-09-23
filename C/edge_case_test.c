#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int allocCount = 0;

typedef struct
{
    int pid;
    char processName[50];
    int memoryRequired;
    int burstTime;
    char status[20];
} PCB;

typedef struct SNode
{
    PCB data;
    struct SNode *next;
} SNode;

typedef struct
{
    SNode *head;
    int count;
} ReadyQueue;

PCB makePCB(int pid, const char *name, int memory,
            int burst, const char *status)
{
    PCB p;

    p.pid = pid;
    strcpy(p.processName, name);
    p.memoryRequired = memory;
    p.burstTime = burst;
    strcpy(p.status, status);

    return p;
}

void readyQueue_init(ReadyQueue *q)
{
    q->head = NULL;
    q->count = 0;
}

int readyQueue_insertHead(ReadyQueue *q, PCB data)
{
    SNode *newNode = malloc(sizeof(SNode));

    if (newNode == NULL)
        return 0;

    newNode->data = data;
    newNode->next = q->head;
    q->head = newNode;

    q->count++;
    allocCount++;

    return 1;
}

int readyQueue_insertTail(ReadyQueue *q, PCB data)
{
    SNode *newNode = malloc(sizeof(SNode));

    if (newNode == NULL)
        return 0;

    newNode->data = data;
    newNode->next = NULL;

    if (q->head == NULL)
    {
        q->head = newNode;
    }
    else
    {
        SNode *current = q->head;

        while (current->next != NULL)
            current = current->next;

        current->next = newNode;
    }

    q->count++;
    allocCount++;

    return 1;
}

int readyQueue_insertAtPosition(ReadyQueue *q, int position, PCB data)
{
    if (position < 0 || position > q->count)
        return 0;

    if (position == 0)
        return readyQueue_insertHead(q, data);

    SNode *newNode = malloc(sizeof(SNode));

    if (newNode == NULL)
        return 0;

    newNode->data = data;

    SNode *previous = q->head;

    for (int i = 1; i < position; i++)
        previous = previous->next;

    newNode->next = previous->next;
    previous->next = newNode;

    q->count++;
    allocCount++;

    return 1;
}

SNode *readyQueue_search(ReadyQueue *q, int pid)
{
    SNode *current = q->head;

    while (current != NULL)
    {
        if (current->data.pid == pid)
            return current;

        current = current->next;
    }

    return NULL;
}

int readyQueue_deleteByKey(ReadyQueue *q, int pid)
{
    if (q->head == NULL)
        return 0;

    if (q->head->data.pid == pid)
    {
        SNode *toDelete = q->head;

        q->head = q->head->next;

        free(toDelete);

        q->count--;
        allocCount--;

        return 1;
    }

    SNode *previous = q->head;
    SNode *current = q->head->next;

    while (current != NULL)
    {
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

int readyQueue_deleteAtPosition(ReadyQueue *q, int position)
{
    if (position < 0 || position >= q->count || q->head == NULL)
        return 0;

    if (position == 0)
    {
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

void readyQueue_traverse(ReadyQueue *q)
{
    printf("-- READY QUEUE --\n");

    SNode *current = q->head;
    int index = 0;

    while (current != NULL)
    {
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

void readyQueue_destroy(ReadyQueue *q)
{
    SNode *current = q->head;

    while (current != NULL)
    {
        SNode *next = current->next;

        free(current);
        allocCount--;

        current = next;
    }

    q->head = NULL;
    q->count = 0;
}

int main(void)
{

    ReadyQueue q;

    /* EMPTY LIST */

    printf("=== EMPTY LIST TEST ===\n");

    readyQueue_init(&q);

    readyQueue_traverse(&q);

    if (readyQueue_search(&q, 999) == NULL)
        printf("Search PID 999: NOT FOUND\n");

    if (readyQueue_deleteAtPosition(&q, 0) == 0)
        printf("Delete position 0: FAILED AS EXPECTED\n");

    /* SINGLE NODE */

    printf("\n=== SINGLE NODE TEST ===\n");

    readyQueue_init(&q);

    readyQueue_insertTail(
        &q,
        makePCB(201, "TestProcess", 100, 50, "READY"));

    printf("Before delete: count=%d\n", q.count);

    if (readyQueue_deleteByKey(&q, 201))
        printf("Delete PID 201: SUCCESS\n");

    printf("After delete: count=%d\n", q.count);

    if (q.head == NULL)
        printf("head=NULL\n");

    /* DELETE HEAD */

    printf("\n=== DELETE HEAD TEST ===\n");

    readyQueue_init(&q);

    readyQueue_insertTail(
        &q,
        makePCB(301, "ProcessA", 100, 50, "READY"));

    readyQueue_insertTail(
        &q,
        makePCB(302, "ProcessB", 200, 100, "READY"));

    readyQueue_insertTail(
        &q,
        makePCB(303, "ProcessC", 300, 150, "READY"));

    printf("Before deleting head:\n");
    readyQueue_traverse(&q);

    readyQueue_deleteAtPosition(&q, 0);

    printf("After deleting head:\n");
    readyQueue_traverse(&q);

    /* DELETE TAIL */

    printf("\n=== DELETE TAIL TEST ===\n");

    readyQueue_destroy(&q);
    readyQueue_init(&q);

    readyQueue_insertTail(
        &q,
        makePCB(401, "ProcessA", 100, 50, "READY"));

    readyQueue_insertTail(
        &q,
        makePCB(402, "ProcessB", 200, 100, "READY"));

    readyQueue_insertTail(
        &q,
        makePCB(403, "ProcessC", 300, 150, "READY"));

    printf("Before deleting tail:\n");
    readyQueue_traverse(&q);

    readyQueue_deleteAtPosition(&q, q.count - 1);

    printf("After deleting tail:\n");
    readyQueue_traverse(&q);

    /* CONSECUTIVE DELETES */

    printf("\n=== CONSECUTIVE DELETE TEST ===\n");

    readyQueue_destroy(&q);
    readyQueue_init(&q);

    readyQueue_insertTail(
        &q,
        makePCB(501, "ProcessA", 100, 50, "READY"));

    readyQueue_insertTail(
        &q,
        makePCB(502, "ProcessB", 200, 100, "READY"));

    readyQueue_insertTail(
        &q,
        makePCB(503, "ProcessC", 300, 150, "READY"));

    readyQueue_insertTail(
        &q,
        makePCB(504, "ProcessD", 400, 200, "READY"));

    printf("Before consecutive deletes:\n");
    readyQueue_traverse(&q);

    readyQueue_deleteAtPosition(&q, 0);
    readyQueue_deleteAtPosition(&q, 0);

    printf("After deleting first two nodes:\n");
    readyQueue_traverse(&q);

    printf("Final count=%d\n", q.count);

    readyQueue_destroy(&q);

    printf("\nallocCount=%d\n", allocCount);

    return 0;
}