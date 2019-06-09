#define MAX_HEAP 1000
typedef enum { false , true } bool;
typedef char Data;

typedef struct {
    Data data;
    int priority;
} HNode;

typedef struct {
    HNode items[ MAX_HEAP + 1];
    int num;
} Heap;

void InitHeap (Heap *pheap)
{
    pheap->num = 0;
}

bool IsEmpty(Heap *pheap)
{
    return pheap->num == 0;
}

bool IsFull(Heap *pheap)
{
    return pheap->num == MAX_HEAP;
}

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

int GetParent(int idx)
{
    return idx / 2;
}

int GetLChild(int idx)
{
    return idx * 2;
}

int GetRChild(int idx)
{
    return idx * 2 + 1;
}

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
