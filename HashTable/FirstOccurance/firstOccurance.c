#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct item{
	char *name;
	int count;
}item;

typedef struct hashTable{
	item **list;
}ht;

int hash(char *name){
	int hashVal = 0;
	int c;

	while( (c = *name++))
		hashVal = ((hashVal<< 5) + hashVal) + c;

	// for( ; *name != '\0'; name++){
	// 	// printf("\n%c", *name);
	// 	hashVal = *name + (hashVal<<5)-hashVal;
	// }

	// printf("\nHash is %d", hashVal%200);
	return hashVal%200;
}

item *lookUp(ht *ht, char *name){
	int hashVal = hash(name);

	item *exists = ht->list[hashVal];

	if(exists == NULL)
		return NULL;
	else
		return exists;
}

void insertItem(ht *ht, char *name, FILE *w){

	int hashVal = hash(name);

	item *exists = lookUp(ht, name);

	if(exists == NULL){
		item *newItem = (item*)malloc(sizeof(item));
		newItem->name = name;
		newItem->count = 1;

		ht->list[hashVal] = newItem;
	}
	else{
		ht->list[hashVal]->count += 1;
		fprintf(w, "%s->%d\n", ht->list[hashVal]->name, ht->list[hashVal]->count);
	}
}

int main(){

	FILE *r = fopen("in2.txt", "r");
	FILE *w = fopen("ot.txt", "w");

	char* in = (char*)malloc(sizeof(char)*10000);

 	if(r == NULL)
		fprintf(w, "Error Opening File!\n");
	
	fscanf(r, "%[^\n]", in);
	
	// 'strtok' -> creates sub-string at given character
	char *inString = strtok(in, ",");
	
	ht *hasht = (ht*)malloc(sizeof(ht));
	hasht->list = (item**)malloc(sizeof(item)*200);

	while( inString != NULL){
		insertItem(hasht, inString, w);
		// fprintf(w, "%s\n", inString);t
		inString = strtok(NULL, ",");
	}

	return 0;
}