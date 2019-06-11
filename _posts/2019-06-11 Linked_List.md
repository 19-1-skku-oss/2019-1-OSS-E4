# Linked List

***

## Definition

Linked list is a linear collection of data elements, whose order is not given by their physical placement in memory. Instead, each element points to the next. It is a data structure consisting of a collection of nodes which together represent a sequence. In its most basic form, each node contains: data, and a reference (in other words, a link) to the next node in the sequence. This structure allows for efficient insertion or removal of elements from any position in the sequence during iteration. More complex variants add additional links, allowing more efficient insertion or removal of nodes at arbitrary positions. A drawback of linked lists is that access time is linear (and difficult to pipeline). Faster access, such as random access, is not feasible. Arrays have better cache locality compared to linked lists.<br><br>
![image](https://upload.wikimedia.org/wikipedia/commons/thumb/6/6d/Singly-linked-list.svg/612px-Singly-linked-list.svg.png)

## Circular Linked List

### Outline
In the last node of a list, the link field often contains a null reference, a special value is used to indicate the lack of further nodes. A less common convention is to make it point to the first node of the list; in that case, the list is said to be 'circular' or 'circularly linked'; otherwise, it is said to be 'open' or 'linear'. It is a list where the last pointer points to the first node.<br><br>
![image](https://upload.wikimedia.org/wikipedia/commons/thumb/d/df/Circularly-linked-list.svg/525px-Circularly-linked-list.svg.png)
### Operations
* typedef Node  

   - Code
```c
typedef struct __Node {
    struct __Node *next;
    int item;
} Node;
```

* typedef CircularLinkedList
   - Code
```c
typedef struct {
    struct Node* tail;
    int len;
} CircularLinkedList
```

* void InsertInitItem(CircularList *plist, Data item);
   - Code
```c
void InsertInitItem(CircularList *plist, Data item)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->item = item;
    newNode->next = newNode;

    plist->tail = newNode;
    plist->len++;
}
```
* void InsertFirst(CircularList *plist, Data item);
   - Code
```c
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
```
* void InsertLast(CircularList *plist, Data item);
   - Code
```c
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
```
* void InsertMiddle(CircularList *plist, int pos, Data item);
   - Code
```c
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
```
* void RemoveInitItem(CircularList *plist);
   - Code
```c
void RemoveInitItem(CircularList *plist)
{
    if (IsEmpty(plist)) exit(1);
    if (plist->len == 1) {
        free(plist->tail);
        plist->len--;
        plist->tail = NULL;
    }
}
```
* void RemoveFirst(CircularList *plist);
   - Code
```c
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
```
* void RemoveLast(CircularList *plist);
   - Code
```c
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
```
* void RemoveMiddle(CircularList *plist, int pos);
   - Code
```c
void RemoveMiddle(CiruclarList *plist, int pos)
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
```
## Double linked list

### Outline
In a double linked list, each node contains, besides the next-node link, a second link field pointing to the 'previous' node in the sequence. The two links may be called 'forward('s') and 'backwards', or 'next' and 'prev'('previous').
![image](https://upload.wikimedia.org/wikipedia/commons/thumb/5/5e/Doubly-linked-list.svg/915px-Doubly-linked-list.svg.png)
### Operations
* typedef struct __Node  

   - Code
```c
typedef struct __Node {
    struct __Node *next;
    struct __Node *prev;
    int item;
}
```
* void InitDLinkedList(DoubleLinkedList *plist);
   - Code
```c
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
```
* void InsertMiddle(DoubleLinkedList *plist, int pos, Data data);
   - Code
```c
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
```
* void InsertFirst(DoubleLinkedList *plist, Data data);
   - Code
```c
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
```
* void InsertLast(DobuleLinkedList *plist, Data data);
   - Code
```c
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
```
* void RemoveFirst(DoubleLinkedList *plist);
   - Code
```c
void RemoveFirst(DoubleLinkedList *plist)
{
	Node *temp;
	temp = plist->head->next;
	temp->next->prev=plist->head;
	plist->head->next=temp->next;
	plist->len--;
	free(temp);
}
```
* void RemoveMiddle(DoubleLinkedList *plist, int pos);
   - Code
```c
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
```
* void RemoveLast(DoubleLinkedList *plist);
   - Code
```c
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
```
