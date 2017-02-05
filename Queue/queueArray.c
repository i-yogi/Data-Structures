#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
	int size, filled;
	int *qArray;
	int rear;
	int front;
}queue;

queue *initQ(int size){
	queue *q = (struct queue*)malloc(sizeof(queue));
	q->size = size;
	q->qArray = (int*)malloc(sizeof(int)*size);
	q->qArray[q->size] = 0;
	printf("\nQueue with size %d created.\n", size);
	q->front = 0;
	q->rear = size-1;
	q->filled =0;
	return q;
}

void enque(queue *q, int ele){
	q->rear	 = (q->rear+1) % q->size;
	q->qArray[q->rear] = ele;
	q->filled++;
	// printf("\nNo of elements in Queue are %d", q->filled);
	// printf("\n***********%d  Added to q->Rear @ %dpos", q->qArray[q->rear], q->rear);
}

void dequeue(queue *q){

	if(q->front == q->rear){
		q->qArray[q->front] = 0;
		q->front = 0;
		q->rear = q->size-1;
		q->filled--;
		// printf("\nNo of elements in Queue are %d", q->filled);
		return;
	}
		// if(q->front < q->rear){
	else{
		q->qArray[q->front] = 0;
		q->front = (q->front+1) % q->size;
		// printf("\n*********** q->Front is %d", q->front);
		// printf("\n*********** q->Rear is %d", q->rear);

		q->filled--;
		printf("\nNo of elements in Queue are %d", q->filled);
		return;
	}
}

int isEmpty(queue *q){
	if(q->filled == 0)
		return 1;
	else return 0;
}

void display(queue *q){
	int i=0;
	int loop = q->front;

	if (isEmpty(q)){
		printf("\nErr: Underflow! (Queue is Empty)\n\n");
		return;
	}
	else{	
		// printf("\n*********** q->Front is %d", q->front);
		// printf("\n*********** q->Rear is %d", q->rear);
		printf("\n***** QUEUE *****\n Front-->\n");

		for(i=0; i<q->size; i++){

			if(q->qArray[loop] != 0)
				printf("\t%d\n", q->qArray[loop]);
				loop = (loop+1) % q->size;
		}	
	}
}

void displayMenu(){
	printf("\n***** QUEUE OPERATIONS *****\n");
	printf("\n1. Enque element in Queue");
	printf("\n2. Display Queue");
	printf("\n3. Dequeue element from Queue");
	printf("\n4. Exit");
	printf("\n\nEnter choice:\t");
}

int main(){
	int qSize=0, ch=0, no=0, i=0, ele=0, limit=0;

	printf("\nEnter the Max size of Queue:");
	scanf("%d", &qSize);
	queue *q = initQ(qSize);

	do{
		displayMenu();
		scanf("%d", &ch);
		
		switch(ch){
			case 1:
				limit = (q->size-q->filled);
				printf("\nEnter no. of Element to Enque: (%d Slots available): ", limit);
				scanf("%d", &no);
				if(no > limit){
					printf("\nErr: Overflow!");
					printf("\nNo. of slots available: %d", limit);
					break;
				}
				else{
					for(i=0; i<no; i++){
						printf("\nEnter element value (int):\t");
						scanf("%d", &ele);
						enque(q, ele);
					}
					display(q);
					break;
				}
			break;

			case 2:
				display(q);
			break;

			case 3:
				dequeue(q);
				display(q);
			break;
			
			case 4: 
				printf("\nExiting program...\nGood Bye!");
			break;
			
			default: printf("WRONG choice!! \n Please try again...");
			break;
		}
	}while(ch != 4);


	return 0;
}