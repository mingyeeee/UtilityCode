#include <stdio.h>
#include "heap.h"

void printHeap(Heap_t* h)
{
	for (uint8_t i = 0; i < h->heapsize; i++)
	{
		printf("Node %d (%d, %d)\n\r", i, h->heapArray[i].key, h->heapArray[i].value.standardMessageID);
	}
}

void printNode(HeapNode_t n)
{
	printf("Min Node (%d, %d)\n\r", n.key, n.value.standardMessageID);
}

void main()
{
	Heap_t h;
	Heap_InitHeap(&h);
	Heap_Add(&h, (HeapNode_t) {3, (iCommsMessage_t) { 3, 4, 1 }});
	printf("Added 3,1\n");
	printHeap(&h);
	Heap_Add(&h, (HeapNode_t) { 4, (iCommsMessage_t) { 4, 4, 1 }});
	printf("Added 4,3\n");
	printHeap(&h);
	Heap_Add(&h, (HeapNode_t) { 1, (iCommsMessage_t) { 1, 4, 1 }});
	printf("Added 1,2\n");
	printHeap(&h);

	HeapNode_t min = Heap_RemoveMin(&h);
	printNode(min);
	printHeap(&h);


	Heap_Add(&h, (HeapNode_t) { 6, (iCommsMessage_t) { 6, 4, 1 }});
	printf("Added 6,8\n");
	printHeap(&h);
	Heap_Add(&h, (HeapNode_t) { 2, (iCommsMessage_t) { 2, 4, 1 }});
	printf("Added 2,5\n");
	printHeap(&h);

	min = Heap_RemoveMin(&h);
	printNode(min);
	printHeap(&h);
	
}