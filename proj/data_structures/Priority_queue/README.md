# Priority Queue


## Definition

 Priority queue is an abstract data type which is like a regular queue or stack data structure, but where additionally each element has a "priority" associated with it.
 In a priority queue, an element with high priority is served before an element with low priority.
 In some implementations, if two elements have the same priority, they are served according to the order in which they were enqueued, while in other implementations, ordering of elements with the same priority is undefined.
 

***

## Operation

 
### Heap.h

* int GetParent(int idx); 
This function returns idx / 2, the parent node's idx.

* int GetLChild(int idx);
This functino returns idx * 2, the left child node's idx.

* int GetRChild(int idx);
This function returns idx * 2 + 1, the right child node's idx.
* void Insert(Heap *pheap, Data, int priority);

* int GetHighPriorityChild(Heap *pheap, int idx);
This function returns child node's idx which has higher priority.
- Code
```c
int GetHighPriorityChild(Heap *pheap, int idx)
{
    if (GetLChild(idx) > pheap->num)
        return 0;
    else if (GetLChild(idx) == pheap->num)
        return GetLChild(idx);
    else
    {
        int left = GetLChild(idx), right = GetRChild(idx);
        if (pheap->items[left].priority > pheap->items[right].priority) return left;
        else return right;
    }
}
```

- Code
```c
void Insert(Heap *pheap, Data item, int priority)
{
    HNode newNode;
    int idx = pheap->num + 1;
    if (IsFull(pheap)) exit(1);
    while (idx > 1) {
        int parent = GetParent(idx);
        if (priority > pheap->items[parent].priority) {
            pheap->items[idx] = pheap->items[parent];
            idx = parent;
        }
        else break;
    }
    newNode.data = data;
    newNode.priority = priority;

    pheap->items[idx] = newNode;
    pheap->num++;
}
```

* Data Delete(Heap *pheap);

```c
Data delete(Heap *pheap)
{
    Data max = pheap->items[1].data;
    HNode last = pheap->items[pheap->num];
    int parent = 1, child;
    while (child = GetHighPriorityChild(pheap, parent)) {
        if (last.priority < pheap->items[child].priority) {
            pheap->items[parent] = pheap->items[child];
            parent = child;
        }
        else break;
    }
    pheap->items[parent] = last;
    pheap->num--;

    return max;
}
```
