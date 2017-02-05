#include<stdlib.h>
#include<stdio.h>

typedef struct node{

	int val;
	struct node *left;
	struct node *right;
}node;

void insertNode(node **rt, int k){

	node *nw = (node*) malloc( sizeof(node));
	nw->val = k;
	nw->left = nw->right = NULL;

	if( *rt == NULL)
		*rt = nw;
	else{

		if( k< (*rt)->val)
			insertNode(&(*rt)->left, k);
		if( k> (*rt)->val)
			insertNode(&(*rt)->right, k);
		if( k == (*rt)->val)
			printf("\nErr: Duplicate Key!");
	}

}

void insertNodes(node **rt){

	int ct, k, i;

	printf("\nNo. of nodes:\t");
	scanf("%d", &ct);

	for( i=0; i<ct; i++){

		printf("\nNode Val:\t");
		scanf("%d", &k);
		insertNode(&(*rt), k);
	}
}

int height(node *rt){

	int lh, rh;

	if(rt == NULL)
		return 0;
	else{

		lh = height(rt->left);
		rh = height(rt->right);

		if(	lh>rh)
			return lh+1;
		else
			return rh+1;
	}
}

void printLevel(node *rt, int l){

	if( rt==NULL)
		return;
	else {
		if( l==1 )
		printf(" %d ", rt->val);
		
		else if( l>1 ){

		printLevel(rt->left, l-1);
		printLevel(rt->right, l-1);
		}
	}
}

void levelOrder(node *rt){

	int ht, i;

	if( rt==NULL)
		return;
	else{

		ht = height(rt);
		printf("\nHeight of Tree is: %d\n", ht);

		for( i=1; i<=ht; i++){
			printf("\n");
			printLevel(rt, i);
		}
	}
}

void printLeft(node *rt, int l){

	if( rt==NULL)
		return;
	if( l==1 )
		printf(" %d ", rt->val);
	if( l>1 ){

		printLeft(rt->left, l-1);
		// printLevel(rt->right, l-1);
	}
}

void leftView(node *rt){

	int ht, i;

	if( rt==NULL)
		return;
	else{

		ht = height(rt);
		printf("\nHeight of Tree is: %d\n", ht);

		for( i=1; i<=ht; i++){
			printf("\n");
			printLeft(rt, i);
		}
	}	
}

void preOrder(node *rt){

	if(rt == NULL)
		return;
	else{
		
		printf(" %d ", rt->val);
		preOrder(rt->left);
		preOrder(rt->right);				
	}
}

void inOrder(node *rt){

	if(rt == NULL)
		return;	
	else {

		inOrder(rt->left);
		printf(" %d ", rt->val);
		inOrder(rt->right);
	}
}

void postOrder(node *rt){

	if(rt == NULL)
		return;	
	else {

		postOrder(rt->left);
		postOrder(rt->right);
		printf(" %d ", rt->val);
	}
}

int max(node *rt){

	int res, lres, rres;

	if( rt== NULL)
		return 0;
	else{

		res = rt->val;
		lres = max(rt->left);
		rres = max(rt->right);

		if(rres > res){
			res = rres;
		}
		if(lres > res){
			res = lres;
		}
		
		return res;
	}
}

// void deleteNode(node **rt){

// 	if( *rt==NULL)
// 		printf("\nErr: Empty Tree!");
// 	else{

// 		printf("\nEnter Key to remove:\t");
// 		scanf();
// 	}
// }

void printMenu(){

	printf("\n\n1. Insert Node");
	printf("\n2. Delete Node");
	printf("\n3. BFT: Level Order");
	printf("\n4. DFT");
	printf("\n5. Left View");
	printf("\n6. Max");
	printf("\n0. Quit");
	printf("\n\nEnter Op-code:\t");
}

int main(){

	int ch, res;
	node *rt = NULL;

	do{

		printMenu();
		scanf("%d", &ch);

		switch(ch){

			case 1:
				insertNodes(&rt);
			break;

			case 2:
				// deleteNode(&rt);
			break;

			case 3:
				levelOrder(rt);
			break;

			case 4:
				printf("\n Pre-order traversal :");
				preOrder(rt);
				printf("\n In-order traversal  :");
				inOrder(rt);
				printf("\n Post-order traversal:");
				postOrder(rt);
			break;

			case 5:
				leftView(rt);
			break;

			case 6:
				res = max(rt);
				printf("\n Max node is: %d", res);
			break;

			case 0:
				printf("\n\nExiting program");
			break;
		}

	} while( ch!=0);

	return 0;
}