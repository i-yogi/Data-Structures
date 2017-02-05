#include<stdio.h>
#include<stdlib.h>

typedef struct stackN{
	int data;
	struct stackN *next;
}stackN;

void displayStack(stackN *top){
	printf("\n Stack Contains:\n Top->");
	while(top != NULL){
		printf("\t%d", top->data);
		top = top->next;
	}
}

void push(stackN **top, int val){
	stackN *newTop = (stackN*)malloc(sizeof(stackN));

	newTop->data = val;
	newTop->next = *top;

	*top = newTop;
}

void pop(stackN **head){
	stackN *del = *head;

	*head = del->next;
	free(del);

	displayStack(*head);
}

int isEmpty(stackN *top){
	if(top == NULL){
		return 1;
	}
	else return 0;
}

void printMenu(){
	printf("\n****** Stack Using Linked List ******");
	printf("\n1. Push Element");
	printf("\n2. Display Stack");
	printf("\n3. Pop Element (top)");
	printf("\n4. Exit");

	printf("\n\nEnter Your Choice:\t");
}

int main(){
	int ch=0, val=0;
	stackN *root=NULL;
	do{
		printMenu();
		scanf("%d", &ch);

		switch(ch){
			case 1:
				printf("\nEnter Value:");
				scanf("%d", &val);
				push(&root, val);
				break;

			case 2:
				if(isEmpty(root))
					printf("\n*** Stack is Empty ***\n");
				else displayStack(root);
				break;

			case 3:
				pop(&root);
				break;

			case 4:
				printf("\nExiting Program...\n");
				break;

			default: 
				printf("\nWrong Choice... Try Again!\n");
				break;
		}
	}while(ch!=4);
	return 0;
}