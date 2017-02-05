#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

void insertFront(node **head, int val){
	node *new = (node*)malloc(sizeof(node));
	new->data = val;
	new->next = *head;
	*head = new;
}

void insertEnd(node **head, int val){
	node *cur = *head;
	
	node *new = (node*)malloc(sizeof(node));
	new->data = val;
	new->next = NULL;

	if((*head)==NULL){
		*head = new;
		printf("\nHead = %d\n",(*head)->data);
	}
	else{
		while(cur->next != NULL){
		cur = cur->next;
		}
		cur->next = new;
	}
}

void printLL(node *head){
	node *cur = head;
	printf("\n\n\t\tSingly Linked List:\n\n\t\t");
	while(cur != NULL){
		printf("%d-->",cur->data);
		cur = cur->next;
	}
	printf("NULL\n\n");
}

void findMid(node *head){
	node *slowPointer = head;
	node *fastPointer = head;

	while(fastPointer != NULL && fastPointer->next != NULL){
		fastPointer = fastPointer->next->next;
		slowPointer = slowPointer->next;
	}
	printf("\nMid Elemnt is %d\n",slowPointer->data);
}

void deleteKey(node **head, int key){
	node *ref = *head, *prev=NULL;

//Key at Head node
	if(ref != NULL && ref->data == key){
		(*head) = ref->next;
		free(ref);
		return;
	}
	else{
		while(ref != NULL && ref->data != key){
			prev = ref;
			ref = ref->next;
		}
//Key NOT found
		if(ref == NULL){
			printf("\nKey Not found!\n");
			return;	
		} 
		else{
			prev->next = ref->next;
			free(ref);
			return;
		}
	}
}

// void deleteKey(node **head, int key){
// 	node *cur = *head, *prev = NULL;

// 	if((*head)->data == key){
// 		(*head) = cur->next;
// 		free(cur);
// 	}
// 	else{
// 		while(cur->next != NULL && cur->data != key){
// 			prev = cur;
// 			cur = cur->next;
// 		}
// 		if(cur->data == key){
// 			prev->next = cur->next;
// 			free(cur);
// 		}
// 		else{
// 			printf("\nNode not found!\n");
// 		}
// 	}
// }

void weavinOption(node *head){
	node *slow = head;
	node *fast = head;
	int temp;

	while(fast != NULL && fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	printf("\nMid Point is %d", slow->data);
	fast = head;
	while(slow->next != NULL){
		temp = fast->next->data;
		fast->next->data = slow->data;
		slow->data = temp;

		slow = slow->next;
		fast = fast->next->next;
	}

	printLL(head);
}

void printMenu(){
	printf("\n1. Insert");
	printf("\n2. Display");
	printf("\n3. Add New Head Node");
	printf("\n4. Delete");
	printf("\n5. Mid Element");
	printf("\n6. Weaving Function");
	printf("\n7. Delete node next to k");
	printf("\n8. Exit");
	printf("\n\nEnter Choice:");
}

int main(){
	int n=0, i=0, v=0;
	int ch=0;
	node *head=NULL;

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
					printf("\nEnter new Head Value:");
					scanf("%d",&v);
					insertFront(&head, v);
					break;
			case 4:
					printf("\nEnter node value to delete:");
					scanf("%d",&v);
					deleteKey(&head, v);
					break;			
			case 5:
					findMid(head);
					break;
			case 6: 
					weavinOption(head);
					break;

			case 7:		
					printf("\nEnter k->next to delete:");
					scanf("%d",&v);
					deleteKNext(&head);
					break;
		}
	}while(ch!=8);
	return 0;
}
