#include "heap.h"

void Heap_InitHeap(Heap_t* h)
{
    h->heapsize = 0;
}

void Swap(HeapNode_t * a, HeapNode_t * b)
{
    HeapNode_t temp;
    temp.key = b->key;
    temp.value = b->value;
    b->key = a->key;
    b->value = a->value;
    a->value = temp.value;
    a->key = temp.key;
}

void HeapifyMin(Heap_t* h, uint8_t parent)
{
    if (h->heapsize == 1) return;
    else
    {
        int smallest = parent;
        int l = 2 * parent + 1;
        int r = 2 * parent + 2;
        if (l < h->heapsize && h->heapArray[l].key < h->heapArray[smallest].key)
            smallest = l;
        if (r < h->heapsize && h->heapArray[r].key < h->heapArray[smallest].key)
            smallest = r;
        if (smallest != parent)
        {
            Swap(&(h->heapArray[parent]), &(h->heapArray[smallest]));
            HeapifyMin(h, smallest);
        }
    }
}
void Heap_Add(Heap_t* h, HeapNode_t n)
{
    if (h->heapsize == MAX_HEAP_SIZE) return;
    if (h->heapsize == 0)
    {
        h->heapArray[0].key = n.key;
        h->heapArray[0].value = n.value;
        h->heapsize += 1;
    }
    else
    {
        h->heapArray[h->heapsize].key = n.key;
        h->heapArray[h->heapsize].value = n.value;
        h->heapsize += 1;
        for (int i = h->heapsize / 2 - 1; i >= 0; i--)
        {
            HeapifyMin(h, i);
        }
    }
}
HeapNode_t Heap_RemoveMin(Heap_t* h)
{
    if (h->heapsize == 0) return (HeapNode_t) { NULL, NULL};
    HeapNode_t min;
    min.key = h->heapArray[0].key;
    min.value = h->heapArray[0].value;

    Swap(&(h->heapArray[0]), &(h->heapArray[h->heapsize - 1]));
    h->heapsize -= 1;
    for (int i = h->heapsize / 2 - 1; i >= 0; i--)
    {
        HeapifyMin(h, i);
    }
    return min;
}