//Yogesh Isawe
//13th Feb 2016
//Stack Using 'Array'

#include<stdio.h>
#include<stdlib.h>


typedef struct stack{
	int top;
	int cap;
	int *arr;
}stack;

stack *createStack(int cap){
	stack *stack = (struct stack*)malloc(sizeof(stack));

	stack->top = -1;
	stack->cap = cap;
	stack->arr = (int*)malloc(sizeof(int)*cap);
	printf("\nStack created with capacity= %d\n", cap);
	return stack;
}

int isFull(stack *stack){
	if(stack->top == stack->cap-1)
		return 1;
	else return 0;
}

int isEmpty(stack *stack){
	if(stack->top == -1)
		return 1;
	else return 0;
}

void push(stack *stack, int val){
	// if(isFull(stack)){
	// 	printf("\nStack full!");
	// 	return;
	// }
	// else{
		stack->arr[++stack->top] = val;
		printf("\n%d pushed in Stack @position #%d\n", val, stack->top);
	// }
}

void pop(stack *stack){
	printf("\nTop element from stack = %d, REMOVED!", stack->arr[stack->top]);
	stack->top--;
}

void displayStack(stack *stack){
	int i=0;
	int size= stack->top;

	if (isEmpty(stack))
	{
		printf("\nStack Empty!");
		return;
	}
	else{
			do{
				printf("\n |%d| ", stack->arr[size]);
				if(size == stack->top){
					printf(" <-Top");
				}
				size--;
			}while(size >= 0);

			printf("\nStack");
		}
}

void displayMenu(){
	printf("\n***** STACK OPERATIONS *****\n");
	printf("\n1. PUSH element in Stack");
	printf("\n2. Display Stack");
	printf("\n3. POP element from Stack");
	printf("\n4. Exit");
	printf("\n\nEnter choice:\t");
}

int main(){
	int cap=0;
	int item=0;
	int ch=0;
	int i=0, j=0;
	
	printf("\nEnter max size for a Stack: ");
	scanf("%d", &cap);
	stack *stack = createStack(cap);

	do{
		displayMenu();
		scanf("%d", &ch);
		
		switch(ch){
			case 1:
				printf("\nNo. of elements to PUSH in Stack: ");
				scanf("%d", &j);
				
				for(i=0; i<j; i++){
					if(isFull(stack)){
						printf("\nStack Full!");
						printf("\tErr: Stack Overflow!");
						break;
					}
					else{
						printf("\nEnter element: ");
						scanf("%d", &item);
						push(stack, item);
					}
				}
				break;
			case 2:
				displayStack(stack);
				break;
			case 3:
				if(isEmpty(stack)){
					printf("\nStack Empty!");
					printf("\tErr: Stack Underflow!");
					break;
				}
				else {
					pop(stack);
					displayStack(stack);
				}
				break;
			case 4: 
				printf("\nExiting program...\nGood Bye!");
				break;
			default: printf("WRONG choice!! \n Please try again...");
		}
	}while(ch != 4);

	return 0;
}