#include<stdio.h>
#include<stdlib.h>

typedef struct node{

	int ver;
	struct node *next;
}node;

typedef struct graph{

	int noV;
	node **ar;
}graph;

void addEdge(graph *g, int x, int y){

	node *des = (node*) malloc( sizeof(node));
	des->ver = y;

	if( g->ar[x] == NULL){

		printf("\nEmpty entry at %d\n", x);
		
		g->ar[x] = (node*) malloc( sizeof(node));
		g->ar[x]->ver = x;
		g->ar[x]->next = des;
		des->next = NULL;
	}
	else {

		node *cur = g->ar[x];
		while( cur->next != NULL)
			cur = cur->next;

		cur->next = des;
		des->next = NULL;
		printf("\nInserted after %d\n", cur->ver);
	}
}

void bfs( graph *g, int v){

	int s = g->noV;
	node *cur = g->ar[v];

	//INIT visited array -> none visited
	int visited[s];
	for( int i=0; i<s; i++)
		visited[i] = 0;

	//INIT que
	int front =0, rear = 0;
	int que[s*s];

	//Mark 1st node visited and enque it
	visited[v] = 1;
	que[rear++] = cur->ver;

	while( front != rear){

		//Deque node
		int de = que[front++];
		printf("%d\t", de);

		node *cur = g->ar[de];

		while( cur != NULL ){

			if( !visited[cur->ver]){

				que[rear++] = cur->ver; 
				visited[cur->ver] = 1;
			}

			cur = cur->next;
		}
	}
}

void goDp( graph *g, int vst[], int v){

	node *cur = g->ar[v];

	vst[v] = 1;
	printf("%d\t", cur->ver);

	while( cur != NULL){

		if( !vst[cur->ver])
			goDp( g, vst, cur->ver);

		cur = cur->next;
	}
}

void dfs( graph *g, int v){

	//init visited array
	int s = g->noV;

	int visited[s];
	for( int i=0; i<s; i++)
		visited[i] = 0;

	goDp( g, visited, v);
}

int main(){

	int i, v, e;
	int x, y;

	printf("\nNo. of vertices: \t");
	scanf("%d", &v);

	graph *g = (graph*) malloc( sizeof(graph));
	g->noV = v;
	g->ar = (node**) malloc( sizeof(node)*v);

	printf("\nEnter no. of edges: \t");
	scanf("%d", &e);

	for(i=0; i<e; i++){

		printf("\nEnter (src, dstn): \t");
		scanf("%d %d", &x, &y);

		addEdge(g, x, y);
	}

	for ( i=0; i<v; i++){

		node *cur = g->ar[i];

		printf("\n");

		while( cur != NULL ){

			printf("%d->", cur->ver);
			cur = cur->next;
		}

		printf("NULL\n");
	}

	bfs( g, 2);

	printf("\n");

	dfs( g, 2);

	return 0;
}