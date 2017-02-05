#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
	int front, end;
	int size;
	int *arr;
}queue;

void enqueue(queue *que, int val){

	que->end += 1;
	que->arr[que->end] = val;
}

void dequeue(queue *que){

	que->front += 1;
	printf("\nElement removed from queue: %d", que->arr[que->front]);
}

void printQueue(queue *que){

	int i;

	printf("\nQueue contains: \n");
	for(i=que->arr[que->front]; i<que->size; i++){
		printf("\t%d", que->arr[i]);
	}
}

int main(){

	int s, i, val;

	printf("\nEnter Queue Size:");
	scanf("%d", &s);

	queue *que = (queue*)malloc(sizeof(queue));
	que->front = que->end = -1;
	que->size = s;
	que->arr  = (int*)malloc(sizeof(int)*s);

	for(i=0; i<s; i++){
		printf("\nEnter Element into Queue:");
		scanf("%d", &val);	

		enqueue(que, val);	
	}

	printQueue(que);

	dequeue(que);

	printQueue(que);

	return 0;
}