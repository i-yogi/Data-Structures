#include<stdio.h>
#include<stdlib.h>

typedef struct stack{

	int size;
	int top;
	int *st;
}stack;

void printMenu(){

	printf("\n\n******** Stack Operations ********\n");

	printf("\n 1. Initialize stack");
	printf("\n 2. Insert value into stack");
	printf("\n 3. Remove item from stack");
	printf("\n 4. Display stack");
	printf("\n 5. Exit");
	printf("\n\n Enter Choice: ");
}

void initStack(stack **st, int size){

	stack *stk = *st;

	stk->size = size;	
	stk->top = -1;
	stk->st = (int*)malloc(sizeof(int)*size);

	printf("\n\n Stack initialized with size of %d", size);
}

int overflow(stack *stack){

	if(stack->top == stack->size-1)
		return 1;
	else return 0;
}

int underflow(stack *stack){

	if(stack->top == -1)
		return 1;
	else return 0;
}

void displayStack(stack *st){

	if(!underflow(st)){

		int i=0;

		printf("\n ***** Stack Size = %d*****", st->size);
		for( i=st->top; i>=0; i--){

			printf("\n%d", st->st[i]);
		}
	} else {
		printf("\n ERROR: Stack Underflow!");
	}
}

void push(stack **st, int value){
	
	stack *stk = *st;	

	if(!overflow(stk)){

		stk->top += 1;
		stk->st[stk->top] = value;
	} else {
		printf("\n ERROR: Stack Overflow!");
	}
}

int main(){

	stack *myStack = (struct stack*)malloc(sizeof(stack));

	int size=0;
	int ch = 0;
	int value=0;
	int set = 0;

	do{
		printMenu();
		scanf("%d", &ch);

		switch(ch){
			
			case 1:	
				printf("\nEnter stack capacity: ");
				scanf("%d", &size);
				initStack(&myStack, size);
				set = 1;
				break;

			case 2:
				if(set){
					printf("\n\nEnter value to push into stack:");
					scanf("%d", &value);
					push(&myStack, value);					
				} else {
					printf("\n ERROR: Stack Underflow!");
				}
				break;
			case 3:
				if(!underflow(myStack)){
					pop();
				}
				else {
					printf("\n ERROR: Stack Underflow!");
				}
				break;

			case 4:
				displayStack(myStack);
				break;

		}
	}while( ch!=5 );
	return 0;
}