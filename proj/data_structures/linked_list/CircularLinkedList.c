#include <stdio.h>

typedef enum {false, true} bool;

typedef int Data;
typedef struct __Node
{
    Data item;
    struct __Node *next;
} Node;

typedef struct
{
    Node *tail;
    int len;
} CircularList;

void InitList(CircularList *plist);
void InsertInitItem(CircularList *plist, Data item);
void InsertFirst(CircularList *plist, Data item);
void InsertLast(CircularList *plist, Data item);
void InsertMiddle(CircularList *plist, int pos, Data item);
void RemoveInitItem(CircularList *plist);
void RemoveFirst(CircularList *plist);
void RemoveLast(CircularList *plist);
void RemoveMiddle(CircularList *plist, int pos);
void PrintList(CircularList *plist);

int main(void)
{
    CircularList list;
    InitList(&list);
    InsertFirst(&list, 1);
    InsertLast(&list, 2);
    InsertLast(&list, 4);
    InsertMiddle(&list, 2, 3);
    PrintList(&list);
    RemoveFirst(&list);
    RemoveLast(&list);
    PrintList(&list);
    return 0;
}

void InsertInitItem(CircularList *plist, Data item)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->item = item;
    newNode->next = newNode;

    plist->tail = newNode;
    plist->len++;
}

void InsertFirst(CircularList *plist, Data item)
{
    if (plist->len == 0) InsertInitItem(plist, item);
    else {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->item = item;
        newNode->next = plist->tail->next;

        plist->tail->next = newNode;
        plist->len++;
    }
}

void InsertLast(CircularList *plist, Data item)
{
    if (plist->len == 0) InsertInitItem(plist, item);
    else {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->item = item;
        newNode->next = plist->tail->next;

        plist->tail->next = newNode;
        plist->tail = newNode;
        plist->len++;
    }
}

void InsertMiddle(CircularList *plist, int pos, Data item)
{
    if (plist->len == 0)
        InsertInitItem(plist, item);
    else
    {
        Node *cur, *newNode;
        *cur = plist->tail;
        for (int i = 0; i < pos; i++)
            cur = cur->next;

        newNode = (Node*)malloc(sizeof(Node));
        newNode->item = item;
        newNode->next = cur->next;
        cur->next = newNode;
        plist->len++;
    }
}

void RemoveInitItem(CircularList *plist)
{
    if (IsEmpty(plist)) exit(1);
    if (plist->len == 1) {
        free(plist->tail);
        plist->len--;
        plist->tail = NULL;
    }
}

void RemoveFirst(CircularList *plist)
{
    if (plist->len == 1)
        RemoveInitItem(plist);
    else {
        Node *temp = plist->tail->next;
        plist->tail->next = temp->next;

        free(temp);
        plist->len--;
    }
}

void RemoveLast(CiruclarList *plist)
{
    if (plist->len == 1)
        RemoveInitItem(plist);
    else {
        Node *cur, *temp;
        cur = plist->tail;
        for (int i = 0; i < plist->len - 1; i++)
            cur = cur->next;
        temp = cur->next;
        cur->next = temp->next;

        free(temp);
        plist->tail = cur;
        plist->len--;
    }
}

void RemoveLast(CiruclarList *plist, int pos)
{
    if (plist->len == 1)
        RemoveInitItem(plist);
    else {
        Node *cur, *temp;
        cur = plist->tail;
        for (int i = 0; i < pos; i++)
            cur = cur->next;
        temp = cur->next;
        cur->next = temp->next;

        free(temp);
        plist->tail = cur;
        plist->len--;
    }
}

void PrintList(CircularList *plist)
{
    Node *temp = plist->tail;
    for (int i = 0; i <plist->len; i++) {
        temp = temp->next;
        printf("%d", temp->item);
    }
}
