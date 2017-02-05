#include<stdio.h>

int main(){

	FILE *ri = fopen("int.txt", "r");

	int c[5], i=-1;

	while(!feof(ri)){
		i++;
		fscanf(ri, "%d", &c[i]);
	}

	for(i=0; i<4; i++)
		printf("%d\t", c[i]);

	return 0;
}