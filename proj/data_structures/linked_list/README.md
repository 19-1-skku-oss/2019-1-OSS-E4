# Linked List

***

## Definition

Linked list is a linear collection of data elements, whose order is not given by their physical placement in memory. Instead, each element points to the next. It is a data structure consisting of a collection of nodes which together represent a sequence. In its most basic form, each node contains: data, and a reference (in other words, a link) to the next node in the sequence. This structure allows for efficient insertion or removal of elements from any position in the sequence during iteration. More complex variants add additional links, allowing more efficient insertion or removal of nodes at arbitrary positions. A drawback of linked lists is that access time is linear (and difficult to pipeline). Faster access, such as random access, is not feasible. Arrays have better cache locality compared to linked lists.
![image](https://upload.wikimedia.org/wikipedia/commons/thumb/6/6d/Singly-linked-list.svg/612px-Singly-linked-list.svg.png)

## Circular Linked List

### Outline
In the last node of a list, the link field often contains a null reference, a special value is used to indicate the lack of further nodes. A less common convention is to make it point to the first node of the list; in that case, the list is said to be 'circular' or 'circularly linked'; otherwise, it is said to be 'open' or 'linear'. It is a list where the last pointer points to the first node.
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
* void RemoveInitItem(CircularList *plist);
   - Code
* void RemoveFirst(CircularList *plist);
   - Code
* void RemoveLast(CircularList *plist);
   - Code
* void RemoveMiddle(CircularList *plist, int pos);
   - Code
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
