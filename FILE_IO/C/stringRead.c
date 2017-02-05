#include<stdio.h>
#include<stdlib.h>

int main(){

	FILE *rc = fopen("char.txt", "r");

	char s[100];
	// char *s = (char*) malloc(sizeof(char)*50);

	while(!feof(rc)){
		fscanf(rc, "%s", s);
		// fgets(s, 100, rc);

		printf("%s\n", s);
	}

	return 0;
}