#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int v;
	struct node *n;
}node;

typedef struct graph{
	int s;
	struct node **ar;
}graph;

void goDp( graph *g, int vst[], int u){
	vst[u] = 1;
	printf(" %d ", u);

	node *cur = g->ar[u];

	while( cur != NULL){
		if( vst[cur->v] != 1)
			goDp(g, vst, cur->v);
		cur = cur->n;
	}
}

void dfs( graph *g, int u){
	if( g== NULL) return;
	
	int i, s;
	s = g->s;
	
	//Init visited
	int vst[s];
	for( i=0; i< s; i++)
		vst[i] = 0;
	
	goDp( g, vst, u);	
}

void bfs( graph *g, int u){
	if( g == NULL)	return;

	int s = g->s;
	int i, f, b;
	node *cur;
	
	//Init visited
	int vst[s];
	for( i =0; i< s; i++)
		vst[i] = 0;

	//Que
	int que[s*s];
	for( i =0; i< (s*s); i++)
		que[i] = 0;
	f = b = 0;

	//Enque and visited
	que[b++] = u;
	vst[u] = 1;

	while( f != b ){	//while queue is not empty
		//Deque and print
		i = que[f++];
		printf(" %d ", i);	
		
		cur = g->ar[i];
		while( cur != NULL){
			if( vst[cur->v] != 1){
				que[b++] = cur->v;
				vst[cur->v] = 1;
			}
			cur = cur->n;
		}
	}
}

void addEdge( graph *g, int u, int v){
	if( g==NULL)	return;
	else{
		node *cur;
		node *new = (node*)malloc(sizeof(node));
		new->v = v;
		new->n = NULL;
		if( g->ar[u] == NULL){
			g->ar[u] = new;
		} else{
			cur = g->ar[u];
			while( cur->n != NULL)
				cur = cur->n;
			cur->n = new;
		}
	}
}

void displayGraph(graph *g){
	node *cur;
	if( g== NULL) return;
	for( int i =0; i< g->s; i++){
		cur = g->ar[i];
		if( cur != NULL){
			printf("\nVertex %d -> ", i);
			while( cur != NULL){
				printf(" %d ", cur->v);
				cur = cur->n;
			}
		} 
	}
	printf("\n");
}

int main(){
	int u, v, n;
	graph *g;
	if( ( g = (graph*)malloc(sizeof(graph))) ==NULL)	
		printf("Error assigning memory to Graph");
	printf("\nNo. of vertices:\t");
	scanf("%d", &g->s);
	if( (g->ar = (node**)malloc(sizeof(node)*g->s)) == NULL)
		printf("Error assigning memory to Graph->array");

	printf("\nNo. of edges:\t");
	scanf("%d", &n);

	for( int i =0; i< n; i++){
		printf("\nEnter (u, v):\t");
		scanf("%d %d", &u, &v);	
		if( u < g->s)	addEdge(g, u, v);
		else	printf("\nInvalid Start-vertex");
	}
	
	displayGraph(g);

	printf("\nDFS traversal:\n");
	dfs(g, 2);

	printf("\nBFS traversal:\n");
	bfs(g, 2);

	return 1;
}