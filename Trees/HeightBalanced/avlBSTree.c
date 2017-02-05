#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int key;
	int height;
	struct node *left;
	struct node *right;
}node;

void printMenu(){
	printf("\n****** AVL Operations ******");

	printf("\n1. Insert");
	printf("\n2. Display (Level Order)");
	printf("\n5. Exit");

	printf("\n****** Enter Choice: ");
}

int max(int a, int b){
	return( a>b ? a : b);
}

int getHeight(node *node){
	if(node == NULL) return 0;
	else return(node->height);
}

int setHeight(node *node){
	if(node == NULL)
		return 0;
	else return(max(getHeight(node->left), getHeight(node->right)) +1);
}

//Breadth First Traversal: Level Order
void printLevel(node *tree, int lev){

	if(tree == NULL){
		// printf("\t null");
		return;
	}
	else if(lev == 1)
			printf("\t%d, %d", tree->key, tree->height);
	else {
			printLevel(tree->left, lev-1);
			printLevel(tree->right, lev-1);
		}
}

void levelOrder(node *root){

	int i = 0;

	if(root == NULL){
		printf("\nError: Root is NULL!");
		return;
	}
	else{

		printf("\nDebug: Root.height -> %d", root->height);

		for(i=1; i<=(root->height); i++){
			printf("\n");
			printLevel(root, i);
		}
	}
}

node* setNewNode(node *new, int val){

	new = (node*)malloc(sizeof(node));
	new->key = val;
	new->left = NULL;
	new->right = NULL;
	new->height = setHeight(new);

	return new;
}

int getBalance(node* parentNode){

	if(parentNode == NULL) return 0;
	else return(getHeight(parentNode->left) - getHeight(parentNode->right));
}

node* rotateRight(node *y){

	node *x    = y->left;
	node *temp = x->right;

	x->right = y;
	y->left = temp;

	x->height = setHeight(x);
	y->height = setHeight(y);

	return x;
}

node* rotateLeft(node *x){

	node *y    = x->right;
	node *temp = y->left;

	y->left = x;
	x->right = temp;
	
	x->height = setHeight(x);
	y->height = setHeight(y);

	return y;
}

node* insertNode(node *root, int val){

//null root -> create new tree
	if(root == NULL){
		root = setNewNode(root, val);
	} else if(val == root->key){

			printf("\nError: Duplicate value!");
	} else {

		// BST insertion
		if(val < root->key){
			root->left = insertNode(root->left, val);
		}
		else if(val > root->key){
			root->right = insertNode(root->right, val);
		}

		//Update Heights of Nodes
		root->height = setHeight(root);
	}

	//Check AVL balance
	int balance = getBalance(root);
	// printf("\n Balance at current node (%d)-> %d", root->key, balance);

	//Left->Left Case
	if(balance > 1 && (val < root->left->key)){
		printf("\nDebug: Left->Left Case");
		return rotateRight(root);
	}

	//Left->Right Case
	if(balance > 1 && (val > root->left->key)){
		printf("\nDebug: Left->Right Case");
		root->left = rotateLeft(root->left);
		return rotateRight(root);
	}

	//Right->Right Case
	if(balance < -1 && (val > root->right->key)){
		printf("\nDebug: Right->Right Case");
		return rotateLeft(root);
	}

	//Right->Left Case
	if(balance < -1 && (val < root->right->key)){
		printf("\nDebug: Right->Left Case");
		root->right = rotateRight(root->right);
		return rotateLeft(root);
	}

	//Unchanged
	return root;
}


//Main ->
int main()
{
	int ch = 0, val = 0;
	node *root = NULL;

	do{
		printMenu();
		scanf("%d", &ch);

		switch(ch){

			case 1: 
				printf("\nEnter node value: ");
				scanf("%d", &val);
				root = insertNode(root, val);
				break;

			case 2:
				levelOrder(root);
				break;

			case 5:
				printf("\nQuiting Program...\n");
				break;
		}
	}while(ch != 5);

	return 0;
}