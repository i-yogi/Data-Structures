#include<stdio.h>
#include<stdlib.h>

#define parent(x) (x-1)/2
#define left(x) (x*2)+1
#define right(x) (x*2)+2

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

void printHeap(int *arr, int s){
	int i;

	printf("\n");
	for(i=0; i<s; i++)
		printf("\t%d", arr[i]);
	printf("\n");
}

void maxHeapify(int *arr, int idx, int size){
	int max = idx;
	int lch = left(idx);
	int rch = right(idx);

	if( lch<size && arr[lch]>arr[max] )
		max = lch;
	if( rch<size && arr[rch]>arr[max] )
		max = rch;
	if( max != idx ){
		swap(&arr[max], &arr[idx]);
		maxHeapify(arr, max, size);
	}

	// printHeap(arr, size);
}


int main(){

	int *heap;
	int i, s, h;

	printf("\nEnter Size of Binary Heap Tree:");
	scanf("%d", &s);

	heap = (int*)malloc(sizeof(int)*s);

	for(i=0; i<s; i++){
		printf("\nEnter Node Value:");
		scanf("%d", &heap[i]);
	}

	printHeap(heap, s);


	for(h = (s-1)/2; h>=0; h--)
		maxHeapify(heap, h, s);

	printHeap(heap, s);

	return 0;
}