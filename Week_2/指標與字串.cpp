#include <stdio.h> 
#include <stdlib.h>

int lengthOfChar(char *ptr);
void displayCharWithIndex(char *ptr, int n);

int lengthOfChar(char *ptr){
	int sum = 0;
	char *tmp;
	tmp = ptr;
	while(*(tmp) != '\0'){
		tmp = tmp + 1;
		sum = sum + 1;
	}
	return sum;
}

void displayCharWithIndex(char *ptr, int n){
	int index = n;
	char *tmp = ptr;
	if(index-1 < 0){
		printf("§AÃaÃa\n");
		return;
	}
	puts(tmp+index-1);
}

int main(void){
	char word[20];
	int index;
	gets(word);
	printf("Start with:");
	scanf(" %d", &index);
	int result = lengthOfChar(word);
	printf("%d\n", result);
	displayCharWithIndex(word, index);
	system("pause");
	return 0;
}
