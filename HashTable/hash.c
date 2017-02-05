#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct item{
	char *string;
	int count;
	struct item *next;
}item;

typedef struct hashTable{
	int size;
	item **list;
}ht;

unsigned int hash(char *string, ht *ht){
	unsigned int hashVal = 0;

	for(; *string != '\0'; string++){
		hashVal = *string + (hashVal<<5) + hashVal;
	}

	hashVal = hashVal % ht->size;

	return hashVal;
}

item *lookUP(ht *ht, char *string){
	int hashVal = hash(string, ht);

	item *exits = ht->list[hashVal];

	if(exits==NULL)
		return NULL;
	else return exits;
}

void addString(ht *ht, char *string){

	unsigned int hashVal = hash(string, ht);
	printf("\nHash is %u", hashVal);

	item *newItem = (item*)malloc(sizeof(item));
	newItem->string = string;
	newItem->next = NULL;

	item *cur = lookUP(ht, string);

	if(cur != NULL){
		cur->count += 1;
	}
	else{
		newItem->count = 1;
		ht->list[hashVal] = newItem;
	}
}

int main(){

	int i, s;
	char *in = (char*)malloc(sizeof(char)*10000); 
	char *string;
	FILE *f = fopen("in.txt", "r");

	fscanf(f, "%[^\n]", in);
	printf("\nFile contains :%s", in);

	string = strtok(in, ",");

	printf("\nEnter Size of HashTable:");
	scanf("%d", &s);

	ht *hasht = (ht*)malloc(sizeof(ht));
	hasht->size = s;
	hasht->list = (item**)malloc(sizeof(item)*s);

	while(string != NULL){
		addString(hasht, string);
		string = strtok(NULL, ",");

		// addString(hasht, string);
		// string = strtok(NULL, ",");

		// addString(hasht, string);
		// string = strtok(NULL, ",");
	}

	item *cur = hasht->list[0];

	printf("\nHash Table Contains: ");
	for(i=0; i<s; i++){
		cur = hasht->list[i];		
		if(cur != NULL){
			printf("\n#%d %s count->%d", i, cur->string, cur->count);
		}
	}

	return 0;
}