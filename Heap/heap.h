#ifndef __HEAP_H__
#define __HEAP_H__
#include <stdint.h>

#define MAX_HEAP_SIZE 32
#define PUBLIC
#define PRIVATE

typedef struct HeapNode
{
    uint16_t key;
    uint8_t value;
} HeapNode_t;

typedef struct heap
{
    uint8_t heapsize;
    HeapNode_t heapArray[MAX_HEAP_SIZE];
} Heap_t;

PUBLIC void Heap_InitHeap(Heap_t * h);
PUBLIC void Heap_Add(Heap_t * h, HeapNode_t n);
PUBLIC HeapNode_t Heap_RemoveMin(Heap_t* h);
PRIVATE void HeapifyMin(Heap_t* h, uint8_t parent);
PRIVATE void Swap(HeapNode_t* a, HeapNode_t* b);
#endif