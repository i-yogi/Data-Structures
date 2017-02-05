#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
	struct node *previous;
}node;

void insertEnd(node **head, int val){
	node *cur = *head;
	node *new = (node*)malloc(sizeof(node));

	new->data = val;

	if((*head)==NULL){
		new->next = NULL;
		new->previous = NULL;
		(*head) = new;
	}
	else{
		while(cur->next != NULL){
			cur = cur->next;
		}
		new->next = NULL;
		new-> previous = cur;
		cur->next = new;
	}
}

void printLL(node *head){
	node *cur = head;
	printf("\n\n\t\tDoubly Linked List:\n\n\t\t");
	printf("\tNULL<==>");
	while(cur != NULL){
		printf("%d<==>",cur->data);
		cur = cur->next;
	}
	printf("NULL\n\n");
}

void deleteNode(node **head, int key){
	node *cur = *head;

	if(cur->data == key){
		(*head) = cur->next;
		(*head)->previous = NULL;
		free(cur);
	}
	else{
		while(cur != NULL && cur->data != key){
			cur = cur->next;
		}
		if(cur->data == key){
			cur->previous->next = cur->next;
			if(cur->next != NULL)
				cur->next->previous = cur->previous;
			free(cur);
		}
		else{
			printf("\nNode not found!\n");
			return;
		}
	}
}

void printMenu(){
	printf("\n1. Insert");
	printf("\n2. Display");
	// printf("\n3. Add New Head Node");
	printf("\n3. Delete");
	// printf("\n5. Mid Element");
	printf("\n6. Exit");
	printf("\n\nEnter Choice:");
}

int main(){
	int i=0, ch=0, n=0, v=0;
	node *head = NULL;
	do{
		printMenu();
		scanf("%d",&ch);
		switch(ch){
			case 1:
					printf("\n\nEnter No. of nodes:");
      				scanf("%d",&n);

      				for(i=0; i<n; i++){
              			printf("\nEnter node Value:");
              			scanf("%d",&v);
              			insertEnd(&head, v);
	      			} 
					break;
			case 2:
					printLL(head);
					break;
			case 3: 
					printf("\nEnter node Value:");
              		scanf("%d",&v);
					deleteNode(&head, v);
					break;
		}
	}while(ch != 6);
	return 0;
}