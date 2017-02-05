#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	
	int val;
	struct node *left, *right;
}node;

typedef struct que{

	node **ar;
	int front, rear, size, cap;
}que;

void insertNode(node **rt, int val){

	node *nw = (node*)malloc(sizeof(node));
	nw->val = val;
	nw->left = nw->right = NULL;

	if( *rt == NULL)
		*rt = nw;
	else if( val< (*rt)->val)
		insertNode( &(*rt)->left, val);
	else if( val> (*rt)->val)
		insertNode( &(*rt)->right, val);
	else printf("\nErr: Duplicate not allowed");
}

void insertNodes(node **rt){

	int l, i, k;

	printf("Enter number of nodes: ");
	scanf("%d", &l);

	for( i=0; i<l; i++){

		printf("Enter node value: ");
		scanf("%d", &k);	
		insertNode(&(*rt), k);
	}
}


int incr(int index, int incr, int cap){

	return (index+incr)%cap;
}


void enqueue(que **q, node *node){

	if( (*q)->size == (*q)->cap){
		
		printf("\nErr: Queue Overflow!");
		return;
	} else{

		(*q)->size++;
		(*q)->rear = incr((*q)->rear, 1, (*q)->cap);;
		(*q)->ar[(*q)->rear] = node;
	}
}

node *dequeue(que **q){

	node *res;

	if( (*q)->size == -1){
		
		printf("\nErr: Queue Underflow!");
		return NULL;
	} else{

		(*q)->size--;
		res = (*q)->ar[(*q)->front];
		(*q)->front = incr((*q)->front, 1, (*q)->cap);;

		return res;
	}
}

int sizeT(node *rt){

	int ls, rs;

	if (rt == NULL)
		return 0;
	else{

		ls = sizeT(rt->left);
		rs = sizeT(rt->right);

		return (ls+rs+1);
	}
}

void bfsQ(node *rt){

	node *hd = rt;

	que *q = (que*) malloc(sizeof(que));
	q->rear = q->size = -1;
	q->front = 0;
	q->cap = sizeT(rt);
	q->ar = (node**) malloc(sizeof(node*)*q->cap);

	printf("\n Tree size is %d\n", q->cap);

	while(hd){

		printf(" %d ", hd->val);

		if(hd->left)
			enqueue(&q, hd->left);
		if(hd->right)
			enqueue(&q, hd->right);

		hd = dequeue(&q);
	}
}

void printMenu(){

	printf("\n\n1. Insert nodes");
	printf("\n2. BFS using Q");
	printf("\n0. Quit");
	printf("\n\nEnter op-code:\t");
}

int main(){

	int ch;

	node *rt = NULL;

	do{

		printMenu();
		scanf("%d", &ch);

		switch(ch){

			case 0:
				printf("\nExiting Program...\n");
			break;

			case 1:
				insertNodes(&rt);
			break;

			case 2:
				bfsQ(rt);
			break;
		}
	}while( ch!=0);

	return 0;
}