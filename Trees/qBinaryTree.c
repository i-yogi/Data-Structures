#include<stdio.h>
#include<stdlib.h>

typedef struct bTree{
	int data;
	struct bTree *left;
	struct bTree *right;
}bTree;

// Binary Tree:

void insert(bTree **root, int val){

	bTree *new = NULL; 

	if(*root == NULL){
		*root = (bTree*)malloc(sizeof(bTree));
		(*root)->data = val;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else if(val < (*root)->data){
			insert(&(*root)->left, val);
	}
	else if(val > (*root)->data){
			insert(&(*root)->right, val);
	}
	else if(val == (*root)->data){
		printf("\n Error: Duplicate value!");
	}
}

// Breadth First Traversal: Level Order using queue

void enque(bTree **que, int *rear, bTree *node){
	que[*rear] = node;
	// printf("\n%d added to queue", node->data);
	(*rear)++;
}

bTree *deque(bTree **que, int *front){
	(*front)++;
	// printf("\n Returning %d", que[*front-1]->data);
	return que[*front-1];
}

void levelOrder(bTree *root){
	int front=0, rear=0;
	bTree *cur = root;

	bTree **que = (bTree**)malloc(sizeof(bTree)*100);
	// printf("\nQueue Create!");

	while(cur){
		printf("\t %d", cur->data);

		if(cur->left)	enque(que, &rear, cur->left);
		if(cur->right)	enque(que, &rear, cur->right);

		cur = deque(que, &front);
	}
}

int main(){
	int i=0, val=0, n=0;
	bTree *root = NULL;

	printf("\nEnter no of Elements to enter:");
	scanf("%d", &n);

	for(i=0; i<n; i++){
		printf("\nEnter int. value:");
		scanf("%d", &val);
		insert(&root, val);
	}

	// printf("\nRoot :%d", root->data);
	levelOrder(root);
	return 0;
}