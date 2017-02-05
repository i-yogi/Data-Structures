#include<stdio.h>
#include<stdlib.h>

#define lChild(x) 2*x+1
#define rChild(x) 2*x+2
#define parent(x) (x-1)/2

typedef struct minHeap{
	int *ar;
	int size;
	int cap;
}minHeap;

int underflow(minHeap *hp){
	if( hp == NULL || hp->size == -1 )	return 1;
	else	return 0;
}

void swapElements(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void initHeap(minHeap *hp, int size){
	hp->ar = (int*)calloc(size, sizeof(int));
	hp->size = -1;
	hp->cap = size;
}

void printHeap(minHeap *hp){
	int i=0;

	if( hp == NULL || hp->size == -1 )
		printf("\n*** Error: Heap Underflow! (No data)\n");
	else{
		printf("\n ******** Min-Heap ********\n");
		for(i=0; i<=hp->size; i++){
			if(hp->ar[i] != 0)
				printf(" %d  |", hp->ar[i]);
		}
	}
}

void insertNode(minHeap *hp, int node){
	int i=0;

	if(hp->size == hp->cap)
		printf("\n*** Error: Heap Overflow!");
	else{

		printf("\n about to enter value");

		hp->size++;
		i = hp->size;
		hp->ar[i] = node;

		printf("\n %d value entered", hp->ar[i]);

		while( i!=0 && (hp->ar[i]) < (hp->ar[parent(i)]) ){
			swapElements( &(hp->ar[i]), &(hp->ar[parent(i)]) );
			i = parent(i);
		}
	}
}

int searchNode(minHeap *hp, int val){
	int s=0, i=0;

	if( hp == NULL || hp->size == -1 ){
		printf("\n*** Error: Heap Underflow! (No data)\n");

		return -1;
	}
	else{
		s = hp->size;
		// printf("\n Search: Array size is %d", s);
		for( i=0; i<=s; i++){
			if( hp->ar[i] == val){
				return i;
			}
		}

		return -1;
	}
}

minHeap *changeValue(minHeap *hp, int val, int new){
	int idx=0;

	if(!underflow(hp)){

		idx = searchNode(hp, val);
		hp->ar[idx] = new;
		
		while( idx!=0 && (hp->ar[idx]) < (hp->ar[parent(idx)]) ){
			swapElements( &(hp->ar[idx]), &(hp->ar[parent(idx)]) );
			idx = parent(idx);
		}
	return hp;
	}
	else return NULL;
}

void heapify(minHeap *hp, int idx){
	int p = idx;
	int l = lChild(idx);
	int r = rChild(idx);
	int small =p;

	if( hp->ar[l] < hp->ar[r] )
		small = l;
	else small = r;

	swapElements(&(hp->ar[small]) , &(hp->ar[p]));
}

void deleteNode(minHeap *hp, int val){	
	if(!underflow(hp)){

		hp = changeValue(hp, val, -1);
		// printHeap(hp);

		hp->ar[0] = hp->ar[hp->size];
		hp->size--;
		// printHeap(hp);

		heapify(hp, 0);
		// printHeap(hp);		
	}
}

void printMenu(){
	printf("\n ******** Min-Heap Operations ********\n");
	printf("\n 1. Create new Min-Heap");
	printf("\n 2. Display Min-Heap");
	printf("\n 3. Insert into Min-Heap");
	printf("\n 4. Change node value");
	printf("\n 5. Delete from Min-Heap");
	printf("\n 7. Exit");
	printf("\n\nEnter Choice: ");
}

int main(){
	int ch=0, size=0, val=0, nv=0;
	minHeap *hp = (minHeap*)malloc(sizeof(minHeap));
	do{
		printMenu();
		scanf("%d", &ch);
		switch(ch){
			case 1:
				printf("\nEnter Size of Heap:");
				scanf("%d", &size);
				initHeap(hp, size);
			break;

			case 2:
				printHeap(hp);
			break;

			case 3: 
				printf("\nEnter value to Insert: ");
				scanf("%d", &val);
				insertNode(hp, val);
				printHeap(hp);
			break;

			case 4:
				printf("\nEnter Node value to change: ");
				scanf("%d", &val);
				printf("\nEnter new value: ");
				scanf("%d", &nv);
				changeValue(hp, val, nv);
				printHeap(hp);
			break;

			case 5:
				printf("\nEnter value to Delete: ");
				scanf("%d", &val);
				deleteNode(hp, val);
				printHeap(hp);
			break;				

			case 7:
				printf("\nExiting Program ...\n");
			break;

			default:
				printf("\nError: Wrong Choice!");
			break;
		}
	}while(ch!=7);

	return 0;
}