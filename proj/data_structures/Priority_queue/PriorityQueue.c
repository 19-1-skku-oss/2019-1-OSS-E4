#include "Heap.h"
#include <stdio.h>

typedef Heap PQueue;

void InitPQueue(PQueue *ppqueue);
bool IsPQEmpty(PQueue *ppqueue);
bool ISPQFull(PQueue *ppqueue);

void EnQueue(PQueue *ppqueue, Data data, int priority);
Data DeQueue(PQueue *ppqueue);

int main(void)
{
    PQueue pqueue;
    InitPQueue(&pqueue);
    EnQueue(&pqueue, 1, 1);
    EnQueue(&pqueue, 3, 3);
    EnQueue(&pqueue, 4, 4);
    EnQueue(&pqueue, 2, 2);
    printf("Dequeue : %d\n", DeQueue(&pqueue));
    printf("Dequeue : %d\n", DeQueue(&pqueue));
    return 0;
}

void InitPQueue(PQueue *ppqueue)
{
    InitHeap(ppqueue);
}

bool IsPQEmpty(PQueue *ppqueue)
{
    return IsEmpty(ppqueue);
}

bool IsPQFull(PQueue *ppqueue)
{
    return IsFull(ppqueue);
}

void EnQueue(PQueue *ppqueue, Data data, int priority)
{
    Insert(ppqueue, data, priority);
}

Data DeQueue(PQueue *ppqueue)
{
    return Delete(ppqueue);
}
