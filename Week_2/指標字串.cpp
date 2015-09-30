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
	puts(tmp+index);
}

int main(void){
	char word[20];
	gets(word);
	int result = lengthOfChar(word);
	printf("%d\n", result);
	displayCharWithIndex(word, 5);
	system("pause");
	return 0;
}
