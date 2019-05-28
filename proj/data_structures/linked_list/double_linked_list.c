#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct __Node {
	struct __Node *prev;
	struct __Node *next;
	Data data;
} Node;

typedef struct {
	int count;
	Node *head;
} DoubleLinkedList;

void InitDLinkedList(DoubleLinkedList *plist);
void InsertMiddle(DoubleLinkedList *plist, int pos, Data data);
void RemoveMiddle(DoubleLinkedList *plist, int pos);
void InsertFirst(DoubleLinkedList *plist, Data data);
void InsertLast(DobuleLinkedList *plist, Data data);
void RemoveFirst(DoubleLinkedList *plist);
void RemoveLast(DoubleLinkedList *plist);
void PrintList(DoubleLinkedList *plist);

int main(void)
{
	DoubleLinkedList list;
	InitDLinkedList(&list);
	printf("==This program shows how double linked list works==\n");
	InsertFirst(&list, 5);
	InsertFirst(&list, 2);
	InsertLast(&list, 6);
	PrintList(&list);
}

void InitDLinkedList(DoubleLinkedList *plist)
{
	Node *dummy1;
	Node *dummy2;
	dummy1 = (Node*)malloc(sizeof(Node));
	dummy2 = (Node*)malloc(sizeof(Node));

	dummy1->prev = NULL;
	dummy2->next = NULL;
	dummy1->next = dummy2;
	dummy2->prev = dummy1;

	plist->head = dummy1;
	plist->count = 0;
}

void InsertMiddle(DoubleLinkedList *plist, int pos, Data data)
{
	if (pos < 0 || pos > plist->len) exit(1);
	Node *cur, *newNode;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = NULL;
	
	cur = plist->head;
	for (int i = 0; i < pos; i++) {
		cur = cur->next;
	}

	newNode->prev=cur;
	newNode->next=cur->next;
	cur->next->prev=newNode;
	cur->next=newNode;
	plist->len++;
}

void RemoveMiddle(DoubleLinkedList *plist, int pos, Data data)
{
	Node *cur, *temp;
	if (plist->len == 0 || pos < 0 || pos >= plist->len) exit(1);
	cur = plist->head;
	for (int i = 0; i < pos; i++) {
		cur = cur->next;
	}
	temp = cur->next;
	temp->next->prev = cur;
	cur->next = temp->next;
	plist->len--;
	free(temp);
}

void InsertFirst(DoubleLinkedList *plist, Data data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev=plist->head;
	newNode->next=plist->head->next;
	plist->head->next->prev=newNode;
	plist->head->next=newNode;
	plist->len++;
}

void InsertLast(DoubleLinkedList *plist, Data data)
{
	Node *cur;
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	cur = plist->head;
	for (int i = 0; i < plist->len; i++){
		cur = cur->next;
	}
	newNode->prev=cur;
	newNode->next=cur->next;
	cur->next->prev=newNode;
	cur->next=newNode;
	plist->len++;
}

void RemoveFirst(DoubleLinkedList *plist)
{
	Node *temp;
	temp = plist->head->next;
	temp->next->prev=plist->head;
	plist->head->next=temp->next;
	plist->len--;
	free(temp);
}

void RemoveLast(DoubleLinkedList *plist)
{
	Node *cur, *temp;
	cur = plist->head;
	for (int i = 0; i < plist->len; i++)
		cur = cur->next;
	temp = cur->next;
	temp->next->prev = cur;
	cur->next = temp->next;
	plist->len--;
	free(temp);
}

void PrintList(DoubleLinkedList *plist)
{
	Node *cur = plist->head;
	printf("List : ");
	for (int i = 0; i < plist->len; i++) {
		cur = cur->next;
		printf("%d ", cur->data);
	}
	printf("\n");
}
