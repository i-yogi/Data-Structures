#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int d;
	struct node *l, *r;
}node;

typedef struct ar{
	node **a;
}ar;

void enque( ar **q, node *e){
	if( (*q)== NULL || e == NULL) return;
	
}

void bfs( node *hd, int s){
	//Init que
	ar *q = (ar*)malloc( sizeof(ar));
	q->a = (node**)malloc( sizeof(node)*s);

	while( hd!= NULL){
		printf(" %d ", hd->d); 
		if( hd->l != NULL)	enque(&q, hd->r);
		if( hd->r != NULL)	enque(&q, hd->r);
		hd = deque(&q);
	}
}

void addNode( node **hd, int v){
	node *cur = *hd;
	node *new = (node*)malloc( sizeof(node));
	new->d = v;
	new->l = new->r = NULL;
	if( cur == NULL){	//first node = head
		(*hd) = new;
	} else {
		if( cur->d == v) printf("\n Error: Duplicate value!\n");
		if( cur->d < v) addNode( &cur->l, v);
		if( cur->d > v) addNode( &cur->r, v);
	}
}

int main(){	
	int i, s, v;
	node *hd = NULL;
	printf("\nEnter no. of nodes : ");
	scanf("%d", &s);
	for( i=0; i< s; i++){
		printf("\nEnter node value : ");
		scanf("%d", &v);
		addNode(&hd, v);
	}
	//printf("\n Head is %d : ", hd->d);
	bfs(hd, s);
	return 1;
}