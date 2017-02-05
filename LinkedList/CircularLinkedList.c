#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

void insertNode(node **head, int val){
	node *new = (node*)malloc(sizeof(node));
	node *cur = *head;
	
	new->data = val;

	if((*head)==NULL){
		new->next = new;
		(*head) = new;
	}
	else{
		while(cur->next != (*head)){
			cur = cur->next;
		}
		new->next = (*head);
		cur->next = new;
	}
}

void printLL(node *head){
	node *cur = head;
	printf("\t\t");
	do{
		printf("%d-->",cur->data);
		cur = cur->next;
	}while(cur != head);
	printf("|repeat");
}

void printMenu(){
	printf("\n1. Insert Node");
	printf("\n2. Display Circular Linked List");
	printf("\n3. Exit");
	printf("\nEnter Option:\n");
}

int main(){
	node *head = NULL;
	node *cur = head;
	int i=0, v=0, n=0, ch=0;	

	do{
		printMenu();
		scanf("%d",&ch);
		switch(ch){
			case 1:
					printf("\nEnter No. of nodes:");
					scanf("%d",&n);
	
					for(i=0; i<n; i++){
						printf("\n\tEnter Value:");
						scanf("%d",&v);
						insertNode(&head, v);
					}
					break;
			case 2:
					printLL(head);
					break;
		}
	}while(ch != 3);

	return 0;
}