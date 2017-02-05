#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

void insert(node **root, int val){

	if(*root == NULL){
		*root = (node*)malloc(sizeof(node));
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

void preorder(node *root){
	if(root == NULL) return;
	
	else{
		printf("  %d  ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(node *root){
	if(root == NULL) return;
	
	else{
		inorder(root->left);
		printf("  %d  ", root->data);
		inorder(root->right);
	}
}

void postorder(node *root){
	if(root == NULL) return;
	
	else{
		postorder(root->left);
		postorder(root->right);
		printf("  %d  ", root->data);
	}
}

void printLevel(node *root, int lev){
	if(root == NULL) return;
	else if(lev == 1) printf("  %d  ", root->data);
	else if(lev > 1){
		printLevel(root->left, lev-1);
		printLevel(root->right, lev-1);
	}
}

int height(node *root){
	if(root == NULL) return 0;
	else {
		int lh = height(root->left);
		int rh = height(root->right);

		if (lh >= rh) return lh+1;
		else return rh+1;
	}

}

void levelOrder(node *root){
	int h =0;
	int i=0;

	if(root == NULL) return;
	h = height(root); 
	printf("\nHeight of the Tree is %d\n", h);
	for(i=1; i<=h; i++){
		printf("\n");
		printLevel(root, i);
	}
}

void rLevelOrder(node *root){
	int h =0;
	int i=0;

	if(root == NULL) return;
	h = height(root); 
	printf("\nHeight of the Tree is %d\n", h);
	for(i=h; i>=1; i--){
		printf("\n");
		printLevel(root, i);
	}
}

//	Delete the Node from tree

node *minNode(node *root){
	while(root->left != NULL)
		root = root->left;
	return root;
}

void deleteNode(node **root, int key){
	// node *temp = *root;
	node *min = NULL;

	if(key < (*root)->data){
		printf("\ngoing left");
		deleteNode(&(*root)->left, key);
	}
	else if(key > (*root)->data){
		printf("\ngoing right");
		deleteNode(&(*root)->right, key);
	}
	else{
//If current node has only one child/ no child
		if((*root)->left == NULL){
			printf("\n@ Leaf node... Right child exists");
			(*root) = (*root)->right;
			free(*root);
		}
		else if((*root)->right == NULL){
			printf("\n@ Leaf node... Left child exists");
			(*root) = (*root)->left;
			free(*root);
		}

//If current node is root node with two children
		else{
			printf("\n@ Root node... Both child exists");
			min = (node*)malloc(sizeof(node));
			min = minNode((*root)->right);

			(*root)->data = min->data;

			deleteNode(&(*root)->right, min->data);
		}
	}
		
}

//Display Menu

void printMenu(){
	printf("\n ******** Binary Search Tree ********");
	printf("\n1. Insert Node");
	printf("\n2. Preorder (Depth First Traversal)");
	printf("\n3. Inorder (Depth First Traversal)");
	printf("\n4. Postorder (Depth First Traversal)");
	printf("\n5. Level Order (Breadth First Traversal)");
	printf("\n6. Reverse Level Order (Breadth First Traversal)");
	printf("\n7. Delete Node");
	printf("\n8. Exit");
	printf("\n\nEnter Choice:");
}

int main(){
	int ch=0, i=0, n=0, val=0, key=0;
	node *root = NULL;

	do{
		printMenu();
		scanf("%d", &ch);

		switch(ch){
			
			case 1:
				printf("\nEnter no of Elements to enter:");
				scanf("%d", &n);

				for(i=0; i<n; i++){
					printf("\nEnter int. value:");
					scanf("%d", &val);

					insert(&root, val);
				}
				printf("\n******** Tree Created (BFS)********");
				levelOrder(root);
			break;

			case 2:
				printf("\n ******** Pre-Order Tree Traversal (DFS)******** \n");
				preorder(root);
			break;
			
			case 3:
				printf("\n ******** In-Order Tree Traversal (DFS)******** \n");
				inorder(root);
			break;

			case 4:
				printf("\n ******** Post-Order Tree Traversal (DFS)******** \n");
				postorder(root);
			break;

			case 5:
				printf("\n ******** Level Order Tree Traversal (BFS)******** \n");
				levelOrder(root);
			break;
			
			case 6:
				printf("\n ******** Reversed Level Order Tree Traversal (BFS)******** \n");
				rLevelOrder(root);
			break;

			case 7:
				printf("\n ******** Binary Search Tree ********");
				levelOrder(root);
				printf("\n Enter value of node to delete:\t");
				scanf("%d", &key);
				deleteNode(&root, key);
				printf("\n ******** Binary Search Tree ********");
				levelOrder(root);
			break;

			case 8:
				printf("\nExiting Program...\n");
			break;

			default:
				printf("\nWrong Choice!\n");
			break;
		}
	}while(ch != 8);

	return 0;
}